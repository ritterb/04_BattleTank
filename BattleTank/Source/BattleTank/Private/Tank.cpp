// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// no need to protect pointers as added at construction
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
	//tankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet) {
	barrel = barrelToSet;
	tankAimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UTankTurret* turretToSet) {
	tankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire() {
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;

	if (barrel && isReloaded) {
		// spawn a projectile at socket location
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(
			projectileBlueprint,
			barrel->GetSocketLocation("Projectile"),
			barrel->GetSocketRotation("Projectile")
			);

		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitLocation) {
	tankAimingComponent->AimAt(hitLocation, launchSpeed);
}