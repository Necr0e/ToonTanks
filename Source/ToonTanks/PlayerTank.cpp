// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "GameFramework/SpringArmComponent.h"

APlayerTank::APlayerTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);
}

