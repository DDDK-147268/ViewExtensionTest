#pragma once
#include "GBufferTestSceneViewExtension.h"

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"

#include "GBufferTest.generated.h"

/*
-------------------------------------------------------------------------------------------------------------------------------------------------
创建一个subsystem，用于管理 GBufferTest 的生命周期和状态
*/
UCLASS()
class UGBufferTestSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()
public:
	UGBufferTestSubsystem() {}
	// Subsystem Init/Deinit
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;// Initialize is called when the subsystem is created
	virtual void Deinitialize() override;// Deinitialize is called when the subsystem is destroyed


public:
	TSharedPtr<FGBufferTestSceneViewExtension, ESPMode::ThreadSafe> GBufferTestSceneViewExtensionPtr;
};






