// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"
#include "TriggerComponent.h"
#include "CollectableItem.h"

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	SetRootComponent(RootComp);

	TriggerComp = CreateDefaultSubobject<UTriggerComponent>(TEXT("Trigger Comp"));
	TriggerComp->SetupAttachment(RootComp);

	KeyItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Item Mesh"));
	KeyItemMesh->SetupAttachment(RootComp);

	KeyItemMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Item Mesh2"));
	KeyItemMesh2->SetupAttachment(RootComp);

	Tags.Add("Lock");
}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	SetIsKeyPlaced(false);
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ALock::GetIsKeyPlaced()
{
	return bIsKeyPlaced;
}

void ALock::SetIsKeyPlaced(bool NewIsKeyPlacedValue)
{
	bIsKeyPlaced = NewIsKeyPlacedValue;
	TriggerComp->Trigger(NewIsKeyPlacedValue);
	KeyItemMesh->SetVisibility(NewIsKeyPlacedValue);
	KeyItemMesh2->SetVisibility(NewIsKeyPlacedValue);
}

