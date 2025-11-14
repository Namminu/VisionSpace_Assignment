// Fill out your copyright notice in the Description page of Project Settings.


#include "IndicatorWidget.h"

void UIndicatorWidget::SetData(const FIndicatorData& data)
{
	TitleTxt->SetText(data.Title);
	SubTitleTxt->SetText(data.SubTitle);
	DescriptionTxt->SetText(data.Description);

	float percent = data.Percent * 100;
	FString PercentString = FString::Printf(TEXT("%.0f"), percent);
	PercentTxt->SetText(FText::FromString(PercentString));

	if (percent >= 200.f)
		SetTextGradation();
}

void UIndicatorWidget::SetTextGradation()
{

}
