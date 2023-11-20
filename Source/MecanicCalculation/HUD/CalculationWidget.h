// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UMG/Public/Blueprint/UserWidget.h"

#include "CalculationWidget.generated.h"

class UCanvasPanel;
class UCalculationData;
class UValueWidget;

UCLASS()
class UParameterNameTranslation : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, FText> ParameterName;
	
};

USTRUCT(BlueprintType)
struct FDisplayValueData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly)
	UValueWidget*  SpawnedWidget {nullptr};

	UPROPERTY(BlueprintReadOnly)
	FName ParameterName;

	UPROPERTY(BlueprintReadOnly)
	FText ValueName;
		
};

/**
 * 
 */
UCLASS(Abstract)
class MECANICCALCULATION_API UCalculationWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCalculationData* CalculationData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* InputPanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* OutputPanel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FDisplayValueData> DataValues;
	
public:

	UFUNCTION(BlueprintCallable)
	void CleanDataValues();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetupWidget(UCalculationData* data);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UValueWidget> _DefaultValueWidgetToSpawn {};

	UFUNCTION(BlueprintCallable, CallInEditor)
	void GenerateFromCalculationData(const UCalculationData* data);

	UFUNCTION()
	void OnWidgetValueUpdated(UValueWidget* valueWidget, float newValue);
	
};
