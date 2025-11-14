// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "AllStructs.h"
#include "PerformanceWidget.generated.h"

/**
 * 
 */
UCLASS()
class UPerformanceWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UI|SetData")
	void SetData(const FPerformanceData& data);

private:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemNameTxt;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* TL_Bar;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TL_ValueTxt;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* AI_Bar;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* AI_ValueTxt;
};
