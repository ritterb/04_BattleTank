// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet) {
	if (!leftTrackToSet || !rightTrackToSet) { return; }
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	UE_LOG(LogTemp, Warning, TEXT("%f: IntendMoveForward %f"), GetWorld()->GetTimeSeconds(), Throw);
	
	// Apply the same force to the left and right tracks
	leftTrack->SetThrottle(Throw);
	rightTrack->SetThrottle(Throw);
	// TODO: prevent double-speed due to using both left stick and gamepad triggers at the same time
}
