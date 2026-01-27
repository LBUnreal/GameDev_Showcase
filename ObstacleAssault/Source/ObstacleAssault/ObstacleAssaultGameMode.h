// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObstacleAssaultGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AObstacleAssaultGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AObstacleAssaultGameMode();

	UFUNCTION(BlueprintCallable)
	void HandleGameStart();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();


private:
	class AObstacleAssaultPlayerController* ObstacleAssaultPlayerController;
	float StartDelay = 3.f;


};



