// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	ATank* controlledTank = Cast<ATank>(GetPawn());
	if (!controlledTank) { return; }
	
	ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!playerTank) { return; }

	// aim at player
	controlledTank->AimAt(playerTank->GetActorLocation());

	// TODO: move towards player

	// TODO: only fire if ready
	controlledTank->Fire();
}
