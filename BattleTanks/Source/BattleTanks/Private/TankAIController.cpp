// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();	// Gets the Players Tank
	auto ControlledTank = GetPawn();										// Gets the AI tank

	if (!ensure(PlayerTank) && ControlledTank) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetTargetLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); // Dont fire Every Frame
	}
}

