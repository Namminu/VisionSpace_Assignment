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