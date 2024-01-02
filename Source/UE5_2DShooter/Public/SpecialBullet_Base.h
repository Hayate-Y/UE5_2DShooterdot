
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
	//コンストラクタ
	ASpecialBullet_Base();

protected:
	// 開始時に呼ばれる関数
	virtual void BeginPlay() override;

public:
	//ヒットした時の関数
	UFUNCTION()
		virtual void OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) ;


	// マイフレーム呼ばれる関数
	//virtual void Tick(float DeltaTime) override;

	//コンポーネントの設定
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPaperFlipbookComponent> PaperFlipbook;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> Niagara;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	


};
