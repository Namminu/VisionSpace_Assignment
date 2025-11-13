// Fill out your copyright notice in the Description page of Project Settings.


#include "PerformanceWidget.h"

void UPerformanceWidget::SetData(const FPerformanceData& data)
{
	// 이름 설정
	ItemNameTxt->SetText(data.ItemName);
	
	// TL 설정
	TL_Bar->SetPercent(data.TraditionalValue);
	FString TL_Text = FString::Printf(TEXT("%d%%"), FMath::RoundToInt(data.TraditionalValue * 100));
	TL_ValueTxt->SetText(FText::FromString(TL_Text));

	// AI 설정
	AI_Bar->SetPercent(data.AIDrivenValue);
	FString AI_Text = FString::Printf(TEXT("%d%%"), FMath::RoundToInt(data.AIDrivenValue * 100));
	AI_ValueTxt->SetText(FText::FromString(AI_Text));
}
