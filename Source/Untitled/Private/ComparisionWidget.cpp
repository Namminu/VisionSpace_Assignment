// Fill out your copyright notice in the Description page of Project Settings.


#include "ComparisionWidget.h"
#include "PerformanceWidget.h"
#include "Components/VerticalBoxSlot.h"

void UComparisionWidget::NativeConstruct()
{
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