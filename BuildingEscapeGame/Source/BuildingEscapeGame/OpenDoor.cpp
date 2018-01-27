// copyright ismail 2017

#include "BuildingEscapeGame.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// ...
    
  ActorThatOpenTheDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
    
    
}

void UOpenDoor::OpenDoor(){
    
    AActor* Owner = GetOwner();
    FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);
    Owner->SetActorRotation(NewRotation);
    
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
    
    //pool the trigger volume
    if (PressurePlate != nullptr && ActorThatOpenTheDoor != nullptr && (PressurePlate -> IsOverlappingActor(ActorThatOpenTheDoor)))
        OpenDoor();
    }

