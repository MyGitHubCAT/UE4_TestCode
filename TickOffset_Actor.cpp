#include "TickOffset.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "TimerManager.h"

ATickOffset::ATickOffset()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyTestMesh = CreatDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	bCanmove = true;//默认值为真
}

// Called when the game starts or when spawned
void ATickOffset::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATickOffset::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();//设置一个FVector向量值,默认赋值为actor类对象在世界中的坐标向量值
	NewLocation.Z += 1000* DeltaTime;//向量的Z值增加1000*DeltaTime
	if(bCanmove)
	{
		bCanmove = false;
		GetWorld()->GetTimerManager().SetTime(MyTimerHandle,this,&ATickOffset::ResetTimer,2.0f,false);
		this->SetActorLocation(Newlocation);//将类对象移动到Newlocation对应位置
		//this->AddActorLocalOffset(Newlocation);//将类对象世界坐标位置增加Newlocation位移
	}
	
}

void ATickOffset::ResetTimer()//重置延时
{
	bCanmove = true;
	GetWorldTimerManager().ClearTimer(MyTimerHandle);
}
