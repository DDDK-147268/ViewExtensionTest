#include "GBufferTestSceneViewExtension.h"

#include "CoreMinimal.h"
#include "RenderCore.h"
#include "Runtime/Renderer/Private/SceneRendering.h"
#include "SceneView.h"
#include "RenderGraphUtils.h"
#include "PixelShaderUtils.h"
#include "PostProcess/PostProcessInputs.h"

#include "FlareShader.h"

// FGBufferTestSceneViewExtension的实现
void FGBufferTestSceneViewExtension::PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessingInputs& Inputs)
{
	ERHIFeatureLevel::Type FeatureLevel = View.GetFeatureLevel();

	//CVarPixelSegment 是控制台变量，定义在RenderCore中，用于控制渲染线程中像素分段的数量，这里会返回默认值 8
	const int PixelSegment = 8;

	//FIntPoint 是一个用于表示二维整数点的结构体，通常用于表示纹理或渲染目标的大小
	//Extent 返回的是纹理在内存上的实际大小，比如 1920x1080 可能会返回为 1920x1088
	FIntPoint TextureSize = FIntPoint(Inputs.ViewFamilyTexture->Desc.Extent.X, Inputs.ViewFamilyTexture->Desc.Extent.Y);
	FIntPoint ViewSize = FIntPoint(Inputs.SceneTextures->GetContents()->SceneColorTexture->Desc.Extent.X, Inputs.SceneTextures->GetContents()->SceneColorTexture->Desc.Extent.Y);

	// 创建一个临时输出纹理，使用SceneColorTexture的描述
	FRDGTextureRef OutputTexture = GraphBuilder.CreateTexture(Inputs.SceneTextures->GetContents()->SceneColorTexture->Desc, TEXT("TempOutTexure"));

	// Add a pass to copy the scene color texture to the output texture
	AddCopyTexturePass(GraphBuilder, Inputs.SceneTextures->GetContents()->SceneColorTexture, OutputTexture);

	//动态申请一个FFlarePassParameters类型的参数结构体，用于传递给渲染图形构建器
	//FFlarePassParameters定义在FlareShader.h中，存储了SRV，测试颜色和渲染目标绑定插槽
	FFlarePassParameters* PassParameters = GraphBuilder.AllocParameters<FFlarePassParameters>();
	//AddPass要求InputTexture是一个SRV类型的纹理，所以这里使用CreateSRV将SceneColorTexture转换为SRV
	PassParameters->InputTexture = GraphBuilder.CreateSRV(Inputs.SceneTextures->GetContents()->SceneColorTexture);
	PassParameters->TestColor = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f); // 设置测试颜色为红色
	// 将输出纹理绑定到渲染目标，
	// ERenderTargetLoadAction是一个枚举类型，用于指定渲染目标的加载操作
	// ERenderTargetLoadAction::ELoad表示加载渲染目标的内容
	PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputTexture, ERenderTargetLoadAction::ELoad);

	FVector2f UVRatio = FVector2f(TextureSize.X / (float)ViewSize.X, TextureSize.Y / (float)ViewSize.Y);

	//设置顶点着色器的引用和参数
	TShaderMapRef<FCustomFlareVS> VertexShader(GetGlobalShaderMap(FeatureLevel));
	FCustomFlareVS::FParameters VSPassParameters;
	VSPassParameters.Pass = *PassParameters;
	VSPassParameters.PixelSegment = (float)PixelSegment;
	VSPassParameters.TextureSize = FVector2f(TextureSize.X, TextureSize.Y);
	VSPassParameters.UVRatio = UVRatio;
	VSPassParameters.InputSampler = TStaticSamplerState<SF_Bilinear>::GetRHI();
	VSPassParameters.ViewUniformBuffer = GetShaderBinding(View.ViewUniformBuffer);	//获取ViewUniformBuffer

	//Use Engine Lensflare Parameters 
	VSPassParameters.FlareBokehSize = View.FinalPostProcessSettings.LensFlareBokehSize;
	VSPassParameters.FlareThreshold = View.FinalPostProcessSettings.LensFlareThreshold;

	FRHITexture* BokehTextureRHI = GWhiteTexture->TextureRHI;//给一张白色纹理作为默认的Bokeh纹理
	FFinalPostProcessSettings Settings = View.FinalPostProcessSettings;

	//如果设置了LensFlareBokehShape，则获取其资源并设置BokehTextureRHI
	if (Settings.LensFlareBokehShape)
	{
		FTextureResource* BokehTextureResource = Settings.LensFlareBokehShape->GetResource();

		if (BokehTextureResource && BokehTextureResource->TextureRHI)
		{
			BokehTextureRHI = BokehTextureResource->TextureRHI;
		}
	}

	//设置像素着色器的引用和参数
	TShaderMapRef<FCustomFlarePS> PixelShader(GetGlobalShaderMap(FeatureLevel));
	FCustomFlarePS::FParameters PSPassParameters;
	PSPassParameters.Pass = *PassParameters;
	PSPassParameters.InputBokehTexture = BokehTextureRHI;
	PSPassParameters.InputBokehSampler = TStaticSamplerState<SF_Bilinear>::GetRHI();

	// 创建一个渲染状态，设置为添加混合
	FRHIBlendState* AdditiveBlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_One>::GetRHI();

	//计算每个实例的大小
	const int32 GLensFlareQuadsPerInstance = PixelSegment * PixelSegment;//PixelSegment * PixelSegment;
	const uint32 InstanceSize = FMath::DivideAndRoundUp(TextureSize.X * TextureSize.Y, GLensFlareQuadsPerInstance);//除后余向上取整，计算实例化的大小

	//添加一个Pass，在SceneColorTexture上渲染LensFlare，输出到OutputTexture上
	GraphBuilder.AddPass(
		RDG_EVENT_NAME("CustomFlare :(%i)", InstanceSize),
		PassParameters,
		ERDGPassFlags::Raster | ERDGPassFlags::NeverCull,
		[VertexShader, PixelShader, VSPassParameters, PSPassParameters, AdditiveBlendState, TextureSize, PixelSegment]
		(FRHICommandList& RHICmdList)
		{
			//视口设置
			RHICmdList.SetViewport(
				0.0f,
				0.0f,
				0.0f,
				TextureSize.X,
				TextureSize.Y,
				1.0f);

			//应用管线状态
			FGraphicsPipelineStateInitializer GraphicsPSOInit;//创建一个渲染管线状态初始化器
			RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);//应用RHICmdList中缓存的渲染目标到GraphicsPSOInit初始化器，
			//这里缓存的渲染目标是在执行AddPass时，由GraphBuilder自动从PassParameters中找到RT设置的
			GraphicsPSOInit.BlendState = AdditiveBlendState;//设置混合状态，这里的AdditiveBlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_One>::GetRHI();
			GraphicsPSOInit.RasterizerState = TStaticRasterizerState<FM_Solid>::GetRHI();//设置光栅化状态
			GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();//深度模板
			GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GEmptyVertexDeclaration.VertexDeclarationRHI;//设置顶点声明
			//这里的GEmptyVertexDeclaration是一个特殊的顶点声明，表示无需从顶点缓冲区读取任何顶点属性数据。
			//主要用于全屏后处理等特定Pass中。
			// 使用这个声明之后，VS的Input应为
			// in uint InstanceId : SV_InstanceID,
			// in uint VertexId : SV_VertexID,
			// 
			GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();//设置顶点着色器
			GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();//设置像素着色器
			GraphicsPSOInit.PrimitiveType = PT_TriangleList;//设置图元为三角形列表，每三个顶点组成一个独立的三角形
			SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);//应用初始化器到RHICmdList

			//设置着色器参数
			SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), VSPassParameters);
			SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PSPassParameters);

			//Set Vertex Stream
			RHICmdList.SetStreamSource(0, nullptr, 0);//这里示例是一个全屏后处理Pass，所以无需顶点缓冲区

			//计算实例大小
			const int32 GLensFlareQuadsPerInstance = PixelSegment * PixelSegment;//PixelSegment * PixelSegment;
			//绘制命令，每两个三角形组成一个实例，根据纹理大小和PixelSegment大小计算实例数量，使其能够覆盖整个纹理
			//RHICmdList.DrawPrimitive(0, 2, 4);// FMath::DivideAndRoundUp(TextureSize.X * TextureSize.Y, GLensFlareQuadsPerInstance));

			RHICmdList.DrawPrimitive(0, 2, FMath::DivideAndRoundUp(TextureSize.X * TextureSize.Y, GLensFlareQuadsPerInstance));
		});

	FRHICopyTextureInfo CopyTextureInfo;//这里其实是全纹理拷贝，所以其实不用设置
	CopyTextureInfo.NumMips = 1;
	CopyTextureInfo.Size = Inputs.SceneTextures->GetContents()->SceneColorTexture->Desc.GetSize();
	//将OutputTexture的内容复制到SceneColorTexture上
	AddCopyTexturePass(GraphBuilder, OutputTexture, Inputs.SceneTextures->GetContents()->SceneColorTexture, CopyTextureInfo);
}

