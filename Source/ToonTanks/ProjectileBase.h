// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectileBase();
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	UPROPERTY(EditAnywhere)
	float Damage;

};
