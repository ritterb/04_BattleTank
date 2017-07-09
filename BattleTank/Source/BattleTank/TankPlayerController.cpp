// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Public/Tank.h"


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

	FVector hitLocation; // out parameter
	if (GetSightRayHitLocation(hitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *hitLocation.ToString());
		// tell controlled tank to aim at this location
		GetControlledTank()->AimAt(hitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {

	// find the crosshair position in pixel coordinates
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(
		viewportSizeX * crosshairLocationX,
		viewportSizeY * crosshairLocationY
	);

	// de-project the screen position of the crosshair to a world direction
	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection)) {

		// line-trace along that look direction, and see what we hit (up to max range)
		bool bGotHit = GetLookVectorHitLocation(lookDirection, hitLocation);
		if (bGotHit) {
			return true;
		}
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const {
	FVector worldLocation; // temp variable, discarded
	return DeprojectScreenPositionToWorld(
		screenLocation.X,
		screenLocation.Y,
		worldLocation,
		lookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& outHitLocation) const {
	FHitResult hitResult;
	FVector start = PlayerCameraManager->GetCameraLocation();
	bool bGotHit = GetWorld()->LineTraceSingleByChannel(
		hitResult,
		start,
		start + (lookDirection * lineTraceRange),
		ECollisionChannel::ECC_Visibility
	);
	if (bGotHit) {
		outHitLocation = hitResult.Location;
	}
	else {
		outHitLocation = FVector(0);
	}
	return bGotHit;
}