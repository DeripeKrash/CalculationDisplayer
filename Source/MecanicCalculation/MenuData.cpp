// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuData.h"

#include "CalculationData.h"

#if WITH_EDITOR

void UMenuData::SetupMenuChildren()
{
	for (int i = 0; i < SubMenus.Num(); i++)
	{
		SubMenus[i]->Parent = this;
		SubMenus[i]->SetupMenuChildren();
	}

	for (int i = 0; i < CalculationDatas.Num(); i++)
	{
		CalculationDatas[i]->GenerateProcessedValueData();
	}
	
	Modify();
}

#endif