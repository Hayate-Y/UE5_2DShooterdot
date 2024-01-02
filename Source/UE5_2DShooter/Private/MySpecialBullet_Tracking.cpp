// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_Tracking.h"
#include "Kismet/KismetMathLibrary.h"

AMySpecialBullet_Tracking::AMySpecialBullet_Tracking()
{
	UPaperFlipbook* NewFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullettuiseki1.SpecialBullettuiseki1"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(NewFlipbook);

	//NiagaraÅiâeÅjÇê›íË
	UNiagaraSystem* NewNiagara = LoadObject<UNiagaraSystem>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/Bullet_Particle_Tuiseki.Bullet_Particle_Tuiseki"), NULL, LOAD_None, NULL);
	Niagara->SetAsset(NewNiagara);
}

void AMySpecialBullet_Tracking::BeginPlay()
{
	Super::BeginPlay();
}

void AMySpecialBullet_Tracking::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_Tracking::Destroy();
	}
	else {
		FVector BreakPoint = this->GetActorLocation();
		AMySpecialBullet_Tracking::Destroy();
		ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0);
		FVector PlayerPoint = PlayerCharacter->GetActorLocation();
		FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(BreakPoint, PlayerPoint);
		GetWorld()->SpawnActor<AMySpecialBullet_Tracking>(AMySpecialBullet_Tracking::StaticClass(), BreakPoint, Rotator);

	}
}