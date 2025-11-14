// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AllStructs.generated.h"

/**
 * 
 */
class AllStructs
{
public:
	AllStructs();
	~AllStructs();
};

USTRUCT(BlueprintType)
struct FPerformanceData
{
	GENERATED_USTRUCT_BODY();

public:
	FText ItemName;
	float TraditionalValue;
	float AIDrivenValue;

	FPerformanceData()
		: ItemName(FText::FromString("Default Item"))
		, TraditionalValue(0.f)
		, AIDrivenValue(0.f)
	{}

	FPerformanceData(const FText& InItemName, float InTraditionalValue, float InAIDrivenValue)
		: ItemName(InItemName)
		, TraditionalValue(InTraditionalValue)
		, AIDrivenValue(InAIDrivenValue)
	{}
};

USTRUCT(BlueprintType)
struct FIndicatorData
{
	GENERATED_USTRUCT_BODY();

public:
	FText Title;
	FText SubTitle;
	FText Description;
	float Percent;
	FText Status;

	FIndicatorData()
		: Title(FText::FromString("Default Title"))
		, SubTitle(FText::FromString("Default SubTitle"))
		, Description(FText::FromString("Default Description"))
		, Percent(0.f)
		, Status(FText::FromString("Default Status"))
	{}

	FIndicatorData(const FText& InTitle, const FText& InSubTitle, const FText& InDescription, float InPercent, const FText& InStatus)
		: Title(InTitle)
		, SubTitle(InSubTitle)
		, Description(InDescription)
		, Percent(InPercent)
		, Status(InStatus)
	{}
};