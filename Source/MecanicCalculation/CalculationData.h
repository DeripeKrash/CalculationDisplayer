// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "CalculationData.generated.h"

#define IS_INPUT 1
#define IS_OUTPUT 0


UENUM(BlueprintType)
enum ProcessedValueType : uint8
{
	IsInput     UMETA(DisplayName = "IsInput"),
	IsOutput      UMETA(DisplayName = "IsOutput")
};

USTRUCT(BlueprintType)
struct FValueData
{
	GENERATED_BODY()
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName ValueName;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName FunctionName;

	UPROPERTY(VisibleAnywhere)
	FString CategoryName;
	
	UPROPERTY(VisibleAnywhere)
	UFunction* ComputeFunction;
	
	
};

/**
 * 
 */
UCLASS(Abstract)
class MECANICCALCULATION_API UCalculationData : public UDataAsset
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
	FText DataName;

	UPROPERTY(VisibleAnywhere)
	TArray<FValueData> ProcessedValueData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(GetOptions="GetParamsNames"))
	TMap<FName, FText> ParameterDisplayName;

	
public:
	
	UFUNCTION(BlueprintCallable)
	bool UpdateParameter(const FName& parameterName, float newValue);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FValueData> GetProcessedValueData() const;

	UFUNCTION()
	void GetParamValueRef(const FName& paramName, float& outFloat);
	
#if WITH_EDITOR
	UFUNCTION(CallInEditor)
	void GenerateProcessedValueData();
#endif
	
	UFUNCTION(CallInEditor, BlueprintCallable)
	void ComputeAllCalculationParameter();

	UFUNCTION()
	TArray<FName> GetParamsNames() const;
	
	virtual UClass* GetCalculationClass() {return GetClass();};

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetDataName() const {return DataName;};
	
	UFUNCTION(BlueprintCallable)
	FText GetParamDisplayName(const FName& paramName) const;
};
