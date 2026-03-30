// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlasterSamGameMode.h"
#include "Tank.h"
#include "Tower.h"
#include "ShooterAI.h"
#include "BlasterSamCharacter.h"
#include "Kismet/GameplayStatics.h"

ABlasterSamGameMode::ABlasterSamGameMode()
{
	// stub
}

void ABlasterSamGameMode::BeginPlay()
{
	Super::BeginPlay();
	InitializeNPCTurretTargeting();
	InitializeNPCInfantryTargeting();
}

/// <summary>
/// Sets Turret to target the player
/// </summary>
void ABlasterSamGameMode::InitializeNPCTurretTargeting()
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), Towers);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		TankPlayer = Cast<ATank>(PlayerPawn);
		InfantryPlayer = Cast<ABlasterSamCharacter>(PlayerPawn);

		int32 LoopIndex = 0;
		while (LoopIndex < Towers.Num())
		{
			AActor* TowerActor = Towers[LoopIndex];

			if (TowerActor)
			{
				ATower* Tower = Cast<ATower>(TowerActor);

				if (Tower)
				{
					if (TankPlayer)
					{
						Tower->SetTank(TankPlayer);
					}
					else if (InfantryPlayer)
					{
						Tower->SetInfantry(InfantryPlayer);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("BlasterSamGameMode: Failed to set Player target for %s"), *PlayerPawn->GetName());
					}

				}
			}

			LoopIndex++;
		}
	}
}

void ABlasterSamGameMode::InitializeNPCInfantryTargeting()
{
	//Initialize all AI Controllers with the Player
	ABlasterSamCharacter* Player = Cast<ABlasterSamCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	TArray<AActor*> ShooterAIActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), ShooterAIActors);

	for (AActor* ShooterAIActor : ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);

		if (ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Display, TEXT("%s starting behavior tree"), *ShooterAI->GetName());
		}
	}
}
