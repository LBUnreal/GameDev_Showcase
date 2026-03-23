// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnhancedInputSubsystems.h"
#include "Tank.generated.h"

class UCameraComponent;
class UInputMappingContext;
class USpringArmComponent;
class UInputAction;
class EnhancedInputComponent;
class APlayerController;

/**
 * 
 */
UCLASS()
class BLASTERSAM_API ATank : public ABasePawn
{
	GENERATED_BODY()

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

public:
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere)
	float Speed = 300.f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 100.f;

	void HandleDestruction() override;

	bool GetIsAlive();

	void SetPlayerEnabled(bool Enabled);

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	void MoveInput(const FInputActionValue& Value);

	void RotateInput(const FInputActionValue& Value);

	APlayerController* PlayerController;

	bool IsAlive = true;
};
