// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitsWidget.h"

FString UUnitDataAsset::GetUnitString(const FName& unitName)
{
	FString unitString;
	
	if (UnitsMap.Contains(unitName))
	{
		unitString = UnitsMap[unitName];
	}
	return unitString;
}

TArray<FName> UUnitsWidget::GetUnitNames()
{
	TArray<FName> names;
	if (UUnitDataAsset* ptr = UnitDataAsset.LoadSynchronous())
	{
		ptr->UnitsMap.GetKeys(names);
	}

	return names;
}
