// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PC not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PC possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation))	// Has side-effect, is going to ray trace
	{
			//	Tell controlled tank to aim at this point
	}
}

//	Get World location of linetrace through crosshair, if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
