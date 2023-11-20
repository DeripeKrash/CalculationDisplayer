// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculationWidget.h"

#include "ValueWidget.h"
#include "Components/CanvasPanel.h"
#include "MecanicCalculation/CalculationData.h"

void UCalculationWidget::CleanDataValues()
{
	for (int i = 0; i < DataValues.Num(); i++)
	{
		DataValues[i].SpawnedWidget->RemoveFromParent();
	}

	DataValues.Empty();
	OutputPanel->ClearChildren();
	InputPanel->ClearChildren();
}

void UCalculationWidget::SetupWidget_Implementation(UCalculationData* data)
{
	CalculationData = data;
	GenerateFromCalculationData(CalculationData);
}

void UCalculationWidget::GenerateFromCalculationData(const UCalculationData* data)
{
	if (!IsValid(data) || !IsValid(InputPanel) || !IsValid(OutputPanel))
	{
		return;
	}

	CleanDataValues();

	TArray<FValueData> processed = CalculationData->GetProcessedValueData();
	
	for (int i = 0; i < processed.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *processed[i].ValueName.ToString());
				

		FDisplayValueData valueData;
			
		valueData.ParameterName = processed[i].ValueName;
		valueData.SpawnedWidget = CreateWidget<UValueWidget>(this, _DefaultValueWidgetToSpawn.Get());
		valueData.SpawnedWidget->ParameterName = valueData.ParameterName;

		if (processed[i].ComputeFunction)
		{
			OutputPanel->AddChild(valueData.SpawnedWidget);
		}
		else
		{
			InputPanel->AddChild(valueData.SpawnedWidget);
		}
		valueData.ValueName = CalculationData->GetParamDisplayName(valueData.ParameterName);
			
		if (IsValid(valueData.SpawnedWidget))
		{
			valueData.SpawnedWidget->OnValueUpdated.AddUniqueDynamic(this, &UCalculationWidget::OnWidgetValueUpdated);
			valueData.SpawnedWidget->SetValueName(valueData.ValueName);
			float value;
			CalculationData->GetParamValueRef(FName(valueData.ValueName.ToString()), value);
			valueData.SpawnedWidget->UpdateValue(value);
		}
			
		DataValues.Add(valueData);
		
	}
}

void UCalculationWidget::OnWidgetValueUpdated(UValueWidget* valueWidget, float newValue)
{
	for (int i = 0; i < DataValues.Num(); i++)
	{
		if (DataValues[i].SpawnedWidget == valueWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("Widget Updated : %s"), *valueWidget->ParameterName.ToString())
			CalculationData->UpdateParameter(DataValues[i].ParameterName, newValue);

			
		}
	}
	
	for (int i = 0; i < DataValues.Num(); i++)
	{

		UE_LOG(LogTemp, Warning, TEXT("Widget Updated : %s"), *valueWidget->ParameterName.ToString())
		float value;
		CalculationData->GetParamValueRef(DataValues[i].ParameterName, value);
		DataValues[i].SpawnedWidget->SetValue(value);

	}
}
