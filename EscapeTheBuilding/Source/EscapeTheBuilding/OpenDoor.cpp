// Copyright N&T 2019


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpensTheDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	//Find the Owner
	AActor* Owner = GetOwner();

	//Create a rotator
	FRotator NewActorRotation = Owner->GetActorRotation();
	NewActorRotation.Yaw = 60.f;

	//Set Rotation
	Owner->SetActorRotation(NewActorRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Pull the Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpensTheDoor))
	{
		// If the ActorThatOpensTheDoor is volume
		OpenDoor();
	}
	
}

