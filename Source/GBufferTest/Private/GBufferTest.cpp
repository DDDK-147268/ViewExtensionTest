#include "GBufferTest.h"

#include "CoreMinimal.h"
#include "RenderCore.h"


//Subsystem的实现
void UGBufferTestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);//执行直接父类的Initialize方法

	//创建一个新的FGBufferTestSceneViewExtension实例，并将其存储在GBufferTestSceneViewExtensionPtr中
	GBufferTestSceneViewExtensionPtr = FSceneViewExtensions::NewExtension<FGBufferTestSceneViewExtension>(this);
}

void UGBufferTestSubsystem::Deinitialize()
{
	Super::Deinitialize();//执行直接父类的Deinitialize方法

	{
		//重置GBufferTestSceneViewExtensionPtr指针，释放所引用对象，并通知其弱引用不再指向有效对象
		GBufferTestSceneViewExtensionPtr.Reset();
		//将指针显式置为nullptr，提高代码健壮性的防御性措施
		GBufferTestSceneViewExtensionPtr = nullptr;
	}
}

AGBufferTest::AGBufferTest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//初始化默认值
	Segment = 2;
	Size = 1.0f;
	Threshold = 0.5f;
	BokehTextureRHI = nullptr;
	Active = true;
	//注册到UGBufferTestSubsystem中
	// Add a scene component as our root
	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	RootComponent->SetMobility(EComponentMobility::Movable);//设置可移动性
}

//AGBufferTest::~AGBufferTest() {
//}

void AGBufferTest::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	//当编辑器属性发生变化时，更新GBufferTestSubsystem中的GBufferTest实例
	if (UGBufferTestSubsystem* Subsystem = GetWorld()->GetSubsystem<UGBufferTestSubsystem>())
	{
		Subsystem->UpdateGBufferTest(this);
	}
}

