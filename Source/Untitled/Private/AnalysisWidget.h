// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/RichTextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
#include "AnalysisWidget.generated.h"

/**
 * 
 */
UCLASS()
class UAnalysisWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
#pragma region --- Chart Widgets ---
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> _24hWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> _weekWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> _monthWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> _yearWidget;

	TArray<UUserWidget*> chartInstances;
#pragma endregion
#pragma region --- Buttons ---
	TArray<UButton*> AllButtons;

	UPROPERTY(meta = (BindWidget))
	UButton* _24hButton;

	UPROPERTY(meta = (BindWidget))
	UButton* WeekButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MonthButton;

	UPROPERTY(meta = (BindWidget))
	UButton* YearButton;
#pragma endregion
#pragma region --- Button Methods ---
	UFUNCTION(BlueprintCallable)
	void On24hButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnWeekButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnMonthButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnYearButtonClicked();

	void UpdateButtonStyle(int ActiveIndex);
#pragma endregion

	UPROPERTY(EditAnywhere, Category = "Button Color", meta = (BindWidget))
	FLinearColor SelectedButtonColor;

	UPROPERTY(EditAnywhere, Category = "Button Color", meta = (BindWidget))
	FLinearColor DefaultButtonColor;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* ChartSwitcher;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* EARichTxt;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* PercentRichTxt;
};
