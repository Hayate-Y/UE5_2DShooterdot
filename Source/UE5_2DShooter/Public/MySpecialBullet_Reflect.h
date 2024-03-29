// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialBullet_Base.h"
#include "MySpecialBullet_Reflect.generated.h"

/**
 * 
 */
UCLASS()
class UE5_2DSHOOTER_API AMySpecialBullet_Reflect : public ASpecialBullet_Base
{
	GENERATED_BODY()

public:
	AMySpecialBullet_Reflect();

protected:
	virtual void BeginPlay() override;

private:
	//ヒット関数
	void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

public:
	//壁に衝突した回数
	int BoundCount = 0;


};
 