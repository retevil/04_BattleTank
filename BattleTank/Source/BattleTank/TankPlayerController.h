// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	ATank* GetControlledTank();
	
	void AimTowardsCrossAir();

	bool GetSightRayHitLocation(FVector &OutHitLocation);

	bool GetLookDirection(FVector2D, FVector & OutHitLocation);

	bool GetLockVectorHitLocation(FVector &HitLocation, FVector StartPoint);

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	

};
