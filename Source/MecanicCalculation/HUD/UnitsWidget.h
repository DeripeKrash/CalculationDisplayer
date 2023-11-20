// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "UMG/Public/Blueprint/UserWidget.h"

#include "UnitsWidget.generated.h"

UCLASS(BlueprintType)
class UUnitDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, FString> UnitsMap;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetUnitString(const FName& unitName);
	
};

/**
 * 
 */
UCLASS()
class MECANICCALCULATION_API UUnitsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(GetOptions="GetUnitNames"))
	FName UnitName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UUnitDataAsset> UnitDataAsset;

public:
	
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetUnitNames();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetUnit(const FName& unit);
	
};
