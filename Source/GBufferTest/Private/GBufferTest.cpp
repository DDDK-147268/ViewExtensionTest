#include "GBufferTest.h"

#include "CoreMinimal.h"
#include "RenderCore.h"


//Subsystem的实现
void UGBufferTestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);//执行直接父类的Initialize方法

	//创建一个新的FGBufferTestSceneViewExtension实例，并将其存储在GBufferTestSceneViewExtensionPtr中
	GBufferTestSceneViewExtensionPtr = FSceneViewExtensions::NewExtension<FGBufferTestSceneViewExtension>();
}

void UGBufferTestSubsystem::Deinitialize()
{
	Super::Deinitialize();//执行直接父类的Deinitialize方法

	{
		GBufferTestSceneViewExtensionPtr->IsActiveThisFrameFunctions.Empty();//清空IsActiveThisFrameFunctions数组,这个数组用于存储当前激活的视图扩展函数

		FSceneViewExtensionIsActiveFunctor IsActiveFunctor;

		//添加一个新的IsActiveFunctor到IsActiveThisFrameFunctions数组中,并设置其IsActiveFunction为一个lambda函数，返回false
		IsActiveFunctor.IsActiveFunction = [](const ISceneViewExtension* SceneViewExtension, const FSceneViewExtensionContext& Context)
		{
			return TOptional<bool>(false);
		};
		GBufferTestSceneViewExtensionPtr->IsActiveThisFrameFunctions.Add(IsActiveFunctor);

		//调用Invalidate方法，通知视图扩展无效
		//Invalidate方法会在渲染线程上执行，确保视图扩展被正确清理,否则渲染线程可能会继续使用已被销毁的视图扩展对象，导致崩溃或未定义行为
		//GBufferTestSceneViewExtensionPtr->Invalidate();
		//重置GBufferTestSceneViewExtensionPtr指针，释放所引用对象，并通知其弱引用不再指向有效对象
		GBufferTestSceneViewExtensionPtr.Reset();
		//将指针显式置为nullptr，提高代码健壮性的防御性措施
		GBufferTestSceneViewExtensionPtr = nullptr;
	}
}


