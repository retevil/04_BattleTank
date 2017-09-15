// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* PlayerTank = GetControlledTank();
	if (!PlayerTank) { UE_LOG(LogTemp, Error, TEXT("There is not Tank controlled by the player")); return; }
	UE_LOG(LogTemp, Warning, TEXT("The player controls : %s"), *PlayerTank->GetName())
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossAir();
}

ATank* ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossAir()
{
	ATank* PlayerTank = GetControlledTank();
	if (!PlayerTank){ UE_LOG(LogTemp, Error, TEXT("There is not Tank controlled by the player")); return; }
}



