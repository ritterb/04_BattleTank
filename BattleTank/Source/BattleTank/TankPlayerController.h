// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& hitLocation) const;
	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;
	//bool GetLookVectorHitLocation(FVector start, FVector end, FHitResult& outHitResult) const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector& outHitLocation) const;

	UPROPERTY(EditAnywhere)
	float crosshairLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
	float crosshairLocationY = 0.33333f;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000.f; // 10 km
};
