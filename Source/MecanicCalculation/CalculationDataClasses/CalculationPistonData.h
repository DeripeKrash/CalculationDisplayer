// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MecanicCalculation/CalculationData.h"
#include "CalculationPistonData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MECANICCALCULATION_API UCalculationPistonData : public UCalculationData
{
	GENERATED_BODY()

public:
		
	// Alesage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float Bore {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float Course {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float ConnectingRodLength {0.0f}; // Longueur de Bielle
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float ConnectingRodAngle {0.0f}; // Angle de Bielle

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float TurnPerMinute {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float averagePistonSpeed {0.0f};
		
	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_OUTPUT, CalculationFunction="GetPistonLocationThroughPMH"))
	float PistonLocationThroughPHM {0.0f};

	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_OUTPUT, CalculationFunction="GetPistonPosition"))
	float PistonLocation {0.0f};

	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_OUTPUT, CalculationFunction="GetPower"))
	float Power {0.0f};
	
	UFUNCTION(BlueprintCallable)
	float GetRadius() const;

	UFUNCTION(BlueprintCallable)
	float GetCalculAngle() const;

	UFUNCTION(BlueprintCallable)
	float GetCrankRadius() const; // Rayon de maneton
	
	UFUNCTION(BlueprintCallable)
	float GetPistonLocationThroughPMH() const;

	UFUNCTION(BlueprintCallable)
	float GetAveragePistonSpeed() const;

	UFUNCTION(BlueprintCallable)
	float GetPower() const;

	UFUNCTION(BlueprintCallable)
	float GetPistonPosition() const;
	
	virtual UClass* GetCalculationClass() override {return UCalculationPistonData::StaticClass();};
};


UCLASS()
class UCDA_AverageEffectivePressure : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Couple {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CylinderNb {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float VolumeDisplaced {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetAverageEffectivePressure"))
	float AverageEffectivePressure {0.0f};
	
	UFUNCTION()
	float GetAverageEffectivePressure() const;
};

UCLASS()
class UCDA_AveragePistonSpeed : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Course {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float TurnPerMinute {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetAveragePistonSpeed"))
	float AveragePistonSpeed {0.0f};
	
	UFUNCTION()
	float GetAveragePistonSpeed() const;
};

UCLASS()
class UCDA_CylinderCalcul : public UCalculationData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Bore {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Course {0.0f};
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CylinderNb {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetCylinder"))
	float Cylinder {0.0f};
	
	UFUNCTION()
	float GetCylinder() const;
};

UCLASS()
class UCDA_PistonPower : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Couple {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float TurnPerMinute {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetPistonPower"))
	float Power {0.0f};
	
	UFUNCTION()
	float GetPistonPower() const;
};

UCLASS()
class UCDA_VolumetricRapport : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CylinderVolume {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CylinderHeadGasket {0.0f};	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float ChamberVolume {0.0f};	
	
	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_INPUT, CalculationFunction="GetVolumetricFactor"))
	float VolumetricFactor {0.0f};

	UFUNCTION(BlueprintCallable)
	float GetVolumetricFactor() const;
};

UCLASS()
class UCDA_ChamberVolume : public UCalculationData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Bore {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Course {0.0f};
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CylinderHeadGasket {0.0f};	

	UPROPERTY(EditAnywhere, meta=(ProcessedValue))
	float VolumetricFactor {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue, CalculationFunction="GetChamberVolume"))
	float ChamberVolume {0.0f};	
	
	UFUNCTION(BlueprintCallable)
	float GetChamberVolume() const;
};

UCLASS(BlueprintType)
class MECANICCALCULATION_API UCDA_PistonLocationThroughPHM : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float Course {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float ConnectingRodLength {0.0f}; // Longueur de Bielle
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue=IS_INPUT))
	float ConnectingRodAngle {0.0f}; // Angle de Bielle
	
	
	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_OUTPUT, CalculationFunction="GetPistonLocationThroughPMH"))
	float PistonLocationThroughPHM {0.0f};
	
	UFUNCTION(BlueprintCallable)
	float GetPistonLocationThroughPMH() const;
	
	
};

UCLASS()
class UCDA_Couple : public UCalculationData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float ForceApplied {0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float Course {0.0f};	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float ConnectingRodAngle {0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ProcessedValue))
	float CrankshaftAngle {0.0f};
	
	UPROPERTY(VisibleAnywhere, meta=(ProcessedValue=IS_INPUT, CalculationFunction="GetCouple"))
	float Couple {0.0f};

	UFUNCTION(BlueprintCallable)
	float GetCouple() const;
};