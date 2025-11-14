// Fill out your copyright notice in the Description page of Project Settings.


#include "ComparisionWidget.h"
#include "PerformanceWidget.h"
#include "Components/VerticalBoxSlot.h"

void UComparisionWidget::NativeConstruct()
{
    Super::NativeConstruct();
    dummyData =
    {
        FPerformanceData{ FText::FromString("Throughput"), 0.35f, 0.65f},
        FPerformanceData{ FText::FromString("Efficiency (OEE)"), 0.4f, 0.6f },
        FPerformanceData{ FText::FromString("Accuracy"), 0.8f, 0.95f },
        FPerformanceData{ FText::FromString("LeadTime"), 0.6f, 0.45f },
        FPerformanceData{ FText::FromString("Operating Cost"), 0.5f, 0.4f },
    };

    SetAllProgressData(dummyData);
}

void UComparisionWidget::SetAllProgressData(const TArray<FPerformanceData>& DataArray)
{
    if (!VerticalItems || !performanceWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("VerticalItems or PerformanceWidget NULL ERROR"));
        return;
    }

    // 데이터 배열을 순회하며 위젯 생성 및 설정
    for (const FPerformanceData& Data : DataArray)
    {
        UPerformanceWidget* ItemWidget = CreateWidget<UPerformanceWidget>(this, performanceWidget);

        if (ItemWidget)
        {
            ItemWidget->SetData(Data);
            UVerticalBoxSlot* slot = Cast<UVerticalBoxSlot>(VerticalItems->AddChild(ItemWidget));
            if (slot)
            {
                FSlateChildSize ChildSize(ESlateSizeRule::Fill);
                ChildSize.Value = 1.0f;
                slot->SetSize(ChildSize);
            }
        }
    }
}