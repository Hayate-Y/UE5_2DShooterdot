
#include "SpecialBullet_Base.h"


// Sets default values
ASpecialBullet_Base::ASpecialBullet_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//カプセルコンポーネントを設定
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
	
	//ヒット関数
	Capsule->OnComponentHit.AddDynamic(this, &ASpecialBullet_Base::OnHitComponent);

	RootComponent = Capsule;

	//フリップブックを設定
	PaperFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbookComponent"));
	PaperFlipbook->SetupAttachment(RootComponent);
	
	//X（ロール）を-90度回転・・・引数が（Y,Z,X）の順になっている模様
	PaperFlipbook->SetRelativeRotation(FRotator(0, 0, -90.0f));
	
	//Niagaraの設定（弾の影に使用）
	Niagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	Niagara->SetupAttachment(RootComponent);
	Niagara->SetRelativeLocation(FVector(-12.0f,0,0));

	//動きの設定
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

