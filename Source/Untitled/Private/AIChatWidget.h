// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "AIChatWidget.generated.h"

/**
 * 
 */
UCLASS()
class UAIChatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

private:
#pragma region --- Weights ---
	/* Weight - Budget */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* BudgetPercentTxt;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* BudgetProgressBar;

	/* Weight - Throughput */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ThroughputPercentTxt;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ThroughputProgressBar;

	/* Weight - Robustness */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RobustnessPercentTxt;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* RobustnessProgressBar;
#pragma endregion

#pragma region --- Text box ---
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* InputTextBox;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* OutputText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LastUpdateTxt;

#pragma endregion
	UPROPERTY(meta = (BindWidget))
	UButton* GenerateBtn;

	FTimerHandle TimerHandle_GenerateTask;

#pragma region --- Functions ---
	UFUNCTION()
	void OnGenerateBtnClicked();

	void OnGenerateTaskCompleted();
#pragma endregion

};
