// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GBufferTest/Public/GBufferTest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGBufferTest() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UTexture_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
GBUFFERTEST_API UClass* Z_Construct_UClass_AGBufferTest();
GBUFFERTEST_API UClass* Z_Construct_UClass_AGBufferTest_NoRegister();
GBUFFERTEST_API UClass* Z_Construct_UClass_UGBufferTestSubsystem();
GBUFFERTEST_API UClass* Z_Construct_UClass_UGBufferTestSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_GBufferTest();
// End Cross Module References

// Begin Class UGBufferTestSubsystem
void UGBufferTestSubsystem::StaticRegisterNativesUGBufferTestSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGBufferTestSubsystem);
UClass* Z_Construct_UClass_UGBufferTestSubsystem_NoRegister()
{
	return UGBufferTestSubsystem::StaticClass();
}
struct Z_Construct_UClass_UGBufferTestSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n-------------------------------------------------------------------------------------------------------------------------------------------------\n\xe5\x88\x9b\xe5\xbb\xba\xe4\xb8\x80\xe4\xb8\xaasubsystem\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xae\xa1\xe7\x90\x86 GBufferTest \xe7\x9a\x84\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe7\x8a\xb6\xe6\x80\x81\n*/" },
#endif
		{ "IncludePath", "GBufferTest.h" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x9b\xe5\xbb\xba\xe4\xb8\x80\xe4\xb8\xaasubsystem\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xae\xa1\xe7\x90\x86 GBufferTest \xe7\x9a\x84\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe7\x8a\xb6\xe6\x80\x81" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGBufferTestSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGBufferTestSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GBufferTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGBufferTestSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGBufferTestSubsystem_Statics::ClassParams = {
	&UGBufferTestSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGBufferTestSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGBufferTestSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGBufferTestSubsystem()
{
	if (!Z_Registration_Info_UClass_UGBufferTestSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGBufferTestSubsystem.OuterSingleton, Z_Construct_UClass_UGBufferTestSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGBufferTestSubsystem.OuterSingleton;
}
template<> GBUFFERTEST_API UClass* StaticClass<UGBufferTestSubsystem>()
{
	return UGBufferTestSubsystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGBufferTestSubsystem);
UGBufferTestSubsystem::~UGBufferTestSubsystem() {}
// End Class UGBufferTestSubsystem

// Begin Class AGBufferTest
void AGBufferTest::StaticRegisterNativesAGBufferTest()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGBufferTest);
UClass* Z_Construct_UClass_AGBufferTest_NoRegister()
{
	return AGBufferTest::StaticClass();
}
struct Z_Construct_UClass_AGBufferTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Actor HLOD Collision Replication Cooking Input DataLayers Physics Streaming WorldPartition" },
		{ "IncludePath", "GBufferTest.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Segment_MetaData[] = {
		{ "Category", "Flare" },
		{ "DisplayName", "Segment" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
		{ "UIMax", "10" },
		{ "UIMin", "2" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "Flare" },
		{ "DisplayName", "Size" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
		{ "UIMax", "30.000000" },
		{ "UIMin", "0.000000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Threshold_MetaData[] = {
		{ "Category", "Flare" },
		{ "DisplayName", "Threshold" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
		{ "UIMax", "10.000000" },
		{ "UIMin", "0.000000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BokehTextureRHI_MetaData[] = {
		{ "Category", "Flare" },
		{ "DisplayName", "FlareShap" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Active_MetaData[] = {
		{ "Category", "Flare" },
		{ "DisplayName", "Enable" },
		{ "ModuleRelativePath", "Public/GBufferTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Segment;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Size;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Threshold;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BokehTextureRHI;
	static void NewProp_Active_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Active;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGBufferTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGBufferTest_Statics::NewProp_Segment = { "Segment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGBufferTest, Segment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Segment_MetaData), NewProp_Segment_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGBufferTest_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGBufferTest, Size), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGBufferTest_Statics::NewProp_Threshold = { "Threshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGBufferTest, Threshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Threshold_MetaData), NewProp_Threshold_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGBufferTest_Statics::NewProp_BokehTextureRHI = { "BokehTextureRHI", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGBufferTest, BokehTextureRHI), Z_Construct_UClass_UTexture_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BokehTextureRHI_MetaData), NewProp_BokehTextureRHI_MetaData) };
void Z_Construct_UClass_AGBufferTest_Statics::NewProp_Active_SetBit(void* Obj)
{
	((AGBufferTest*)Obj)->Active = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGBufferTest_Statics::NewProp_Active = { "Active", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGBufferTest), &Z_Construct_UClass_AGBufferTest_Statics::NewProp_Active_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Active_MetaData), NewProp_Active_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGBufferTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGBufferTest_Statics::NewProp_Segment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGBufferTest_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGBufferTest_Statics::NewProp_Threshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGBufferTest_Statics::NewProp_BokehTextureRHI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGBufferTest_Statics::NewProp_Active,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGBufferTest_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGBufferTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_GBufferTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGBufferTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGBufferTest_Statics::ClassParams = {
	&AGBufferTest::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGBufferTest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGBufferTest_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGBufferTest_Statics::Class_MetaDataParams), Z_Construct_UClass_AGBufferTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGBufferTest()
{
	if (!Z_Registration_Info_UClass_AGBufferTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGBufferTest.OuterSingleton, Z_Construct_UClass_AGBufferTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGBufferTest.OuterSingleton;
}
template<> GBUFFERTEST_API UClass* StaticClass<AGBufferTest>()
{
	return AGBufferTest::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGBufferTest);
AGBufferTest::~AGBufferTest() {}
// End Class AGBufferTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGBufferTestSubsystem, UGBufferTestSubsystem::StaticClass, TEXT("UGBufferTestSubsystem"), &Z_Registration_Info_UClass_UGBufferTestSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGBufferTestSubsystem), 2861754253U) },
		{ Z_Construct_UClass_AGBufferTest, AGBufferTest::StaticClass, TEXT("AGBufferTest"), &Z_Registration_Info_UClass_AGBufferTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGBufferTest), 2709785381U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_2476124496(TEXT("/Script/GBufferTest"),
	Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
