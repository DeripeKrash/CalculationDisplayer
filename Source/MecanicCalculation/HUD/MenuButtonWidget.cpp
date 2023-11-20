// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuButtonWidget.h"

void UMenuButtonWidget::SetupFromMenuData_Implementation(UMenuData* data)
{
	MenuData = data;
	CalculationData = nullptr;
}

void UMenuButtonWidget::SetupFromCalculationData_Implementation(UCalculationData* data)
{
	MenuData = nullptr;
	CalculationData = data;
}

void UMenuButtonWidget::OnButtonSelected_Implementation()
{
	if (CalculationData)
	{
		OnSelected_CalculationData.Broadcast(this, CalculationData);
	}
	else if(MenuData)
	{
		OnSelected_MenuData.Broadcast(this, MenuData);
	}
}
