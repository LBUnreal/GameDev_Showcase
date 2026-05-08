// Fill out your copyright notice in the Description page of Project Settings.


#include "Launcher.h"
#include "Projectile.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

ALauncher::ALauncher()
{
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(GunSkeletalMeshComponent);
}

void ALauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALauncher::PullTrigger()
{
	FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();

	AProjectile* Projectile =
		GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);

	if (Projectile)
	{
		Projectile->SetOwner(this);
	}
}

void ALauncher::BeginPlay()
{
	Super::BeginPlay();
}