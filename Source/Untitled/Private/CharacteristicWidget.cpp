// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacteristicWidget.h"
#include "IndicatorWidget.h"
#include "Components/GridSlot.h"

void UCharacteristicWidget::NativeConstruct()
{
	Super::NativeConstruct();
    dummyData =
    {
        /* 한글 폰트 출력 시 깨짐현상 문제 : 해결 보류 */
        //FIndicatorData(FText::FromString("창고 처리량"), FText::FromString(""), FText::FromString("24h 물류 처리량 17만 -> 42만"), 0.75f, FText::FromString("향상")),
        //FIndicatorData(FText::FromString("Order Picking Accuracy"), FText::FromString(""), FText::FromString("피킹 시간"), 0.75f, FText::FromString("단축")),
        //FIndicatorData(FText::FromString("Lead Time"), FText::FromString(""), FText::FromString("리드타임 48H -> 24H"), 1.05f, FText::FromString("단축")),
        //FIndicatorData(FText::FromString("Space Utilization Efficiency"), FText::FromString("고밀도 저장 창고 면적"), FText::FromString("창고 활용 효율성"), 0.25f, FText::FromString("향상")),
        //FIndicatorData(FText::FromString("처리 용량"), FText::FromString(""), FText::FromString("처리 용량"), 3.00f, FText::FromString("증가")),
        //FIndicatorData(FText::FromString("Loabor costs"), FText::FromString("자율 창고 로봇으로 24시간 무인 운영"), FText::FromString("10억 달러 이상 인건비"), 0.15f, FText::FromString("간소화")),
        //FIndicatorData(FText::FromString("ROI 추정"), FText::FromString("예측"), FText::FromString("초기 2년 내"), 2.75f, FText::FromString("달성")),
        //FIndicatorData(FText::FromString("재고 비용"), FText::FromString("예측"), FText::FromString("재고 최적화"), 0.15f, FText::FromString("절감")),
        //FIndicatorData(FText::FromString("최적 경로"), FText::FromString("예측"), FText::FromString("연료비 절감, 시간"), 0.55f, FText::FromString("단축"))

        FIndicatorData(FText::FromString("Warehouse Throughput"), FText::FromString(""), FText::FromString("Logistics throughput 170k -> 420k"), 0.75f, FText::FromString("Improved")),
        FIndicatorData(FText::FromString("Order Picking Accuracy"), FText::FromString(""), FText::FromString("Picking Time"), 0.75f, FText::FromString("Reduced")),
        FIndicatorData(FText::FromString("Lead Time"), FText::FromString(""), FText::FromString("Lead Time 48H -> 24H"), 1.05f, FText::FromString("Reduced")),
        FIndicatorData(FText::FromString("Space Utilization Efficiency"), FText::FromString("High Density Storage"), FText::FromString("Warehouse Utilization"), 0.25f, FText::FromString("Improved")),
        FIndicatorData(FText::FromString("Processing Capacity"), FText::FromString(""), FText::FromString("Processing Capacity"), 3.00f, FText::FromString("Increased")),
        FIndicatorData(FText::FromString("Labor Costs"), FText::FromString("24h unmanned operation"), FText::FromString("$1B+ Labor Cost"), 0.15f, FText::FromString("Optimized")),
        FIndicatorData(FText::FromString("Estimated ROI"), FText::FromString("Forecast"), FText::FromString("Within the first 2 years"), 2.75f, FText::FromString("Achieved")),
        FIndicatorData(FText::FromString("Inventory Costs"), FText::FromString("Forecast"), FText::FromString("Inventory Optimization"), 0.15f, FText::FromString("Reduced")),
        FIndicatorData(FText::FromString("Optimal Route"), FText::FromString("Forecast"), FText::FromString("Fuel Costs, Time"), 0.55f, FText::FromString("Reduced"))
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
    IndiGridPanel->ClearChildren();

    for (int i = 0; i < DataArray.Num(); i++)
    {
		const int row = i / 3;
		const int col = i % 3;

        UIndicatorWidget* indiWidget = CreateWidget<UIndicatorWidget>(this, indicatorWidget);
        if (indiWidget)
        {
            indiWidget->SetData(DataArray[i]);
            indiWidget->OnIndicatorHoverd.BindUObject(this, &UCharacteristicWidget::OnIndicatorCardHovered);
            UGridSlot* slot = Cast<UGridSlot>(IndiGridPanel->AddChildToGrid(indiWidget, row, col));
            if (slot)
            {
                slot->SetRow(row);
				slot->SetColumn(col);

                slot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
                slot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
                slot->SetPadding(FMargin(2.f));
			}
        }
    }
}

void UCharacteristicWidget::OnIndicatorCardHovered(UIndicatorWidget* hoveredIndicator)
{
    if (currentHoveredIndicator && currentHoveredIndicator != hoveredIndicator)
    {
        currentHoveredIndicator->ResetBorderColor();
    }

    currentHoveredIndicator = hoveredIndicator;
}
