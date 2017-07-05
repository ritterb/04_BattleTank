// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	auto playerTank = GetPlayerTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController not possessing a tank"));
	}
	/*else {
		UE_LOG(LogTemp, Warning, TEXT("%s possessing tank: %s"), *GetName(), *controlledTank->GetName());
	}*/
	if (!playerTank) {
		UE_LOG(LogTemp, Error, TEXT("%s could not find PlayerController possessed tank"), *GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s found PlayerController tank: %s"), *GetName(), *playerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto controlledTank = GetControlledTank();
	if (!controlledTank) { return; }

	FVector playerLocation = GetPlayerTank()->GetActorLocation();
	controlledTank->AimAt(playerLocation);

	// TODO: move towards player

	// TODO: fire if ready
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	APawn* playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerTank) {
		return nullptr;
	}
	return Cast<ATank>(playerTank);
}
