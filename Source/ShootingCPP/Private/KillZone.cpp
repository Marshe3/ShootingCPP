// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"

#include "Components/BoxComponent.h"


// Sets default values
AKillZone::AKillZone()
{
	// Tick()이 필요 없는 액터에는 항상 false로 설정
	PrimaryActorTick.bCanEverTick = false;
	
	// 플레이어와 동일 - 박스 콜리전 컴포넌트 생성
	boxComp =CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Collider"));
	SetRootComponent(boxComp); // 생성된 박스 콜라이더 컴포넌트를 최상단 컴포넌트로 설정
	
	// 박스 모빌리티 고정으로 설정
	
	boxComp->SetMobility(EComponentMobility::Static);
	
	// 박스 콜라이더 크기를 50X2000X50 설정
	FVector boxSize = FVector(50.0f, 2000.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);
	
	boxComp->SetCollisionProfileName(TEXT("KillZone"));
}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	// OnComponentBeginOverlap 델리게이트에 OnOverlap 함수를 등록
	// "Overlap" 발생하면 OnOverlap() 호출해 라고 엔진에 등록 설정
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::OnKillZoneOverlap);
}

void AKillZone::OnKillZoneOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor
	, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex
	, bool bFromSweep, const FHitResult& SweepResult)
{
	// 진입한 액터 제거
	OtherActor->Destroy();
}

