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
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
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
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
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

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGBufferTestSubsystem, UGBufferTestSubsystem::StaticClass, TEXT("UGBufferTestSubsystem"), &Z_Registration_Info_UClass_UGBufferTestSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGBufferTestSubsystem), 595037664U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_3940461292(TEXT("/Script/GBufferTest"),
	Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
