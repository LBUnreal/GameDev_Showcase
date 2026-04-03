// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

class UMover;
/**
 * 
 */
UCLASS()
class BLASTERSAM_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()
	
protected:
	//Called when the game starts
	virtual void BeginPlay() override;

public:
	//Initializes TriggerComponent's Default values
	UTriggerComponent();

	//Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedCom, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
	bool bIsPressurePlate = false;

	UPROPERTY(EditAnywhere)
	AActor* MoverActor = nullptr;

	UMover* Mover = nullptr;

	void Trigger(bool NewTriggerValue);

private:
	UPROPERTY(VisibleAnywhere)
	bool bIsTriggered = false;

	UPROPERTY(VisibleAnywhere)
	int32 ActivatorCount = 0;
};
