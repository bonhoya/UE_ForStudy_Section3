// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class UE_FORSTUDY_SECTION3_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnyWhere, Category = "Moving")
	FVector ObjectVelocity = FVector(0, 0, 0);
	UPROPERTY(EditAnyWhere, Category = "Moving")
	float MoveDistance = 0;

	UPROPERTY(EditAnyWhere, Category = "Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	float GetDistanceMoved() const;

	void RotateObject(float DeltaTime);
	void MoveObject(float DeltaTime);
};
