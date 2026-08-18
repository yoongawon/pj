#include "MyStar.h"


AMyStar::AMyStar()
{
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Pear.M_Pear"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;

}

void AMyStar::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation(); // 시작 위치 저장

	OnMyStarPickedUP();
}

void AMyStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

	// 왕복 이동 (X축 기준)
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + FVector(MoveDirection * MoveSpeed * DeltaTime, 0.0f, 0.0f);

	float DistanceFromStart = FVector::Dist(StartLocation, NewLocation);
	if (DistanceFromStart >= MaxRange)
	{
		MoveDirection *= -1.0f;
	}

	SetActorLocation(NewLocation);
}

void AMyStar::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AMyStar::GetRotationSpeed() const
{
	return RotationSpeed;
}
