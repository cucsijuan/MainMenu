// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMPUZZLE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	void AddActiveTrigger();
	void RemoveActiveTrigger();

	UPROPERTY(EditAnywhere,Category = "Setup")
	float Speed = 20;
	UPROPERTY(EditAnywhere, Category = "Setup", Meta = (MakeEditWidget = true))
	FVector TargetLocation;
private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	
};
