// Fill out your copyright notice in the Description page of Project Settings.


#include "AnalysisWidget.h"

void UAnalysisWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ChartSwitcher)
	{
		if (_24hWidget)
		{
			UUserWidget* _24hWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), _24hWidget);
			if (_24hWidgetInstance)
			{
				ChartSwitcher->AddChild(_24hWidgetInstance);
				chartInstances.Add(_24hWidgetInstance);
			}
		}
		if (_weekWidget)
		{
			UUserWidget* _weekWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), _weekWidget);
			if (_weekWidgetInstance)
			{
				ChartSwitcher->AddChild(_weekWidgetInstance);
				chartInstances.Add(_weekWidgetInstance);
			}
		}
		if (_monthWidget)
		{
			UUserWidget* _monthWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), _monthWidget);
			if (_monthWidgetInstance)
			{
				ChartSwitcher->AddChild(_monthWidgetInstance);
				chartInstances.Add(_monthWidgetInstance);
			}
		}
		if (_yearWidget)
		{
			UUserWidget* _yearWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), _yearWidget);
			if (_yearWidgetInstance)
			{
				ChartSwitcher->AddChild(_yearWidgetInstance);
				chartInstances.Add(_yearWidgetInstance);
			}
		}
	}

	if (_24hButton)
	{
		_24hButton->OnClicked.AddDynamic(this, &UAnalysisWidget::On24hButtonClicked);
		AllButtons.Add(_24hButton);
	}
	if (WeekButton)
	{
		WeekButton->OnClicked.AddDynamic(this, &UAnalysisWidget::OnWeekButtonClicked);
		AllButtons.Add(WeekButton);
	}
	if (MonthButton)
	{
		MonthButton->OnClicked.AddDynamic(this, &UAnalysisWidget::OnMonthButtonClicked);
		AllButtons.Add(MonthButton);
	}
	if (YearButton)
	{
		YearButton->OnClicked.AddDynamic(this, &UAnalysisWidget::OnYearButtonClicked);
		AllButtons.Add(YearButton);
	}

	FText formattedEARichText = FText::Format(
		FText::FromString(TEXT("<LargeNumber>{0}</><PositiveBlue>EA</>")),
		FText::AsNumber(23094.57)
	);
	EARichTxt->SetText(formattedEARichText);

	FText formattedPercentRichText = FText::Format(
		FText::FromString(TEXT("<PositiveBlue>+</><LargeNumber>{0}</><SmallPercent>%</>")),
		FText::AsNumber(19.24f)
		);
	PercentRichTxt->SetText(formattedPercentRichText);

	OnMonthButtonClicked();
}

void UAnalysisWidget::On24hButtonClicked()
{
	if (ChartSwitcher)
	{
		ChartSwitcher->SetActiveWidgetIndex(0);
		UpdateButtonStyle(0);
	}
}

void UAnalysisWidget::OnWeekButtonClicked()
{
	if (ChartSwitcher)
	{
		ChartSwitcher->SetActiveWidgetIndex(1);
		UpdateButtonStyle(1);
	}
}

void UAnalysisWidget::OnMonthButtonClicked()
{
	if (ChartSwitcher)
	{
		ChartSwitcher->SetActiveWidgetIndex(2);
		UpdateButtonStyle(2);
	}
}

void UAnalysisWidget::OnYearButtonClicked()
{
	if (ChartSwitcher)
	{
		ChartSwitcher->SetActiveWidgetIndex(3);
		UpdateButtonStyle(3);
	}
}

void UAnalysisWidget::UpdateButtonStyle(int ActiveIndex)
{
	for (int i = 0; i < AllButtons.Num(); i++)
	{
		FButtonStyle CurrentStyle = AllButtons[i]->WidgetStyle;
		FLinearColor TargetColor;

		if (i == ActiveIndex)
		{
			TargetColor = SelectedButtonColor;
		}
		else
		{
			TargetColor = DefaultButtonColor;
		}

		FSlateBrush NormalBrush = CurrentStyle.Normal;

		NormalBrush.TintColor = TargetColor;
		CurrentStyle.Normal = NormalBrush;

		AllButtons[i]->SetStyle(CurrentStyle);
	}
}