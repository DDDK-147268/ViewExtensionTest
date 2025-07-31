// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GBufferTest.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GBUFFERTEST_GBufferTest_generated_h
#error "GBufferTest.generated.h already included, missing '#pragma once' in GBufferTest.h"
#endif
#define GBUFFERTEST_GBufferTest_generated_h

#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGBufferTestSubsystem(); \
	friend struct Z_Construct_UClass_UGBufferTestSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGBufferTestSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GBufferTest"), NO_API) \
	DECLARE_SERIALIZER(UGBufferTestSubsystem)


#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UGBufferTestSubsystem(UGBufferTestSubsystem&&); \
	UGBufferTestSubsystem(const UGBufferTestSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGBufferTestSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGBufferTestSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGBufferTestSubsystem) \
	NO_API virtual ~UGBufferTestSubsystem();


#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_17_PROLOG
#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_20_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GBUFFERTEST_API UClass* StaticClass<class UGBufferTestSubsystem>();

#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_53_INCLASS \
private: \
	static void StaticRegisterNativesAGBufferTest(); \
	friend struct Z_Construct_UClass_AGBufferTest_Statics; \
public: \
	DECLARE_CLASS(AGBufferTest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GBufferTest"), NO_API) \
	DECLARE_SERIALIZER(AGBufferTest)


#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_53_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGBufferTest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGBufferTest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGBufferTest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGBufferTest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGBufferTest(AGBufferTest&&); \
	AGBufferTest(const AGBufferTest&); \
public: \
	NO_API virtual ~AGBufferTest();


#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_50_PROLOG
#define FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_53_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_53_INCLASS \
	FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h_53_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GBUFFERTEST_API UClass* StaticClass<class AGBufferTest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_learningC_Plugins_GBufferTest_Source_GBufferTest_Public_GBufferTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
