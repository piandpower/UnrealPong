// Fill out your copyright notice in the Description page of Project Settings.

#include "unrealpong.h"
#include "PaddlePawn.h"


// Sets default values
APaddlePawn::APaddlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PaddleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	PaddleCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));	
	
	PaddleMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	PaddleCollider->AttachToComponent(PaddleMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

// Called when the game starts or when spawned
void APaddlePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaddlePawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APaddlePawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("P1Up", this, &APaddlePawn::MoveUp);
	InputComponent->BindAxis("P1Down", this, &APaddlePawn::MoveDown);
}

void APaddlePawn::MoveUp(float value)
{
	FVector ActorLocation = GetActorLocation();
	ActorLocation.X += value * MoveSpeed;
	if (ActorLocation.X > MaxX) {
		ActorLocation.X = MaxX;
	}
	SetActorLocation(ActorLocation);
}

void APaddlePawn::MoveDown(float value)
{
	FVector ActorLocation = GetActorLocation();
	ActorLocation.X -= value * MoveSpeed;

	if (ActorLocation.X < MinX) {
		ActorLocation.X = MinX;
	}
	SetActorLocation(ActorLocation);
}

