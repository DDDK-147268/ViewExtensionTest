// Copyright Epic Games, Inc. All Rights Reserved.

#include "GBufferTestModule.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FGBufferTestModule"

void FGBufferTestModule::StartupModule()
{
	//获取插件目录路径，并添加着色器源目录映射。
	FString PluginShaderPath = IPluginManager::Get().FindPlugin(TEXT("GBufferTest"))->GetBaseDir() / TEXT("Shaders");
	AddShaderSourceDirectoryMapping(TEXT("/GBufferTest"), PluginShaderPath);
}

void FGBufferTestModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGBufferTestModule, GBufferTest)