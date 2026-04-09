// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScreenMessage.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class BLASTERSAM_API UScreenMessage : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* MessageTextBlock;

	void SetMessageText(FString Message);
};
