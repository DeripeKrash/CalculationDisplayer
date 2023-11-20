// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MecanicCalculation/CalculationData.h"
#include "UObject/Object.h"

#include "ConversionCalculationData.generated.h"

UCLASS()
class UCDA_KiloWattsToHorsePower : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float KiloWatts_Input {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float HorsePower_Input {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetHorsePowerOutput"))
	float HorsePower_Output {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetKiloWattsOutput"))
	float KiloWatts_Output {0.0f};
	
	UFUNCTION()
	float GetKiloWattsOutput() const;
	
	UFUNCTION()
	float GetHorsePowerOutput() const;
		
};


UCLASS()
class UCDA_TurnMinToRadSec : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float TurnMin_Input {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float RadSec_Input {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetRadSecOutput"))
	float RadSec_Output {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetTurnMinOutput"))
	float TurnMin_Output {0.0f};
	
	UFUNCTION()
	float GetRadSecOutput() const;
	
	UFUNCTION()
	float GetTurnMinOutput() const;
		
};
