// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/Object.h"
#include "MenuButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMenuButtonWidgetUpdated_MenuData, UMenuButtonWidget*, buttonWidget, UMenuData*, menuData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMenuButtonWidgetUpdated_UCalculationData, UMenuButtonWidget*, buttonWidget, UCalculationData*, calculationData);

class UMenuData;
class UCalculationData;

/**
 * 
 */
UCLASS(Abstract)
class MECANICCALCULATION_API UMenuButtonWidget : public UUserWidget
{	
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMenuData* MenuData {nullptr};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCalculationData* CalculationData {nullptr};
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FMenuButtonWidgetUpdated_MenuData OnSelected_MenuData;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FMenuButtonWidgetUpdated_UCalculationData OnSelected_CalculationData;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetupFromMenuData(UMenuData* data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetupFromCalculationData(UCalculationData* data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnButtonSelected();
};
