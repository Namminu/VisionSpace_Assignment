// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "TitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class UTitleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	/* 에디터에서 선택할 디스플레이 위젯 클래스 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> displayWidget;

	/* 새 위젯을 열 버튼 */
	UPROPERTY(meta = (BindWidget))
	UButton* openButton;

	/* 위젯 인스턴스 런타임 보관 */
	UPROPERTY()
	UUserWidget* displayWidgetInstance;

	/* 버튼 클릭 이벤트 */
	UFUNCTION()
	void OnOpenButtonClicked();

	UFUNCTION()
	void HandleDisplayWidgetClosed();
};
