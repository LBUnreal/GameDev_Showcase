// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAI.generated.h"

class ABlasterSamCharacter;
/**
 * 
 */
UCLASS()
class BLASTERSAM_API AShooterAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	//Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	APawn* PlayerPawn;

	ABlasterSamCharacter* PlayerCharacter;
	ABlasterSamCharacter* MyCharacter; //Controlled by the AI
public:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	void StartBehaviorTree(ABlasterSamCharacter* Player);

	ABlasterSamCharacter* GetPlayerCharacter();
	ABlasterSamCharacter* GetMyCharacter();
};
