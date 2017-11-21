// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	UFUNCTION(BlueprintCallable)
	void IntendTurnRight(float Throw);
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
