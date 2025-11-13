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
	// 1. InputTextBox 내용 지우기
	InputTextBox->SetText(FText::GetEmpty());

	// 2. 로딩 애니메이션 시작
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

	// 3. 로딩 완료 메서드 설정
	UWorld* world = GetWorld();
	if (world)
	{
		world->GetTimerManager().SetTimer(
			TimerHandle_GenerateTask,
			this,
			&UAIChatWidget::OnGenerateTaskCompleted,
			2.0f, // 대기 시간 임의 3초 설정
			false
		);
	}
}

void UAIChatWidget::OnGenerateTaskCompleted()
{
	// 1. 로딩 애니메이션 종료
	if (loadingWidgetInstance)
	{
		if (loadingBorder->GetContent() == loadingWidgetInstance)
		{
			loadingBorder->SetContent(nullptr);
		}
		else loadingWidgetInstance->RemoveFromParent();
		loadingWidgetInstance = nullptr;
	}

	// 2. OutputText 내용 설정
	FText dummyResult = FText::FromString(TEXT(
	"KPI +15% | ROI +10% | EFF 85% | MOP ↓ 1.2s\n"
    "▲ Performance Alert: Current operation shows 35% efficiency gap\n"
    "High labor dependency (20 workers)\n"
    "Consider automation for 62% cost reduction potential\n"
	"Manual processes limiting scalability"));
	OutputText->SetText(dummyResult);

	// 3. LastUpdateTxt 갱신
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
