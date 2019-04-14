// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)	const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
