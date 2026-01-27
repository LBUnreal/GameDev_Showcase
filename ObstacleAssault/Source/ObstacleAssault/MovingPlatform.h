// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(0.f, 0.f, 0.f);

private:
	FVector StartLocation;

	UPROPERTY(VisibleAnywhere)
	double DistanceMoved = 0;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere)
	double MaxDistance = 300;
	float GetDistanceMoved(float DeltaTime);
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};
