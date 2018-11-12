
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TActor1.generated.h"


UCLASS()
class FC_CODE_TEST_API TickOffset : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	TickOffset();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyTestMesh;//mesh组件
  
	bool bCanmove;
	FTimerHandle MyTimerHandle;
	void ResetTimer();//延时器
};
