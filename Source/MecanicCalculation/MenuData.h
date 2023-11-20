// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MenuData.generated.h"

class UCalculationData;

/**
 * 
 */
UCLASS()
class MECANICCALCULATION_API UMenuData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText MenuName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMenuData* Parent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UMenuData*> SubMenus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UCalculationData*> CalculationDatas;

#if WITH_EDITOR
	
	UFUNCTION(CallInEditor)
	void SetupMenuChildren();

#endif
};
