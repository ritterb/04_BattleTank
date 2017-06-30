// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UStaticMeshComponent* barrelToSet);
	
	// TODO: add SetTurretReference

	void AimAt(FVector hitLocation, float launchSpeed);

private:	
	void MoveBarrelTowards(FVector aimDirection);

	UStaticMeshComponent* barrel = nullptr;
	
};
