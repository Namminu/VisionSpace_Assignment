// Fill out your copyright notice in the Description page of Project Settings.


#include "SynthesisWidget.h"

void USynthesisWidget::NativeConstruct()
{
	APlayerController* OwningPlayer = GetOwningPlayer();
	if (!OwningPlayer)
	{
		UE_LOG(LogTemp, Error, TEXT("Owing Player Controller NULL ERROR"));
		return;
	}
		
	if (AIChatWidget && AIChatBorder)
	{
		UUserWidget* AIChatWidgetInstance = CreateWidget<UUserWidget>(OwningPlayer, AIChatWidget);
		if (AIChatWidgetInstance)
		{
			AIChatBorder->SetContent(AIChatWidgetInstance);
		}
	}
	else
	{
		if (!AIChatWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("AIChatWidget Error"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AIChatBorder Error"));
		}
	}

	if (ComparisionWidget && ComparisionBorder)
	{
		UUserWidget* ComparisionWidgetInstance = CreateWidget<UUserWidget>(OwningPlayer, ComparisionWidget);
		if (ComparisionWidgetInstance)
		{
			ComparisionBorder->SetContent(ComparisionWidgetInstance);
		}
	}
	else
	{
		if (!ComparisionWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("ComparisionWidget Error"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ComparisionBorder Error"));
		}
	}

	if (AnalysisWidget && AnalysisBorder)
	{
		UUserWidget* AnalysisWidgetInstance = CreateWidget<UUserWidget>(OwningPlayer, AnalysisWidget);
		if (AnalysisWidgetInstance)
		{
			AnalysisBorder->SetContent(AnalysisWidgetInstance);
		}
	}
	else
	{
		if (!AnalysisWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("AnalysisWidget Error"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AnalysisBorder Error"));
		}
	}

	if (CharacteristicWidget && CharacteristicBorder)
	{
		UUserWidget* CharacteristicWidgetInstance = CreateWidget<UUserWidget>(OwningPlayer, CharacteristicWidget);
		if (CharacteristicWidgetInstance)
		{
			CharacteristicBorder->SetContent(CharacteristicWidgetInstance);
		}
	}
	else
	{
		if (!CharacteristicWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("CharacteristicWidget Error"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CharacteristicBorder Error"));
		}
	}
}