// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/ButtonSlot.h"
#include "AnalysisWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PageSwitcher)
	{
		if (SynthesisWidget)
		{
			UUserWidget* SynthesisWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), SynthesisWidget);
			if (SynthesisWidgetInstance)
			{
				PageSwitcher->AddChild(SynthesisWidgetInstance);
				PageInstances.Add(SynthesisWidgetInstance);
			}
		}
		if (ThroughputWidget)
		{
			UUserWidget* ThroughputWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ThroughputWidget);
			if (ThroughputWidgetInstance)
			{
				PageSwitcher->AddChild(ThroughputWidgetInstance);
				PageInstances.Add(ThroughputWidgetInstance);
			}
		}
		if (OEEWidget)
		{
			UUserWidget* OEEWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), OEEWidget);
			if (OEEWidgetInstance)
			{
				PageSwitcher->AddChild(OEEWidgetInstance);
				PageInstances.Add(OEEWidgetInstance);
			}
		}
		if (ROIWidget)
		{
			UUserWidget* ROIWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ROIWidget);
			if (ROIWidgetInstance)
			{
				PageSwitcher->AddChild(ROIWidgetInstance);
				PageInstances.Add(ROIWidgetInstance);
			}
		}
	}

	if (SynthesisBtn)
	{
		SynthesisBtn->OnClicked.AddDynamic(this, &UMainWidget::OnSynthesisButtonClicked);
		AllButtons.Add(SynthesisBtn);
	}
	if (ThroughputBTN)
	{
		ThroughputBTN->OnClicked.AddDynamic(this, &UMainWidget::OnThroughputButtonClicked);
		AllButtons.Add(ThroughputBTN);
	}
	if (OEEBtn)
	{
		OEEBtn->OnClicked.AddDynamic(this, &UMainWidget::OnOEEButtonClicked);
		AllButtons.Add(OEEBtn);
	}
	if (ROIBtn)
	{
		ROIBtn->OnClicked.AddDynamic(this, &UMainWidget::OnROIButtonClicked);
		AllButtons.Add(ROIBtn);
	}
	if (closeButton)
	{
		closeButton->OnClicked.AddDynamic(this, &UMainWidget::OnCloseButtonClicked);
		AllButtons.Add(closeButton);
	}
	OnSynthesisButtonClicked();
}

void UMainWidget::OnCloseButtonClicked()
{
	OnClosed.Broadcast();
	this -> RemoveFromParent();
}

void UMainWidget::OnSynthesisButtonClicked()
{
	if (PageSwitcher)
	{
		PageSwitcher->SetActiveWidgetIndex(0);
		UpdateButtonStyle(0);
	}
}

void UMainWidget::OnThroughputButtonClicked()
{
	if (PageSwitcher)
	{
		PageSwitcher->SetActiveWidgetIndex(1);
		UpdateButtonStyle(1);
	}
}

void UMainWidget::OnOEEButtonClicked()
{
	if (PageSwitcher)
	{
		PageSwitcher->SetActiveWidgetIndex(2);
		UpdateButtonStyle(2);
	}
}

void UMainWidget::OnROIButtonClicked()
{
	if (PageSwitcher)
	{
		PageSwitcher->SetActiveWidgetIndex(3);
		UpdateButtonStyle(3);
	}
}

void UMainWidget::UpdateButtonStyle(int ActiveIndex)
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