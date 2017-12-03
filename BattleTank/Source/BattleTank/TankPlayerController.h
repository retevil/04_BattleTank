// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
class ATank;

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
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	//Con esta UFUNCTION hacemos que esta funcion salga en blueprint como un evento, como por ejemplo BeginPlay()
	//No hace falta implementación.
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingCompRef);
private:
	//En esta funcion pasamos el valor del HitLocation, es decir, donde choca nuestra linea imaginaria a la funcion AimAt de la clase Tank, para poder usarla al apuntar.
	void AimTowardsCrossAir();
	//Esta funcion devuelve el punto donde la mirilla choca con el mundo o otro pawn.
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	//En esta funcion de-proyectamos la posicion del apuntador en la pantalla a una direccion dentro del mundo.
	bool GetLookDirection(FVector2D, FVector & OutHitLocation);
	//Esta funcion traza una linea imaginaria y devuelve la posicion cada vez que esa linea toca algo dentro del canal ECC_Visible.
	bool GetLockVectorHitLocation(FVector &HitLocation, FVector StartPoint);


	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;
	
	//En esta variable damos la distancia que queremos a nuestra linea imaginaria.
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	

};
