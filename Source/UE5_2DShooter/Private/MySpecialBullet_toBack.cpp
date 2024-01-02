// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_toBack.h"

AMySpecialBullet_toBack::AMySpecialBullet_toBack() 
{
	//Flipbook��ݒ�
	UPaperFlipbook* NewFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(NewFlipbook);

	//Niagara�i�e�j��ݒ�
	UNiagaraSystem* NewNiagara = LoadObject<UNiagaraSystem>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/Bullet_Particle_2.Bullet_Particle_2"), NULL, LOAD_None, NULL);
	Niagara->SetAsset(NewNiagara);

	Capsule->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Block);
}

void AMySpecialBullet_toBack::BeginPlay()
{
	Super::BeginPlay();
}

//�q�b�g�֐�������
void AMySpecialBullet_toBack::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//�q�b�g��������ɂ���ď����𕪂���
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//�v���C���[�Ȃ�_���[�W��^����
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_toBack::Destroy();
	}
	else
	{
		//�ǂȂ炻�̂܂ܔj��
		AMySpecialBullet_toBack::Destroy();
	}
}