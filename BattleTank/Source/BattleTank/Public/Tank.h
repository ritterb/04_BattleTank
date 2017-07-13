// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // put other includes before this one

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* turretToSet);

	UFUNCTION(BlueprintCallable, Category = Fire)
	void Fire();

protected:
	UTankAimingComponent* tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> projectileBlueprint;	

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float launchSpeed = 4000.f;
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float reloadTimeInSeconds = 3.f;

	UTankBarrel* barrel = nullptr;
	double lastFireTime = 0.f;
};
