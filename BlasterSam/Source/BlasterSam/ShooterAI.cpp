// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BlasterSamCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShooterAI::StartBehaviorTree(ABlasterSamCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<ABlasterSamCharacter>(GetPawn());

		if (Player)
		{
			PlayerCharacter = Player;
		}

		RunBehaviorTree(EnemyAIBehaviorTree);

		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();

		if (MyBlackboard && Player && MyCharacter)
		{
			MyBlackboard->SetValueAsVector(TEXT("StartLocation"), MyCharacter->GetActorLocation());
		}
	}
}

ABlasterSamCharacter* AShooterAI::GetPlayerCharacter()
{
	return PlayerCharacter;
}

ABlasterSamCharacter* AShooterAI::GetMyCharacter()
{
	return MyCharacter;
}
