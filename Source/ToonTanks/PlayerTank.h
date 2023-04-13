// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "PlayerTank.generated.h"

class USpringArmComponent;

UCLASS()
class TOONTANKS_API APlayerTank : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerTank();
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	
};
