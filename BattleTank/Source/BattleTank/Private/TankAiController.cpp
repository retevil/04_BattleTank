// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITankAimingComponent= GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (ensure(PlayerTank)&& ensure(AITankAimingComponent)){		
	//Move Towards the player.
	MoveToActor(PlayerTank,AcceptanceRadius);
	//Aim towards the player.
	AITankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	//Fire if ready.
	AITankAimingComponent->Fire();
	}
}


