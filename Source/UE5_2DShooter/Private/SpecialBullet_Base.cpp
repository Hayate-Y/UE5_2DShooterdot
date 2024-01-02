
#include "SpecialBullet_Base.h"


// Sets default values
ASpecialBullet_Base::ASpecialBullet_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//�J�v�Z���R���|�[�l���g��ݒ�
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	Capsule->SetCapsuleHalfHeight(17.0f);
	Capsule->SetCapsuleRadius(17.0f);
	Capsule->SetNotifyRigidBodyCollision(true);
	Capsule->CanCharacterStepUpOn = ECB_No;
	Capsule->SetCollisionProfileName("Custom");
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Capsule->SetCollisionObjectType(ECC_GameTraceChannel5);
	Capsule->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_GameTraceChannel4, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_GameTraceChannel5, ECR_Overlap);
	Capsule->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	
	//�q�b�g�֐�
	Capsule->OnComponentHit.AddDynamic(this, &ASpecialBullet_Base::OnHitComponent);

	RootComponent = Capsule;

	//�t���b�v�u�b�N��ݒ�
	PaperFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbookComponent"));
	PaperFlipbook->SetupAttachment(RootComponent);
	
	//X�i���[���j��-90�x��]�E�E�E�������iY,Z,X�j�̏��ɂȂ��Ă���͗l
	PaperFlipbook->SetRelativeRotation(FRotator(0, 0, -90.0f));
	
	//Niagara�̐ݒ�i�e�̉e�Ɏg�p�j
	Niagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	Niagara->SetupAttachment(RootComponent);
	Niagara->SetRelativeLocation(FVector(-12.0f,0,0));

	//�����̐ݒ�
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovement->UpdatedComponent=RootComponent;
	ProjectileMovement->InitialSpeed = 300.0f;
	ProjectileMovement->MaxSpeed = 300.0f;
	ProjectileMovement->ProjectileGravityScale = 0;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->bBounceAngleAffectsFriction = true;
	ProjectileMovement->Bounciness = 1.0f;
	ProjectileMovement->Friction = 0.0f;

}

void ASpecialBullet_Base::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void ASpecialBullet_Base::OnHitComponent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

