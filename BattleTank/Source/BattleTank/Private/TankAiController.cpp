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
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank= Cast<ATank>(GetPawn());
	if (PlayerTank){		
	//TODO Move Towards the player.
	
	//Aim towards the player.
	AITank->AimAt(PlayerTank->GetActorLocation());
	
	//Fire if ready.
	AITank->Fire();
	}
}


