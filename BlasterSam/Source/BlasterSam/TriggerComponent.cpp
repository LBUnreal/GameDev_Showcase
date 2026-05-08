// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Mover.h"

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MoverActor)
	{
		Mover = MoverActor->FindComponentByClass<UMover>();

		if (Mover)
		{
			UE_LOG(LogTemp, Display, TEXT("Mover Component found!"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Mover component not found!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MoverActor not set"));
	}

	if (bIsPressurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. You can turn these features
	// off to improved performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
	{
		ActivatorCount++;
		if (!bIsTriggered)
		{
			Trigger(true);
		}
	}

}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedCom, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
	{
		ActivatorCount--;
		if (ActivatorCount == 0 && bIsTriggered)
		{
			Trigger(false);
		}
	}
}

void UTriggerComponent::Trigger(bool NewTriggerValue)
{
	bIsTriggered = NewTriggerValue;
	if (Mover)
	{
		Mover->SetShouldMove(bIsTriggered);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s doesn't have a mover to trigger!"), *GetOwner()->GetActorNameOrLabel());
	}

}
