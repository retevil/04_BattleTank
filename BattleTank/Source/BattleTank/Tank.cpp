// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("51531237:Tank_C++_Constructor"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("51531237:Tank_C++_BeginPlay"));
	
}

void ATank::Fire()
{	
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded) 
	{
		auto ProjectileSpawnPoint = Barrel->GetSocketLocation(FName("Projectile"));
		auto ProjectileSpawnRotator = Barrel->GetSocketRotation(FName("Projectile"));
		//Spawn a projectile at the socket location on the barrel.
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileSpawnPoint, ProjectileSpawnRotator);
	
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	else {  return; }
}

void ATank::AimAt(FVector HitLocation)
{
	if (!FindComponentByClass<UTankAimingComponent>()) { return; }
	FindComponentByClass<UTankAimingComponent>()->AimAt(HitLocation,LaunchSpeed);

}