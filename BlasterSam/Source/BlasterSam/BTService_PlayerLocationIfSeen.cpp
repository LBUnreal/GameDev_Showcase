// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update player location if seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());

	if (OwnerController)
	{
		ABlasterSamCharacter* Player = OwnerController->GetPlayerCharacter();
		UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

		if (Player && Blackboard)
		{
			bool HasLineOfSight = OwnerController->LineOfSightTo(Player);
			if (HasLineOfSight)
			{
				Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
				OwnerController->SetFocus(Player, EAIFocusPriority::Gameplay);
			}
			else
			{
				Blackboard->ClearValue(GetSelectedBlackboardKey());
				OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
			}
		}
	}
}
