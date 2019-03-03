// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.h"

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)	
	{
		UE_LOG(LogTemp, Error, TEXT("AI cant find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller found plaer: %s"), *(ControlledTank->GetName()));
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//	TODO Move towards player

		GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());

		//	TODO Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
