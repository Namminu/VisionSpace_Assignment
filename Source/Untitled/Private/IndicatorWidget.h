// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AllStructs.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/RichTextBlock.h"
#include "IndicatorWidget.generated.h"

/**
 * 
 */
UCLASS()
class UIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void ResetBorderColor();

	DECLARE_DELEGATE_OneParam(FOnIndicatorHoverd, UIndicatorWidget*)
	FOnIndicatorHoverd OnIndicatorHoverd;

	UFUNCTION()
	void SetData(const FIndicatorData& data);

private:
#pragma region --- Widget Properties ---
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SubTitleTxt;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DescriptionTxt;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* ShowPercent;
#pragma endregion

#pragma region --- Mouse Hover ---
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	UPROPERTY(meta = (BindWidget))
	UBorder* CardBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border Color", meta = (AllowPrivateAccess))
	FLinearColor OriginalBorderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border Color", meta = (AllowPrivateAccess))
	FLinearColor ChangeBorderColor;
#pragma endregion
};
