// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

APlayerTank::APlayerTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);

	MoveSpeed = 200.f;
}

void APlayerTank::BeginPlay()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			Subsystem->AddMappingContext(TankMappingContext, 0);
}

void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	if (UEnhancedInputComponent* PIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MovementAction)
		{
			PIC->BindAction(MovementAction, ETriggerEvent::Triggered, this, &APlayerTank::MoveForwardBack);
		}
	}
}

void APlayerTank::MoveForwardBack(const FInputActionValue& Value)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value.Get<float>() * MoveSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation);
}

void APlayerTank::TankLook(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Move Forward"));
}

void APlayerTank::TankTurn(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Turn"));
}

void APlayerTank::TankShoot(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("PEW!"));
}


