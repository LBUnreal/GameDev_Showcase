// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
	SetShouldMove(false);
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentLocation = GetOwner()->GetActorLocation();

	ReachedTarget = CurrentLocation.Equals(TargetLocation, 0.000001);

	if (!ReachedTarget)
	{
		float Speed = MoveOffset.Length() / MoveTime;
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}
}

bool UMover::GetShouldMove()
{
	return bShouldMove;
}

void UMover::SetShouldMove(bool NewShouldMove)
{
	bShouldMove = NewShouldMove;

	if (bShouldMove)
	{
		//Target location is the start location + the move offset
		TargetLocation = StartLocation + MoveOffset;
	}
	else
	{
		//Target location is the start location
		TargetLocation = StartLocation;
	}
}

