// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BlasterSamGameMode.generated.h"

class ATank;
class ABlasterSamCharacter;

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class ABlasterSamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ABlasterSamGameMode();

protected:
	virtual void BeginPlay() override;

private:
	ATank* TankPlayer;
	ABlasterSamCharacter* InfantryPlayer;
	void InitializeNPCTurretTargeting();
	void InitializeNPCInfantryTargeting();
};



