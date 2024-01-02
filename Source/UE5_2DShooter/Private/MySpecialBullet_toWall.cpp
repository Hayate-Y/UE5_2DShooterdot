// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_toWall.h"
#include "Kismet/KismetMathLibrary.h"
#include "MySpecialBullet_toBack.h"

AMySpecialBullet_toWall::AMySpecialBullet_toWall()
{
	//Flipbookを設定
	UPaperFlipbook* NewFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(NewFlipbook);

	//Niagara（影）を設定
	UNiagaraSystem* NewNiagara = LoadObject<UNiagaraSystem>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/Bullet_Particle.Bullet_Particle"), NULL, LOAD_None, NULL);
	Niagara->SetAsset(NewNiagara);
}

void AMySpecialBullet_toWall::BeginPlay()
{
	Super::BeginPlay();

	//スポーンした場所を保存
	StartLocation = GetActorLocation();

}

//ヒット関数を実装
void AMySpecialBullet_toWall::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//デバック用
	//UKismetSystemLibrary::PrintString(this, UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0)->GetName(), true, true, FColor::Cyan, 2.f, TEXT("None"));
	//UKismetSystemLibrary::PrintString(this, OtherActor->GetName(), true, true, FColor::Cyan, 2.f, TEXT("None"));

	//ヒットした相手によって処理を分ける
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//Playerだった場合、ダメージを与えて破壊
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_toWall::Destroy();
	}else
	{
		//壁だった場合、反射用の弾をスポーン
		FVector BreakPoint = this->GetActorLocation();
		AMySpecialBullet_toWall::Destroy();
		FRotator Rotator=UKismetMathLibrary::FindLookAtRotation(BreakPoint,StartLocation);
		GetWorld()->SpawnActor<AMySpecialBullet_toBack>(AMySpecialBullet_toBack::StaticClass(), BreakPoint , Rotator);

	}
}

