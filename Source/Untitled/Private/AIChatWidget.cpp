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

	UE_LOG(LogTemp, Warning, TEXT("AIChat Widget Native Called"));

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
	// StartAnmation();

	// 3. 로딩 완료 메서드 설정
	UWorld* world = GetWorld();
	if (world)
	{
		world->GetTimerManager().SetTimer(
			TimerHandle_GenerateTask,
			this,
			&UAIChatWidget::OnGenerateTaskCompleted,
			3.0f, // 대기 시간 임의 3초 설정
			false
		);
	}
}

void UAIChatWidget::OnGenerateTaskCompleted()
{
	// 1. 로딩 애니메이션 종료
	// StopAnimation();

	// 2. OutputText 내용 설정
	FText dummyResult = FText::FromString(TEXT("dummy Result ~"));
	OutputText->SetText(dummyResult);

	// 3. LastUpdateTxt 갱신
	FDateTime curTime = FDateTime::Now();
	FString timeFormatString = TEXT("Last updated : %%p %%I:%%M:%%S");
	FString formattedTime = curTime.ToString(*timeFormatString);
	LastUpdateTxt->SetText(FText::FromString(formattedTime));
}
