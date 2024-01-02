// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_Reflect.h"

AMySpecialBullet_Reflect::AMySpecialBullet_Reflect()
{

	ProjectileMovement->InitialSpeed = 350.0f;
	ProjectileMovement->MaxSpeed = 350.0f;


	//Flipbook��ݒ�
	UPaperFlipbook* ReflectFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(ReflectFlipbook);

}

void AMySpecialBullet_Reflect::BeginPlay()
{
	Super::BeginPlay();
}

//�q�b�g�֐��̎���
void AMySpecialBullet_Reflect::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//�q�b�g��������ɂ���ď����𕪂���
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//�v���C���[�Ȃ�_���[�W��^����
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_Reflect::Destroy();
	}
	else if (BoundCount < 5) {
		//�ǂ͂T�񔽎˂���
		BoundCount++;
	}
	else {
		//�U��ڂ̏Փ˂Ŕj��
		AMySpecialBullet_Reflect::Destroy();
	}
}
