// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass < UTankAimingComponent>();
	if (!ensure (AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossAir();
}

void ATankPlayerController::AimTowardsCrossAir()
{
	auto PlayerTankAimingComponent = GetPawn()->FindComponentByClass < UTankAimingComponent>();
	if (!ensure(PlayerTankAimingComponent)) { return; }
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) 
	{	
		PlayerTankAimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	//Find the crosshair possition
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Linetrace along that look direction and see what we hit.
		GetLockVectorHitLocation(OutHitLocation, LookDirection);
	}
	
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector &LookDirection)
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		OUT WorldLocation,
		OUT LookDirection
	);
}

bool ATankPlayerController::GetLockVectorHitLocation(FVector& HitLocation, FVector LookDirection)
{	
		FHitResult Hit;	
		auto StartPoint = PlayerCameraManager->GetCameraLocation();
		auto EndPoint = StartPoint+(LookDirection*LineTraceRange);
		
		if (GetWorld()->LineTraceSingleByChannel(
			OUT Hit,
			StartPoint,
			EndPoint,
			ECollisionChannel::ECC_Visibility)
			)
		{
			HitLocation = Hit.Location;
			return true;
		}
		else { HitLocation = FVector(0.f); return false; }
}