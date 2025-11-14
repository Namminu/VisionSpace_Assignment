// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AllStructs.h"
#include "Components/GridPanel.h"
#include "CharacteristicWidget.generated.h"

/**
 * 
 */
UCLASS()
class UCharacteristicWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> indicatorWidget;

	UPROPERTY(meta = (BindWidget))
	UGridPanel* IndiGridPanel;

	void SetAllIndicatorData(const TArray<FIndicatorData>& DataArray);

	UPROPERTY()
	TArray<FIndicatorData> dummyData;
};