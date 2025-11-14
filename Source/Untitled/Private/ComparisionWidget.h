// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "AllStructs.h"
#include "ComparisionWidget.generated.h"

/**
 * 
 */
UCLASS()
class UComparisionWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> performanceWidget;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalItems;

	void SetAllProgressData(const TArray<FPerformanceData>& DataArray);

	UPROPERTY()
	TArray<FPerformanceData> dummyData;
};
