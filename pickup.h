// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/ShapeComponent.h"
#include "Classes/Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"
#include "MyActor.generated.h"

UCLASS()
class FIRSTPERSON_CODE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)//定义组件
	USceneComponent* PickupRoot;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;//创建固体网格
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* PickupBox; //碰撞盒子（拾取判定）

	UFUNCTION()//定义功能函数名称（名称自定义），函数类型为默认设置，不能修改？参照重载函数。 不同于自定义函数，需要添加FUNCTION（）才能使用
	void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);//自定义碰撞函数,注意必须与OnComponentBeginOverlap.AddDynamic中提供的类型一致
};
