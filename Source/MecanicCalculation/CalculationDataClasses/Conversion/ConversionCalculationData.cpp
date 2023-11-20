// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversionCalculationData.h"

float UCDA_KiloWattsToHorsePower::GetHorsePowerOutput() const
{
	return KiloWatts_Input * 1.36f;
}

float UCDA_KiloWattsToHorsePower::GetKiloWattsOutput() const
{
	return HorsePower_Input * 0.74f;
}

float UCDA_TurnMinToRadSec::GetRadSecOutput() const
{
	return ((2.0f * PI) / 60.0f) * TurnMin_Input;
}

float UCDA_TurnMinToRadSec::GetTurnMinOutput() const
{
	return (60.0f / (2.0f * PI)) * RadSec_Input;
}