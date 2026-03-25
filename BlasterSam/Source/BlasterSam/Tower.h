// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BLASTERSAM_API ATower : public ABasePawn
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank* GetTank();
	void SetTank(ATank* NewTankValue);

	void HandleDestruction() override;

	UPROPERTY(EditAnywhere)
	float FireRange = 300.f;

	UPROPERTY(EditAnywhere)
	float FireRate = 2.f;

private:
	ATank* Tank;

	void CheckFireCondition();
	bool InFireRange();
};
