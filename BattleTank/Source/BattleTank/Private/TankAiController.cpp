// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankAimingComponent.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()){
	//TODO Move Towards the player.
	
	//Aim towards the player.
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	//Fire if ready.
	}
}


ATank* ATankAiController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank()
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

