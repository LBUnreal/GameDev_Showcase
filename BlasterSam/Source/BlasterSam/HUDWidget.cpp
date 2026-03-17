// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "Components/ProgressBar.h"

void UHUDWidget::SetHealthBarPercent(float NewPercent)
{
	if (NewPercent >= 0.f && NewPercent <= 1.f)
	{
		HealthBar->SetPercent(NewPercent);
	}
}
