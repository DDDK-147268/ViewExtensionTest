// Copyright Epic Games, Inc. All Rights Reserved.

#include "GBufferTestEditorModule.h"
#include "GBufferTest.h"
#include "Interfaces/IPluginManager.h"
#include "IPlacementModeModule.h"

#define LOCTEXT_NAMESPACE "FGBufferTestEditorModule"

void FGBufferTestEditorModule::StartupModule()
{
	//在放置Actor面板中新增一个CustomFlare类
	RegisterToPlacementMode();
}

void FGBufferTestEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FGBufferTestEditorModule::RegisterToPlacementMode()
{
	//创建一个新的放置类型分类
	FPlacementCategoryInfo FlarePlacementInfo(
		FText::FromString("DDDKPlugins"),//分类显示名
		FName("DDDKPlugins"),//分类唯一标识符
		"DDDKPlugins",//未知
		41//排序
	);
	//把这个分类注册到放置模式中
	IPlacementModeModule::Get().RegisterPlacementCategory(FlarePlacementInfo);
	//创建一个可放置物，注册到对应放置类别中
	IPlacementModeModule::Get().RegisterPlaceableItem(FlarePlacementInfo.UniqueHandle,
		MakeShared<FPlaceableItem>(
			*AGBufferTest::StaticClass(),
			FAssetData(AGBufferTest::StaticClass()),
			NAME_None,
			NAME_None,
			TOptional<FLinearColor>(),
			1,
			FText::FromString("CustomFlare")
		)
	);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGBufferTestEditorModule, GBufferTest)