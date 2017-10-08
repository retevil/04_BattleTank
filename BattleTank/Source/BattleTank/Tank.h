// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Tank.generated.h"
class UTankBarrel;
class UTankAimingComponent;
class UTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void SetBarrelReference(UTankBarrel*BarrelToSet);

	UFUNCTION(BlueprintCallable)
		void SetTurretReference(UTurret*TurretToSet);
private:
	UPROPERTY(EditAnywhere, Category="Firing")
	float LaunchSpeed = 10000;
};
