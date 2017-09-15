// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AiTank = GetControlledTank();
	if (!AiTank) { UE_LOG(LogTemp, Error, TEXT("There is not Tank possesed by the AI")); return; }
	UE_LOG(LogTemp, Warning, TEXT("The AI posseses : %s"), *AiTank->GetName())

	ATank* FoundPlayerController = GetPlayerTank();
	if (!FoundPlayerController){ UE_LOG(LogTemp, Error, TEXT("There is not PlayerController found by the AI")); return; }
	UE_LOG(LogTemp, Warning, TEXT("The AI has found the PlayerController in: %s"), *FoundPlayerController->GetName())

}

ATank* ATankAiController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank()
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

