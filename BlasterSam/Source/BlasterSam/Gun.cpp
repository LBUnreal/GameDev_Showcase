// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Gun Scene Component"));
	SetRootComponent(GunSceneComponent);

	GunSkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Skeletal Mesh Component"));
	GunSkeletalMeshComponent->SetupAttachment(GunSceneComponent);

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Muzzle Flash Partical System"));
	MuzzleFlashParticleSystem->SetupAttachment(GunSkeletalMeshComponent);
	Tags.Add("CollectableItem");
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	MuzzleFlashParticleSystem->Deactivate();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	MuzzleFlashParticleSystem->Activate(true);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ShootSound, GetActorLocation());

	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;

		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;
		bool HasHit = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPointLocation, EndLocation, ECC_GameTraceChannel2, Params);

		if (HasHit)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactParticleSystem, HitResult.ImpactPoint, HitResult.ImpactPoint.Rotation());

			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, HitResult.ImpactPoint);

			AActor* HitActor = HitResult.GetActor();

			if (HitActor)
			{
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), BulletDamage, GetOwnerController(), this, UDamageType::StaticClass());
			}
		}
	}
}

AController* AGun::GetOwnerController()
{
	return OwnerController;
}

void AGun::SetOwnerController(AController* Controller)
{
	OwnerController = Controller;
}

