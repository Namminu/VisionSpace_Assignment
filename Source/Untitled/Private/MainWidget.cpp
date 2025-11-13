// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (closeButton)
	{
		closeButton->OnClicked.AddDynamic(this, &UMainWidget::OnCloseButtonClicked);
	}

	// Widgets 생성 및 추가
	if(AIChatWidget && AIChatBorder)
	{
		UUserWidget* AIChatWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), AIChatWidget);
		if(AIChatWidgetInstance)
		{
			AIChatBorder->SetContent(AIChatWidgetInstance);
		}
	}
	
}

void UMainWidget::OnCloseButtonClicked()
{
	OnClosed.Broadcast();
	// 위젯을 부모에서 제거하여 닫기
	this -> RemoveFromParent();
}