// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_toBack.h"

AMySpecialBullet_toBack::AMySpecialBullet_toBack() 
{
	//Flipbookを設定
	UPaperFlipbook* NewFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(NewFlipbook);

	//Niagara（影）を設定
	UNiagaraSystem* NewNiagara = LoadObject<UNiagaraSystem>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/Bullet_Particle_2.Bullet_Particle_2"), NULL, LOAD_None, NULL);
	Niagara->SetAsset(NewNiagara);

	Capsule->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Block);
}

void AMySpecialBullet_toBack::BeginPlay()
{
	Super::BeginPlay();
}

//ヒット関数を実装
void AMySpecialBullet_toBack::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//ヒットした相手によって処理を分ける
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//プレイヤーならダメージを与える
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_toBack::Destroy();
	}
	else
	{
		//壁ならそのまま破壊
		AMySpecialBullet_toBack::Destroy();
	}
}