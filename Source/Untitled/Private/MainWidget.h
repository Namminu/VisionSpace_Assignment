// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "MainWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMainWidgetClosed);

UCLASS()
class UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintAssignable)
	FOnMainWidgetClosed OnClosed;

protected:
#pragma region --- SubWidgets ---
	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> CharacteristicWidget;

	UPROPERTY(meta = (BindWidget))
	UBorder* CharacteristicBorder;

	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> AnalysisWidget;

	UPROPERTY(meta = (BindWidget))
	UBorder* AnalysisBorder;

	// Comparision Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> ComparisionWidget;

	UPROPERTY(meta = (BindWidget))
	UBorder* ComparisionBorder;

	// AIChat Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> AIChatWidget;

	UPROPERTY(meta = (BindWidget))
	UBorder* AIChatBorder;
#pragma endregion

	/* 위젯창 닫기 버튼 */
	UPROPERTY(meta = (BindWidget))
	UButton* closeButton;


	/* 닫기 버튼 클릭 이벤트 */
	UFUNCTION()
	void OnCloseButtonClicked();
};
