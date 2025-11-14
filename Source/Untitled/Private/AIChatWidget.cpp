// Fill out your copyright notice in the Description page of Project Settings.


#include "AIChatWidget.h"

void UAIChatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button click event
	if (GenerateBtn)
	{
		GenerateBtn->OnClicked.AddDynamic(this, &UAIChatWidget::OnGenerateBtnClicked);
	}

	// Set Dummy Data
	float budgetPercent = 0.34f;
	float throughputPercent = 0.64f;
	float robustnessPercent = 0.40f;

	BudgetPercentTxt->SetText(FText::AsPercent(budgetPercent));
	BudgetProgressBar->SetPercent(budgetPercent);

	ThroughputPercentTxt->SetText(FText::AsPercent(throughputPercent));
	ThroughputProgressBar->SetPercent(throughputPercent);

	RobustnessPercentTxt->SetText(FText::AsPercent(robustnessPercent));
	RobustnessProgressBar->SetPercent(robustnessPercent);
}

void UAIChatWidget::OnGenerateBtnClicked()
{
	InputTextBox->SetText(FText::GetEmpty());

	if (!loadingWidgetInstance)
	{
		if (!loadingWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("Loading Widget Null ERROR"));
		}
		loadingWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), loadingWidget);
		if (loadingWidgetInstance)
		{
			if (loadingBorder)
			{
				loadingBorder->SetContent(loadingWidgetInstance);
			}
			else loadingWidgetInstance->AddToViewport();
		}
	}

	UWorld* world = GetWorld();
	if (world)
	{
		world->GetTimerManager().SetTimer(
			TimerHandle_GenerateTask,
			this,
			&UAIChatWidget::OnGenerateTaskCompleted,
			2.0f,
			false
		);
	}
}

void UAIChatWidget::OnGenerateTaskCompleted()
{
	if (loadingWidgetInstance)
	{
		if (loadingBorder->GetContent() == loadingWidgetInstance)
		{
			loadingBorder->SetContent(nullptr);
		}
		else loadingWidgetInstance->RemoveFromParent();
		loadingWidgetInstance = nullptr;
	}

	FText dummyRichOutputData = FText::FromString(TEXT(
		"<SmallPercent>KPI +15% | ROI +10% | EFF 85% | MOP ↓ 1.2s</>\n"
		"<SmallOrange>▲ Performance Alert:</><SmallPercent>Current operation shows 35% efficiency gap</>\n"
		"<SmallRed>High labor dependency (20 workers)</>\n"
		"<SmallGreen>Consider automation for 62% cost reduction potential</>\n"
		"<SmallPurple>Manual processes limiting scalability</>\n"
		"<SmallPercent>Throughput +75% | Accuracy 99.9% | Downtime 0.5%</>\n"
		"<SmallOrange>Configuration Warning:</><SmallPurple> Current WMS is not compatible with AMR fleet</>\n"
		"<SmallGreen>Integrate WMS via API to support real-time robot orchestration</>\n"
		"<SmallGray>Inventory Accuracy:</><SmallPercent>99.9%</><SmallGray>(Goal: 100%) - Minor</><SmallRed> error </><SmallGray>margin</>\n"
		"<SmallGreen>Deploy 5 AGVs for long-distance transport to minimize human walking distance</>"
	));
	OutputText->SetText(dummyRichOutputData);

	FDateTime curTime = FDateTime::Now();
	int32 hour = curTime.GetHour() % 12;
	if (hour == 0) hour = 12;
	FString ampm = curTime.GetHour() >= 12 ? TEXT("PM") : TEXT("AM");
	FString formattedTime = FString::Printf(
		TEXT("Last updated : %s %02d:%02d:%02d"),
		*ampm,
		hour,
		curTime.GetMinute(),
		curTime.GetSecond());
	LastUpdateTxt->SetText(FText::FromString(formattedTime));
}
