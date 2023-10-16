// Fill out your copyright notice in the Description page of Project Settings.

#include "moveLR.h"

// Sets default values
AmoveLR::AmoveLR()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	// TEXT : 언리얼에서 사용하는 문자형 중 하나.
	// <USceneComponent>(TEXT("SceneRootRoot")); : USceneComponent 객체를 "SceneRootRoot" 이름으로 동적 생성
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	// <UStaticMeshComponent>(TEXT("mymyMesh")); : UStaticMeshComponent 객체를 "mymyMesh" 이름으로 동적 생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);	// Scene을 Root Component로 올리겠다.
	// RootComponent = Scene;	// Scene을 Root Component로 올리겠다.

	// AttachToComponent : Component에 붙이는 기능
	// Scene에 현재 좌표값을 Scene 기준으로 상대좌표계(KeepRelativeTransform)를 붙인다.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	// RootComponent에 현재 좌표값을 Scene 기준으로 상대좌표계(KeepRelativeTransform)를 붙인다.
	// StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset 가져오기
	// ConstructorHelpers::FObjectFinder : 오브젝트 에셋을 찾는다.
	// <UStaticMesh> : 찾을 에셋 타입
	// sm : 찾아서 넣을 객체의 이름
	// static ConstructorHelpers::FObjectFinder<UStaticMesh>sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	//if (sm.Succeeded()) {	// 에셋을 성공적으로 불러왔으면
	//	StaticMesh->SetStaticMesh(sm.Object);	// StaticMeshComponent에 StaticMesh 적용
	// }

}

AmoveLR::~AmoveLR()
{
}

// Called when the game starts or when spawned
void AmoveLR::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmoveLR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	// 오버라이드한 함수인 경우 부모 함수를 실행한다.

	if (m_isPlay == false)
		return;

	if (m_IsMoveRight) {
		m_LocX++;	// 오른쪽 이동
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
		if (m_LocX >= 100) m_IsMoveRight = false;
	}

	else {
		m_LocX--;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
		if (m_LocX <= 0) m_IsMoveRight = true;
	}
}

void AmoveLR::cPlay_Implementation(bool isPlay)
{
	m_isPlay = isPlay;
}

