// Copyright Leven Games

#include "SprungWheel.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodySpringConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Body Spring Constraint"));
	SetRootComponent(BodySpringConstraint);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(BodySpringConstraint);

	WheelAxleConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Wheel Axle Constraint"));
	WheelAxleConstraint->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraints();
}

void ASprungWheel::SetupConstraints()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent * BodyRoot = Cast< UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	BodySpringConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);

	WheelAxleConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);

}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{
	Wheel->AddForce(Axle->GetForwardVector() * ForceMagnitude);
}

