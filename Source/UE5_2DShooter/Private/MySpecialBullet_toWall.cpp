// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpecialBullet_toWall.h"
#include "Kismet/KismetMathLibrary.h"
#include "MySpecialBullet_toBack.h"

AMySpecialBullet_toWall::AMySpecialBullet_toWall()
{
	//Flipbook��ݒ�
	UPaperFlipbook* NewFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/SpecialBullet2_4.SpecialBullet2_4"), NULL, LOAD_None, NULL);
	PaperFlipbook->SetFlipbook(NewFlipbook);

	//Niagara�i�e�j��ݒ�
	UNiagaraSystem* NewNiagara = LoadObject<UNiagaraSystem>(NULL, TEXT("/Game/UE5_2DShooter/Enemy/Enemy-Nature/Bullet_Particle.Bullet_Particle"), NULL, LOAD_None, NULL);
	Niagara->SetAsset(NewNiagara);
}

void AMySpecialBullet_toWall::BeginPlay()
{
	Super::BeginPlay();

	//�X�|�[�������ꏊ��ۑ�
	StartLocation = GetActorLocation();

}

//�q�b�g�֐�������
void AMySpecialBullet_toWall::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//�f�o�b�N�p
	//UKismetSystemLibrary::PrintString(this, UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0)->GetName(), true, true, FColor::Cyan, 2.f, TEXT("None"));
	//UKismetSystemLibrary::PrintString(this, OtherActor->GetName(), true, true, FColor::Cyan, 2.f, TEXT("None"));

	//�q�b�g��������ɂ���ď����𕪂���
	if (UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0) == OtherActor)
	{
		//Player�������ꍇ�A�_���[�W��^���Ĕj��
		OtherActor->TakeDamage(0.25f, FDamageEvent(), GetInstigatorController(), this);
		AMySpecialBullet_toWall::Destroy();
	}else
	{
		//�ǂ������ꍇ�A���˗p�̒e���X�|�[��
		FVector BreakPoint = this->GetActorLocation();
		AMySpecialBullet_toWall::Destroy();
		FRotator Rotator=UKismetMathLibrary::FindLookAtRotation(BreakPoint,StartLocation);
		GetWorld()->SpawnActor<AMySpecialBullet_toBack>(AMySpecialBullet_toBack::StaticClass(), BreakPoint , Rotator);

	}
}

