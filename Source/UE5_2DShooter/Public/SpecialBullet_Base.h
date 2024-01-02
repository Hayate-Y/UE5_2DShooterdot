
#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"

#include "PaperCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperFlipbook.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


#include "SpecialBullet_Base.generated.h"

UCLASS()
class UE5_2DSHOOTER_API ASpecialBullet_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	//�R���X�g���N�^
	ASpecialBullet_Base();

protected:
	// �J�n���ɌĂ΂��֐�
	virtual void BeginPlay() override;

public:
	//�q�b�g�������̊֐�
	UFUNCTION()
		virtual void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) ;


	// �}�C�t���[���Ă΂��֐�
	//virtual void Tick(float DeltaTime) override;

	//�R���|�[�l���g�̐ݒ�
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPaperFlipbookComponent> PaperFlipbook;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> Niagara;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	


};
