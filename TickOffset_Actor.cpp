#include "TickOffset.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "TimerManager.h"

ATickOffset::ATickOffset()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATActor1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ATActor1::ResetTimer()
{
	
}
