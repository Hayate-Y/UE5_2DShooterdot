// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialBullet_Base.h"
#include "MySpecialBullet_toBack.generated.h"

/**
 * 
 */
UCLASS()
class UE5_2DSHOOTER_API AMySpecialBullet_toBack : public ASpecialBullet_Base
{
	GENERATED_BODY()

public:
	AMySpecialBullet_toBack();

protected:
	virtual void BeginPlay() override;

private:
	//ÉqÉbÉgä÷êî
	void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	
};
