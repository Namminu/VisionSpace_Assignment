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
	TArray<FPerformanceData> dummyData =
	{
		FPerformanceData{ FText::FromString("Throughput"), 0.35f, 0.65f},
		FPerformanceData{ FText::FromString("Efficiency (OEE)"), 0.4f, 0.6f },
		FPerformanceData{ FText::FromString("Accuracy"), 0.8f, 0.95f },
		FPerformanceData{ FText::FromString("LeadTime"), 0.6f, 0.45f },
		FPerformanceData{ FText::FromString("Operating Cost"), 0.5f, 0.4f },
	};
};
