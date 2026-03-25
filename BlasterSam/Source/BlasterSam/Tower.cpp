// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle FireTimeHandle;
	GetWorldTimerManager().SetTimer(FireTimeHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

ATank* ATower::GetTank()
{
	return Tank;
}

void ATower::SetTank(ATank* NewTankValue)
{
	if (NewTankValue)
	{
		Tank = NewTankValue;
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();

	UE_LOG(LogTemp, Display, TEXT("Tower HandleDestruction"));
	Destroy();
}

void ATower::CheckFireCondition()
{
	if (Tank && Tank->GetIsAlive() && InFireRange())
	{
		Fire();
	 }
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		float DistanceToTank = GetDistanceTo(Tank);

		return DistanceToTank <= FireRange;
	}

	return false;
}
