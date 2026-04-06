// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lock.generated.h"

class UTriggerComponent;
class UStaticMeshComponent;

UCLASS()
class BLASTERSAM_API ALock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FString KeyItemName;

	bool GetIsKeyPlaced();
	void SetIsKeyPlaced(bool NewIsKeyPlacedValue);

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	UTriggerComponent* TriggerComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyItemMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* KeyItemMesh2;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsKeyPlaced = false;
};
