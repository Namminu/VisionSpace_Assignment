// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"
#include "MainWidget.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (openButton)
	{
		openButton->OnClicked.AddDynamic(this, &UTitleWidget::OnOpenButtonClicked);
	}
}

void UTitleWidget::OnOpenButtonClicked()
{
	if (!displayWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Display Widget Not Set for %s"), *GetName());
		return;
	}

	if(!displayWidgetInstance)
	{
		UMainWidget* MainWidgetInstance = CreateWidget<UMainWidget>(GetWorld(), displayWidget);
		if (MainWidgetInstance)
		{
			MainWidgetInstance->OnClosed.AddDynamic(this, &UTitleWidget::HandleDisplayWidgetClosed);

			displayWidgetInstance = MainWidgetInstance;
			displayWidgetInstance->AddToViewport();
		}
	}
}

void UTitleWidget::HandleDisplayWidgetClosed()
{
	displayWidgetInstance = nullptr;
}
