// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	
	//Esta funcion nos devuelve el ATank que esta siendo controlado por la IA.
	ATank* GetControlledTank();
	
	//Esta funcion nos devuelve el ATank que controla el jugador.
	ATank* GetPlayerTank();
	
	void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
