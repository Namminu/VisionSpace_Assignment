// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Open Butoon Clicked"));
	if (!displayWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Display Widget Not Set for %s"), *GetName());
		return;
	}

	if(!displayWidgetInstance)
	{
		displayWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), displayWidget);
		if (displayWidgetInstance)
		{
			displayWidgetInstance->AddToViewport();
		}
	}
}
