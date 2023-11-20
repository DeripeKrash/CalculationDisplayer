// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UMG/Public/Blueprint/UserWidget.h"

#include "ValueWidget.generated.h"

class UUnitsWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FValueWidgetUpdated, UValueWidget*, valueWidget, float, newValue);

/**
 * 
 */
UCLASS()
class MECANICCALCULATION_API UValueWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(GetOptions="GetUnitNames"))
	FName UnitName {};
	
	FName ParameterName;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UUnitsWidget* UnitsWidget {nullptr};
		
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetValueName(const FText& name);
	virtual void SetValueName_Implementation(const FText& name);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FText GetValueName() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateValue(float value);
	virtual void UpdateValue_Implementation(float value);

	UFUNCTION(BlueprintImplementableEvent)
	void SetValue(float value);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	float GetValue() const;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FValueWidgetUpdated OnValueUpdated;
	
protected:
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetUnitNames();
	
};
