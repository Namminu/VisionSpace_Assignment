// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MainWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMainWidgetClosed);

UCLASS()
class UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintAssignable)
	FOnMainWidgetClosed OnClosed;

private:
#pragma region --- Page Widgets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> SynthesisWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ThroughputWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> OEEWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ROIWidget;

	TArray<UUserWidget*> PageInstances;
#pragma endregion
#pragma region --- Buttons ---
	TArray<UButton*> AllButtons;

	UPROPERTY(meta = (BindWidget))
	UButton* SynthesisBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* ThroughputBTN;

	UPROPERTY(meta = (BindWidget))
	UButton* OEEBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* ROIBtn;

	UPROPERTY(meta = (BindWidget))
	UButton* closeButton;
#pragma endregion

#pragma region --- Button Methods ---
	UFUNCTION(BlueprintCallable)
	void OnSynthesisButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnThroughputButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnOEEButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnROIButtonClicked();

	UFUNCTION()
	void OnCloseButtonClicked();

	void UpdateButtonStyle(int ActiveIndex);
#pragma endregion

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* PageSwitcher;

	UPROPERTY(EditAnywhere, Category = "Button Color", meta = (BindWidget))
	FLinearColor SelectedButtonColor;

	UPROPERTY(EditAnywhere, Category = "Button Color", meta = (BindWidget))
	FLinearColor DefaultButtonColor;
};
