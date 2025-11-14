// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AllStructs.h"
#include "Components/TextBlock.h"
#include "IndicatorWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void SetData(const FIndicatorData& data);

private:
	void SetTextGradation();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SubTitleTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DescriptionTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PercentTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PercentMark;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatusTxt;
};
