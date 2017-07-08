// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float relativeSpeed) {
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.f, 1.f);

	float rotationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewRotation = RelativeRotation.Yaw + rotationChange;

	SetRelativeRotation(FRotator(0.f, rawNewRotation, 0.f));
}

