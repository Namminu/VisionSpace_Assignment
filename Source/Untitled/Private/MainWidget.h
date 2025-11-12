// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
	/* 위젯창 닫기 버튼 */
	UPROPERTY(meta = (BindWidget))
	UButton* closeButton;


	/* 닫기 버튼 클릭 이벤트 */
	UFUNCTION()
	void OnCloseButtonClicked();
};
