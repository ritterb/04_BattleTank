// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float relativeSpeed) {
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.f, 1.f);

	// move the barrel the right amount this frame
	// give a max elevation speed, and the frame time
	float elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewElevation = RelativeRotation.Pitch + elevationChange;
	float newElevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(newElevation, 0.f, 0.f));

}