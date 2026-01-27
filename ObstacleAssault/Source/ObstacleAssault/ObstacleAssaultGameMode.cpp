// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObstacleAssaultGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ObstacleAssaultPlayerController.h"

AObstacleAssaultGameMode::AObstacleAssaultGameMode()
{
	// stub
}

void AObstacleAssaultGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacleAssaultGameMode::HandleGameStart()
{
	ObstacleAssaultPlayerController = Cast<AObstacleAssaultPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (ObstacleAssaultPlayerController)
	{
		ObstacleAssaultPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;

		FTimerDelegate PlayerEnableTimerDelegate =
			FTimerDelegate::CreateUObject(
				ObstacleAssaultPlayerController,
				&AObstacleAssaultPlayerController::SetPlayerEnabledState,
				true);

		GetWorldTimerManager().SetTimer(
			PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false);
	}
}