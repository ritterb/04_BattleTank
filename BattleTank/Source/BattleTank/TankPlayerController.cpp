// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	

	auto controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing tank: %s"), *controlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Tick %f"), DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}

	FVector hitLocation; // OUT parameter
	if (GetSightRayHitLocation(hitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *hitLocation.ToString());
	}

	
	// get world location of linetrace through crosshair
	// if it hits the landscape
		// tell controlled tank to aim at this point

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {
	FHitResult hitResult;
	FVector start;
	bool bHitActor;
	bHitActor = GetWorld()->GetFirstPlayerController()->ActorLineTraceSingle(hitResult, GetPawn()->GetActorLocation(), hitLocation, ECollisionChannel::ECC_PhysicsBody, FName());
	hitLocation = hitResult.Location;
	return bHitActor;
}