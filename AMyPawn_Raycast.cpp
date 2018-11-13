// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn_Raycast.h"
#include "Components/InputComponent.h"//PlayerInputComponent引用
#include "DrawDebugHelpers.h" //DrawDebugLine引用
#include "Animation/AnimInstance.h"// GetWorld()
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn_Raycast::AMyPawn_Raycast()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");//添加运动组件，否则不能移动
	
	Root= CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	
	
	Camera = CreateDefaultSubobject<UCameraComponent>("MyCamera");
	Camera->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMyPawn_Raycast::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_Raycast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn_Raycast::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)//映射定义
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("AddFire", IE_Pressed, this, &AMyPawn_Raycast::MyRatcast);//时间映射定义，AddFire事件发生时，IE_Press表示按下，调用该类对象（this）的MyRatcast函数
	PlayerInputComponent->BindAxis("Moveforward", this, &AMyPawn_Raycast::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn_Raycast::MoveRight);//添加映射获得映射的值
}

void AMyPawn_Raycast::MyRatcast()//产生射线
{
	FHitResult* MyHitResult = new FHitResult();//不完整类型用指针创建，该指针所指的变量用于存储射线碰撞物体的碰撞结果
	FVector StartVector = this->GetActorLocation();//射线起始位置，pawn类对线在世界中的位置
	FVector ForwardVector = GetActorForwardVector();//射线发生的方向，pawn向前的朝向，即游戏中玩家的面向
	FVector EndVector = ForwardVector * 1000.f + StartVector;//射线终止位置，式子的含义为从类对象位置沿与玩家朝向平行的位置发射一根1000射线所在的终点位置
	FCollisionQueryParams* CQP = new FCollisionQueryParams();//??
	if (GetWorld()->LineTraceSingleByChannel(*MyHitResult, StartVector,EndVector,ECC_Visibility,CQP)/*在StartVector,EndVector间生成一条射线，将与其他物体的碰撞结果存储在*MyHitResult里，射线不会显示在世界里*/)/*判定是否射线生成成功*/
	{
		DrawDebugLine(GetWorld(), StartVector, EndVector, FColor(255, 0, 0), true);//绘制一条debug线，可以用来显示看不见的射线
		if (MyHitResult->GetActor() != NULL)//如果射线碰撞到东西，删除射线
		{
			MyHitResult->GetActor()->Destroy();
		}
	}


}

void AMyPawn_Raycast::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);//获取方向根据映射添加移动
}


void AMyPawn_Raycast::MoveRight(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);//获取方向根据映射添加移动

}

