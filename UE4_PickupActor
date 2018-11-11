// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Classes/Components/BoxComponent.h"
#include "Classes/Components/ShapeComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values

AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;//将PickupRoot设置为根组件,缺少该命令默认为最先创建的组件为根组件（MyActor）
	/*PickupRoot->SetWorldScale3D(FVector(1, 1, 1));*/
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::KeepRelativeTransform);//StaticMeshComponent中attach函数将MyMesh添加到PickupRoot
	//
	PickupBox = CreateDefaultSubobject<UBoxComponent>("PickuoBox");
	PickupBox->SetWorldScale3D(FVector(2, 2, 2));
	PickupBox->SetGenerateOverlapEvents(true);
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::OnPlayerEnterPickupBox);
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::KeepRelativeTransform);//设置碰撞盒
	

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Destroy();
}

