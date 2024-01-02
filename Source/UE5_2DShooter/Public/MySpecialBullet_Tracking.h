// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialBullet_Base.h"
#include "MySpecialBullet_Tracking.generated.h"

/**
 * 
 */
UCLASS()
class UE5_2DSHOOTER_API AMySpecialBullet_Tracking : public ASpecialBullet_Base
{
	GENERATED_BODY()

public:
	AMySpecialBullet_Tracking();

protected:
	virtual void BeginPlay() override;

public:
	void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
};
