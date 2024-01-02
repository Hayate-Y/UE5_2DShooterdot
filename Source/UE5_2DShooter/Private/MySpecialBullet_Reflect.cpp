// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_Reflect.h"

AMySpecialBullet_Reflect::AMySpecialBullet_Reflect()
{

	ProjectileMovement->InitialSpeed = 350.0f;
	ProjectileMovement->MaxSpeed = 350.0f;


	//Flipbookを設定
	UPaperFlipbook* ReflectFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(ReflectFlipbook);

}

void AMySpecialBullet_Reflect::BeginPlay()
{
	Super::BeginPlay();
}

//ヒット関数の実装
void AMySpecialBullet_Reflect::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//ヒットした相手によって処理を分ける
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//プレイヤーならダメージを与える
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_Reflect::Destroy();
	}
	else if (BoundCount < 5) {
		//壁は５回反射する
		BoundCount++;
	}
	else {
		//６回目の衝突で破壊
		AMySpecialBullet_Reflect::Destroy();
	}
}
