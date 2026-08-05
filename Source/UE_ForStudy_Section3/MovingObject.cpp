// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveObject(DeltaTime);
	RotateObject(DeltaTime);
}

float AMovingObject::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

void AMovingObject::RotateObject(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

void AMovingObject::MoveObject(float DeltaTime)
{
	if(GetDistanceMoved() > MoveDistance)
	{
		FVector MoveDirection = ObjectVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		ObjectVelocity = -ObjectVelocity;
	}
	else
	{
		FVector CurrentActorLocation = GetActorLocation();
		CurrentActorLocation = CurrentActorLocation + ObjectVelocity * DeltaTime;
		SetActorLocation(CurrentActorLocation);
	}
}