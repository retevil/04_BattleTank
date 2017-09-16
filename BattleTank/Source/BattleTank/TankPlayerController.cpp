// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	//Las siguientes lineas crean un puntero hacia el tanque que controla el jugador y luego comprobamos
	//que verdaderamente el jugador controla un tanque.
	ATank* PlayerTank = GetControlledTank();
	if (!PlayerTank) { UE_LOG(LogTemp, Error, TEXT("There is not Tank controlled by the player")); return; }
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossAir();
}

ATank* ATankPlayerController::GetControlledTank()
{
	//Aqui casteamos el componente tank del player controller y devolvemos el pawn del mismo.
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossAir()
{

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) 
	{	
		UE_LOG(LogTemp, Warning, TEXT("is hitting %s"), *HitLocation.ToString());
		//A hacer, decir al tanque que apunte a esta localizacion.
	}
}
//Esta funcion devuelve el punto donde la mirilla choca con el mundo o otro pawn.
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

//De-project the screen position of the cursor to a world direction.
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