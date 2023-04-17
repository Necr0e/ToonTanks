// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "PlayerTank.generated.h"

class USpringArmComponent;
class UInputAction;
class UInputMappingContext;


UCLASS()
class TOONTANKS_API APlayerTank : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerTank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> MovementAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> TurnAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> ShootAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputMappingContext> TankMappingContext;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditAnywhere, Category= "Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, Category= "Movement")
	float TurnSpeed;

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;
	
	void TankShoot(const FInputActionValue& Value);
	void MoveForwardBack(const FInputActionValue& Value);
	void TankTurn(const FInputActionValue& Value);
	void TankLook(const FInputActionValue& Value);

	
};
