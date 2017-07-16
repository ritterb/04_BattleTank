// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);

private:
	virtual void BeginPlay() override;
	
	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float trackMaxDrivingForce = 200000.f; // 40 metric ton tank at 0.5g acceleration

};
