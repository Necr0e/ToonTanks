// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"


UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	ATower();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	class APlayerTank* Tank;
	UPROPERTY(EditDefaultsOnly, Category= "Combat")
	float FiringRange;
	FTimerHandle FireRateTimerHandle;
	UPROPERTY(EditDefaultsOnly, Category= "Combat")
	float FiringRate;
	void CheckFireCondition();
	bool IsInFiringRange() const;
};

