// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculationPistonData.h"

#include "UObject/UnrealTypePrivate.h"

float UCalculationPistonData::GetRadius() const
{
	return Course / 2.0f;
}

float UCalculationPistonData::GetCalculAngle() const
{
	return FMath::DegreesToRadians(ConnectingRodAngle + 90.f);
}

float UCalculationPistonData::GetCrankRadius() const
{
	return 0.5f * Course;
}

float UCalculationPistonData::GetPistonLocationThroughPMH() const
{
	float radius = GetRadius();
	float calculAngle = GetCalculAngle();
	return (radius + ConnectingRodLength) - (radius * FMath::Sin(calculAngle) +
		(FMath::Sqrt((ConnectingRodLength * ConnectingRodLength) - FMath::Pow(radius, 2) * FMath::Pow(FMath::Cos(calculAngle), 2))));
}

float UCalculationPistonData::GetAveragePistonSpeed() const
{
	return (2.0f * Course * TurnPerMinute) / 60000.0f;
}

float UCalculationPistonData::GetPower() const
{
	return (Course * TurnPerMinute) / 7028.0f;
}

float UCalculationPistonData::GetPistonPosition() const
{
	float crankRadius = GetCrankRadius();
	float delta = crankRadius / ConnectingRodLength;
	
	return ConnectingRodLength * (1 - (FMath::Pow(delta, 2) / 4.0f))
	+ crankRadius * (FMath::Cos(ConnectingRodAngle) + (delta * FMath::Cos(2.0f * delta) / 4.0f));
}
float UCDA_AverageEffectivePressure::GetAverageEffectivePressure() const
{
	return (400.0f * PI * Couple) / (CylinderNb * VolumeDisplaced);
}

float UCDA_AveragePistonSpeed::GetAveragePistonSpeed() const
{
	return (2.0f * Course * TurnPerMinute) / 60000.0f;
}

float UCDA_CylinderCalcul::GetCylinder() const
{
	return Bore * Bore * Course * CylinderNb * (PI / 4.0f / 1000.0f);
}

float UCDA_PistonPower::GetPistonPower() const
{
	return (Couple * TurnPerMinute) / 7028.0f;
}

float UCDA_VolumetricRapport::GetVolumetricFactor() const
{
	return ((CylinderVolume + CylinderHeadGasket) + ChamberVolume) / ChamberVolume;
}

float UCDA_ChamberVolume::GetChamberVolume() const
{
	return (PI * FMath::Pow((Bore / 2.0f), 2.0f) * (Course + CylinderHeadGasket))
	/ (VolumetricFactor - 1.0f);
}

float UCDA_PistonLocationThroughPHM::GetPistonLocationThroughPMH() const
{
	float radius = Course / 2.0f;
	float calculAngle = FMath::DegreesToRadians(ConnectingRodAngle + 90.f);
	return (radius + ConnectingRodLength) - (radius * FMath::Sin(calculAngle) +
		(FMath::Sqrt((ConnectingRodLength * ConnectingRodLength) - FMath::Pow(radius, 2) * FMath::Pow(FMath::Cos(calculAngle), 2))));
}

float UCDA_Couple::GetCouple() const
{
	float connectingRodAngleRad = FMath::DegreesToRadians(ConnectingRodAngle);
	float crankAngleRad = FMath::DegreesToRadians(CrankshaftAngle);

	return ForceApplied * (Course / 2.0f) * FMath::Sin(connectingRodAngleRad + crankAngleRad) / FMath::Cos(crankAngleRad);
}
