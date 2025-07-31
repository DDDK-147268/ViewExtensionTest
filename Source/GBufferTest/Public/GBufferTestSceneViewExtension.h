#pragma once
#include "CoreMinimal.h"
#include "ScreenPass.h"

#include "SceneViewExtension.h"

class UGBufferTestSubsystem;
/*
------------------------------------------------------------------------------------------------------------------------------------------------
创建一个SceneViewExtension，用于在渲染过程中添加自定义的GBuffer处理逻辑
这个类继承自FSceneViewExtensionBase，提供了必要的接口来处理视图扩展
*/
class FGBufferTestSceneViewExtension : public FSceneViewExtensionBase
{
public:
	FGBufferTestSceneViewExtension(const FAutoRegister& AutoRegister, UGBufferTestSubsystem* InWorldSubsystem)
		: FSceneViewExtensionBase(AutoRegister), WorldSubsystem(InWorldSubsystem)
	{
	}

private:
	//~ Begin FSceneViewExtensionBase Interface
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {};
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {};
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {};

	//这个函数用于添加自定义pass，在这里实现 AddPass
	virtual void PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessingInputs& Inputs) override;
	//~ End FSceneViewExtensionBase Interface

	//新增的函数，用于在BasePass结束后回调，可以修改GBuffer的内容
	//virtual void PostRenderBasePassDeferred_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView, const FRenderTargetBindingSlots& RenderTargets, TRDGUniformBufferRef<FSceneTextureUniformParameters> SceneTextures) override;

public:
	//void Invalidate();

	//void ShouldEnableViewExtension();

private:
	UGBufferTestSubsystem* WorldSubsystem;
};
