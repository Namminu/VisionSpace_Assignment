// Fill out your copyright notice in the Description page of Project Settings.


#include "IndicatorWidget.h"

void UIndicatorWidget::SetData(const FIndicatorData& data)
{
	if (CardBorder)
	{
		CardBorder->SetBrushColor(OriginalBorderColor);
	}

	TitleTxt->SetText(data.Title);
	SubTitleTxt->SetText(data.SubTitle);
	DescriptionTxt->SetText(data.Description);
	float percent = data.Percent * 100;
	// 폰트 그라데이션 설정
	if (percent >= 200.f)
	{
		FText formattedSPRichText = FText::Format(
			FText::FromString(TEXT("<LargeGradation>{0}</><MiddleGradation>%</><MiddleGradation>{1}</>")),
			FText::AsNumber(percent),
			data.Status
		);
		ShowPercent->SetText(formattedSPRichText);
	}
	else 
	{
		FText formattedSPRichText = FText::Format(
			FText::FromString(TEXT("<LargeNumber>{0}</><MiddlePercent>%</><SubOrange>{1}</>")),
			FText::AsNumber(percent),
			data.Status
		);
		ShowPercent->SetText(formattedSPRichText);
	}
}

void UIndicatorWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	if (CardBorder)
	{
		CardBorder->SetBrushColor(ChangeBorderColor);
	}
	OnIndicatorHoverd.ExecuteIfBound(this);
}

void UIndicatorWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
}

void UIndicatorWidget::ResetBorderColor()
{
	if (CardBorder)
	{
		CardBorder->SetBrushColor(OriginalBorderColor);
	}
}