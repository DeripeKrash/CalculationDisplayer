// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UCalculationData;
class UMenuButtonWidget;
class UMenuData;

/**
 * 
 */
UCLASS(Abstract)
class MECANICCALCULATION_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMenuData* MenuData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UMenuButtonWidget> MenuButtonWidgetToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* Panel;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetupPanel(UMenuData* data);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void FillPanel();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnMenuDataSelected(UMenuButtonWidget* buttonWidget, UMenuData* data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCalculationDataSelected(UMenuButtonWidget* buttonWidget, UCalculationData* data);
	
};
