// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PaddlePawn.generated.h"

UCLASS()
class UNREALPONG_API APaddlePawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent *PaddleMeshComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UBoxComponent *PaddleCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MinX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 5;

	// Sets default values for this pawn's properties
	APaddlePawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:

	void MoveUp(float value);
	void MoveDown(float value);
	
};
