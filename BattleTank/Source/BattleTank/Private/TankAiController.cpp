// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AiTank = GetControlledTank();
	if (!AiTank) { UE_LOG(LogTemp, Error, TEXT("There is not Tank possesed by the AI")); return; }
	UE_LOG(LogTemp, Warning, TEXT("The AI posseses : %s"), *AiTank->GetName())
}

ATank* ATankAiController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}


