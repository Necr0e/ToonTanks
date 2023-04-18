
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
	TurnSpeed = 20.f;
}

void APlayerTank::BeginPlay()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			Subsystem->AddMappingContext(TankMappingContext, 0);

	
}

void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
		if (TurnAction)
		{
			PIC->BindAction(TurnAction, ETriggerEvent::Triggered, this, &APlayerTank::TankTurn);
		}
		if (LookAction)
		{
			PIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerTank::TankLook);
		}
		if (ShootAction)
		{
			PIC->BindAction(ShootAction, ETriggerEvent::Completed, this, &APlayerTank::TankShoot);
		}
	}
}

void APlayerTank::MoveForwardBack(const FInputActionValue& Value)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value.Get<float>() * MoveSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
}

void APlayerTank::TankLook(const FInputActionValue& Value)
{
	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	RotateTurret(HitResult.ImpactPoint);
}

void APlayerTank::TankTurn(const FInputActionValue& Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = Value.Get<float>() * TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}

void APlayerTank::TankShoot(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("PEW!"));
	Fire();
}


