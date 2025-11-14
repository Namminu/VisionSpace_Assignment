// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "SynthesisWidget.generated.h"

/**
 * 
 */
UCLASS()
class USynthesisWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

private:
#pragma region --- SubWidgets ---
	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> CharacteristicWidget;

	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> AnalysisWidget;

	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ComparisionWidget;

	// AIChat Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> AIChatWidget;

	UPROPERTY(meta = (BindWidget))
	UBorder* CharacteristicBorder;

	UPROPERTY(meta = (BindWidget))
	UBorder* AnalysisBorder;

	UPROPERTY(meta = (BindWidget))
	UBorder* ComparisionBorder;

	UPROPERTY(meta = (BindWidget))
	UBorder* AIChatBorder;
#pragma endregion
};
