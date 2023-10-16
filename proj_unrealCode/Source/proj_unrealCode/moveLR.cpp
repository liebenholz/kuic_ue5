// Fill out your copyright notice in the Description page of Project Settings.

#include "moveLR.h"

// Sets default values
AmoveLR::AmoveLR()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	// TEXT : �𸮾󿡼� ����ϴ� ������ �� �ϳ�.
	// <USceneComponent>(TEXT("SceneRootRoot")); : USceneComponent ��ü�� "SceneRootRoot" �̸����� ���� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	// <UStaticMeshComponent>(TEXT("mymyMesh")); : UStaticMeshComponent ��ü�� "mymyMesh" �̸����� ���� ����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);	// Scene�� Root Component�� �ø��ڴ�.
	// RootComponent = Scene;	// Scene�� Root Component�� �ø��ڴ�.

	// AttachToComponent : Component�� ���̴� ���
	// Scene�� ���� ��ǥ���� Scene �������� �����ǥ��(KeepRelativeTransform)�� ���δ�.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	// RootComponent�� ���� ��ǥ���� Scene �������� �����ǥ��(KeepRelativeTransform)�� ���δ�.
	// StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset ��������
	// ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	// <UStaticMesh> : ã�� ���� Ÿ��
	// sm : ã�Ƽ� ���� ��ü�� �̸�
	// static ConstructorHelpers::FObjectFinder<UStaticMesh>sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	//if (sm.Succeeded()) {	// ������ ���������� �ҷ�������
	//	StaticMesh->SetStaticMesh(sm.Object);	// StaticMeshComponent�� StaticMesh ����
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
	Super::Tick(DeltaTime);	// �������̵��� �Լ��� ��� �θ� �Լ��� �����Ѵ�.

	if (m_isPlay == false)
		return;

	if (m_IsMoveRight) {
		m_LocX++;	// ������ �̵�
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

