// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacteristicWidget.h"
#include "IndicatorWidget.h"
#include "Components/GridSlot.h"

void UCharacteristicWidget::NativeConstruct()
{
	Super::NativeConstruct();
    dummyData =
    {
        FIndicatorData{ FText::FromString("창고 처리량"), FText::FromString(""), FText::FromString("24h 물류 처리량 17만 -> 42만"), 0.75f, FText::FromString("향상") },
        FIndicatorData{ FText::FromString("Order Picking Accuracy"), FText::FromString(""), FText::FromString("피킹 시간"), 0.75f, FText::FromString("단축") },
        FIndicatorData{ FText::FromString("Lead Time"), FText::FromString(""), FText::FromString("리드타임 48H -> 24H"), 1.05f, FText::FromString("단축") },
        FIndicatorData{ FText::FromString("Space Utilization Efficiency"), FText::FromString("고밀도 저장 창고 면적"), FText::FromString("창고 활용 효율성"), 0.25f, FText::FromString("향상") },
        FIndicatorData{ FText::FromString("처리 용량"), FText::FromString(""), FText::FromString("처리 용량"), 3.00f, FText::FromString("증가") },
        FIndicatorData{ FText::FromString("Loabor costs"), FText::FromString("자율 창고 로봇으로 24시간 무인 운영"), FText::FromString("10억 달러 이상 인건비"), 0.15f, FText::FromString("간소화") },
        FIndicatorData{ FText::FromString("ROI 추정"), FText::FromString("예측"), FText::FromString("초기 2년 내"), 2.75f, FText::FromString("달성") },
        FIndicatorData{ FText::FromString("재고 비용"), FText::FromString("예측"), FText::FromString("재고 최적화"), 0.15f, FText::FromString("절감") },
        FIndicatorData{ FText::FromString("최적 경로"), FText::FromString("예측"), FText::FromString("연료비 절감, 시간"), 0.55f, FText::FromString("단축") }
    };

	SetAllIndicatorData(dummyData);
}

void UCharacteristicWidget::SetAllIndicatorData(const TArray<FIndicatorData>& DataArray)
{
    if (!IndiGridPanel || !indicatorWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("VerticalItems or PerformanceWidget NULL ERROR"));
        return;
    }

    // 데이터 배열을 순회하며 위젯 생성 및 설정
    for (const FIndicatorData& Data : DataArray)
    {
        UIndicatorWidget* indiWidget = CreateWidget<UIndicatorWidget>(this, indicatorWidget);

        if (indiWidget)
        {
            indiWidget->SetData(Data);
            UGridSlot* slot = Cast<UGridSlot>(IndiGridPanel->AddChild(indiWidget));
            if (slot)
            {
                slot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
                slot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
                slot->SetPadding(FMargin(2.f));
            }
        }
    }
}
