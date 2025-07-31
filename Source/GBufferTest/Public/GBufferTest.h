#pragma once
#include "GBufferTestSceneViewExtension.h"

#include "CoreMinimal.h"
#include "RenderCore.h"
#include "Subsystems/EngineSubsystem.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"

#include "GBufferTest.generated.h"

/*
-------------------------------------------------------------------------------------------------------------------------------------------------
创建一个subsystem，用于管理 GBufferTest 的生命周期和状态
*/
UCLASS()
class UGBufferTestSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	UGBufferTestSubsystem() {}
	// Subsystem Init/Deinit
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;// Initialize is called when the subsystem is created
	virtual void Deinitialize() override;// Deinitialize is called when the subsystem is destroyed


public:
	TSharedPtr<FGBufferTestSceneViewExtension, ESPMode::ThreadSafe> GBufferTestSceneViewExtensionPtr;

	friend class FGBufferTestSceneViewExtension;
private:
	// 一个数组用于存储所有的 GBufferTest 实例，FGBufferTestSceneViewExtension会根据这个数组来渲染Pass
	TWeakObjectPtr<AGBufferTest> GBufferTest;
public:
	void UpdateGBufferTest(AGBufferTest* InGBufferTest)
	{
		if (InGBufferTest)
		{
			GBufferTest = InGBufferTest;
		}
		else
		{
			GBufferTest.Reset();
		}
	}
};


UCLASS(Blueprintable, placeable, HideCategories = (Actor, HLOD, Collision, Replication, Cooking, Input, DataLayers, Physics, Streaming, WorldPartition))
class GBUFFERTEST_API AGBufferTest : public AActor
{
	GENERATED_UCLASS_BODY()
public:
	//~AGBufferTest() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flare", meta = (UIMin = 2, UIMax = 10, DisplayName = "Segment"))
	int Segment;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flare", meta = (UIMin = 0.0, UIMax = 30.0, DisplayName = "Size"))
	float Size;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flare", meta = (UIMin = 0.0, UIMax = 10.0, DisplayName = "Threshold"))
	float Threshold;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flare", meta = (DisplayName = "FlareShap"))
	TObjectPtr<class UTexture> BokehTextureRHI;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Flare", meta = (DisplayName = "Enable"))
	bool Active;
private:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};



