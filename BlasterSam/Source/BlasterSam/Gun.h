// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"


class USceneComponent;
class USkeletalMeshComponent;
class AController;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS()
class BLASTERSAM_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float MaxRange = 10000.f;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* ImpactParticleSystem;

	UPROPERTY(EditAnywhere)
	float BulletDamage = 10;

	UPROPERTY(EditAnywhere)
	USoundBase* ShootSound;

	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* GunSkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* MuzzleFlashParticleSystem;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PullTrigger();

	AController* GetOwnerController();
	void SetOwnerController(AController* Controller);

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* GunSceneComponent;

	UPROPERTY(VisibleAnywhere)
	AController* OwnerController = nullptr;

};
