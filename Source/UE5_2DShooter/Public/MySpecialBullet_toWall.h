// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialBullet_Base.h"
#include "MySpecialBullet_toWall.generated.h"

/**
 * 
 */
UCLASS()
class UE5_2DSHOOTER_API AMySpecialBullet_toWall : public ASpecialBullet_Base
{
	GENERATED_BODY()

public:
	AMySpecialBullet_toWall();

	//スポーンした場所を保存する変数
	FVector StartLocation;

protected:
	virtual void BeginPlay() override;

private:
	//ヒット関数
	void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
};
