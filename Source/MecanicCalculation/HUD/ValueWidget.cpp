// Fill out your copyright notice in the Description page of Project Settings.


#include "ValueWidget.h"

#include "UnitsWidget.h"


void UValueWidget::SetValueName_Implementation(const FText& name)
{
}

void UValueWidget::UpdateValue_Implementation(float value)
{
	SetValue(value);
	OnValueUpdated.Broadcast(this, value);
}

TArray<FName> UValueWidget::GetUnitNames()
{
	if (IsValid(UnitsWidget))
	{
		return UnitsWidget->GetUnitNames();
	}
	return {};
}
