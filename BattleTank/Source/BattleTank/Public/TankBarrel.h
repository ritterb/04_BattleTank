// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Holds barrel's properties 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// relativeSpeed: -1 is max downward movement, +1 is max upward movement
	void Elevate(float relativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 10.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevationDegrees = 0.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevationDegrees = 40.f;
	
};
