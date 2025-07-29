#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

//BaseShader

class FCustomFlareShader : public FGlobalShader
{
public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}

	//ModifyCompilationEnvironment 动态配置着色器编译环境
	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	}

	FCustomFlareShader() = default;
	FCustomFlareShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
	}
};

//定义一个FFlarePassParameters结构体，用于传递给渲染图形构建器
//这个结构体包含了输入纹理，测试颜色和渲染目标绑定插槽等信息
BEGIN_SHADER_PARAMETER_STRUCT(FFlarePassParameters, )
	SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D, InputTexture) // 输入纹理
	SHADER_PARAMETER(FVector4f, TestColor) // 测试颜色
	RENDER_TARGET_BINDING_SLOTS() // 渲染目标绑定插槽
END_SHADER_PARAMETER_STRUCT()

//Simple VS
class FCustomFlareVS : public FCustomFlareShader
{
	DECLARE_GLOBAL_SHADER(FCustomFlareVS);
	SHADER_USE_PARAMETER_STRUCT(FCustomFlareVS, FCustomFlareShader);//在着色器中声明参数需要用这个宏

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )//声明完上面的宏之后，下面必须声明一个参数结构体
		SHADER_PARAMETER_STRUCT_INCLUDE(FFlarePassParameters, Pass)
		SHADER_PARAMETER(float, FlareBokehSize)
		SHADER_PARAMETER(float, FlareThreshold)
		SHADER_PARAMETER(float, PixelSegment)
		SHADER_PARAMETER(FVector2f, UVRatio)
		SHADER_PARAMETER(FVector2f, TextureSize)
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, ViewUniformBuffer)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
	END_SHADER_PARAMETER_STRUCT()
};

//Simple PS
class FCustomFlarePS : public FCustomFlareShader
{
	DECLARE_GLOBAL_SHADER(FCustomFlarePS);
	SHADER_USE_PARAMETER_STRUCT(FCustomFlarePS, FCustomFlareShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT_INCLUDE(FFlarePassParameters, Pass)
		SHADER_PARAMETER_TEXTURE(Texture2D, InputBokehTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputBokehSampler)
		//RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()
};