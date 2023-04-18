// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "PlayerTank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	FiringRange = 1000.f;
	FiringRate = 2.f;
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FiringRate, true);
}
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsInFiringRange())
		RotateTurret(Tank->GetActorLocation());

}

void ATower::CheckFireCondition()
{
	if (IsInFiringRange())
		Fire();
}

bool ATower::IsInFiringRange() const
{
	if (Tank)
	{
		float DistanceToTarget = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (DistanceToTarget <= FiringRange)
			return true;
	}
	return false;
}

