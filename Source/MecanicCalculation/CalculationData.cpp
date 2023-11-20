// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculationData.h"

#define CHECK_TRUE_OR_RETURN_FALSE(...) if (!__VA_ARGS__) return false;

bool UCalculationData::UpdateParameter(const FName& parameterName, float newValue)
{
	FProperty* prop = GetCalculationClass()->FindPropertyByName(parameterName);
	CHECK_TRUE_OR_RETURN_FALSE(prop);

	FFloatProperty* fltProp = CastField<FFloatProperty>(prop);
	CHECK_TRUE_OR_RETURN_FALSE(fltProp);

	float* propPtr = fltProp->ContainerPtrToValuePtr<float>(this);
	*propPtr = newValue;
	CHECK_TRUE_OR_RETURN_FALSE(propPtr);


	ComputeAllCalculationParameter();
	
	return true;
}

TArray<FValueData> UCalculationData::GetProcessedValueData() const
{
	return ProcessedValueData;
}

void UCalculationData::GetParamValueRef(const FName& paramName, float& outValue)
{
	for (int i = 0; i < ProcessedValueData.Num(); i++)
	{
		if (ProcessedValueData[i].ValueName == paramName)
		{
			FProperty* prop = GetCalculationClass()->FindPropertyByName(paramName);
			FFloatProperty* fltProp = CastField<FFloatProperty>(prop);

			if (!fltProp)
				return;
			
			const float* propPtr = fltProp->ContainerPtrToValuePtr<float>(this);

			outValue = *propPtr;
		}
	}
}


#if WITH_EDITOR

void UCalculationData::GenerateProcessedValueData()
{
	ProcessedValueData.Empty();
	
	for (TFieldIterator<FFloatProperty> prop(GetCalculationClass()); prop; ++prop)
	{
		bool validParam = false;
		FValueData valueData;
		
		if (prop->HasMetaData(TEXT("ProcessedValue")))
		{
			valueData.ValueName = FName(prop->GetName());
			validParam = true;
		}
		
		if (prop->FindMetaData("CalculationFunction"))
		{
			FName name = *prop->GetMetaDataText("CalculationFunction").ToString();
			UFunction* function = FindFunction(name);
						
			UE_LOG(LogTemp, Warning, TEXT("%s => %s : %d"),
				*prop->GetName(),
				*prop->GetMetaDataText("CalculationFunction").ToString(),
				IsValid(FindFunction(name)));
		
			if (IsValid(function))
			{
				valueData.ValueName = FName(prop->GetName());
				valueData.FunctionName = name;
				valueData.ComputeFunction = function;
				validParam = true;
			}
		}
		
		if (prop->HasMetaData(TEXT("Category")))
		{
			valueData.CategoryName = prop->GetMetaData(TEXT("Category"));
		}
		if (validParam)
		{
			ProcessedValueData.Add(valueData);
			Modify();
		}
		
	}
}

#endif

void UCalculationData::ComputeAllCalculationParameter()
{
	for (int i = 0; i < ProcessedValueData.Num(); i++)
	{
		FProperty* prop = GetCalculationClass()->FindPropertyByName(ProcessedValueData[i].ValueName);

		if (ProcessedValueData[i].ComputeFunction)
		{
			FFrame stack(this, ProcessedValueData[i].ComputeFunction, nullptr, nullptr, ProcessedValueData[i].ComputeFunction->ChildProperties);
			float result;
			ProcessedValueData[i].ComputeFunction->Invoke(this, stack, &result);
		
			UE_LOG(LogTemp, Warning, TEXT("result = %f"), result);
			float* value = prop->ContainerPtrToValuePtr<float>(this);
			*value = result;
		}
	}
	
}

TArray<FName> UCalculationData::GetParamsNames() const
{
	TArray<FName> param;
	for (int i = 0; i < ProcessedValueData.Num(); i++)
	{
		param.Add(ProcessedValueData[i].ValueName);
	}
	return param;
}

FText UCalculationData::GetParamDisplayName(const FName& paramName) const
{
	if (ParameterDisplayName.Contains(paramName))
	{
		return ParameterDisplayName[paramName];
	}
	return FText::FromName(paramName);
}
