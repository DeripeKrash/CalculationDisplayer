// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "MenuButtonWidget.h"
#include "Components/PanelWidget.h"
#include "MecanicCalculation/MenuData.h"

void UMenuWidget::FillPanel_Implementation()
{
	Panel->ClearChildren();

	if (!IsValid(MenuData))
	{
		return;
	}
	
	for (int i = 0; i < MenuData->SubMenus.Num(); i++)
	{
		UMenuButtonWidget* spawnedWidget = CreateWidget<UMenuButtonWidget>(this, MenuButtonWidgetToSpawn.Get());

		if (!spawnedWidget)
		{
			return;
		}
		
		spawnedWidget->SetupFromMenuData(MenuData->SubMenus[i]);
		spawnedWidget->OnSelected_MenuData.AddUniqueDynamic(this, &UMenuWidget::OnMenuDataSelected);
		Panel->AddChild(spawnedWidget);
	}

	for (int i = 0; i < MenuData->CalculationDatas.Num(); i++)
	{
		UMenuButtonWidget* spawnedWidget = CreateWidget<UMenuButtonWidget>(this, MenuButtonWidgetToSpawn.Get());

		if (!spawnedWidget)
		{
			return;
		}
		
		spawnedWidget->SetupFromCalculationData(MenuData->CalculationDatas[i]);
		spawnedWidget->OnSelected_CalculationData.AddUniqueDynamic(this, &UMenuWidget::OnCalculationDataSelected);
		Panel->AddChild(spawnedWidget);
	}
}

void UMenuWidget::OnMenuDataSelected_Implementation(UMenuButtonWidget* buttonWidget, UMenuData* data)
{
}

void UMenuWidget::OnCalculationDataSelected_Implementation(UMenuButtonWidget* buttonWidget, UCalculationData* data)
{
}

void UMenuWidget::SetupPanel_Implementation(UMenuData* data)
{
	MenuData = data;
	FillPanel();
}
