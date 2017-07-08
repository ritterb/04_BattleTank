// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// forward declaration
class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel* barrelToSet);
	void SetTurretReference(UTankTurret* turretToSet);
	
	// TODO: add SetTurretReference

	void AimAt(FVector hitLocation, float launchSpeed);

private:	
	void MoveBarrelTowards(FVector aimDirection);

	UTankBarrel* barrel = nullptr;
	UTankTurret* turret = nullptr;
	
};
