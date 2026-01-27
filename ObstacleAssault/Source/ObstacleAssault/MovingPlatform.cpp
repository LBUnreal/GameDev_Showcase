// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

float AMovingPlatform::GetDistanceMoved(float DeltaTime)
{
	return FVector::Distance(StartLocation, GetActorLocation());
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	DistanceMoved = GetDistanceMoved(DeltaTime);

	if (DistanceMoved >= MaxDistance)
	{
		double Overshoot = DistanceMoved - MaxDistance;
		UE_LOG(LogTemp, Warning, TEXT("Distance overshot: %f"), Overshoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MoveDirection * MaxDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//Performs a Rotation on the platform
	FRotator RotationToAdd = RotationVelocity * DeltaTime;
	AddActorLocalRotation(RotationToAdd);
}
