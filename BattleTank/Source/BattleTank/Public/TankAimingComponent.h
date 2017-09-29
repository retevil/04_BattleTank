// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
class UTankBarrel;//Forward Declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//En esta funcion le decimos a los tanques, tanto del jugador como de la IA, donde deben apuntar.
	void AimAt(FVector HitLocation,float LaunchSpeed);
	
	void MoveBarrelTowards(FVector AimDirection);

	void SetBarrelReference(UTankBarrel* BarrelToSet);
private:
	UTankBarrel * Barrel=nullptr;

	
};
