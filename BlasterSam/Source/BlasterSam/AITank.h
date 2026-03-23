// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "AITank.generated.h"

/**
 * 
 */
UCLASS()
class BLASTERSAM_API AAITank : public ATower
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
