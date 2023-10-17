// Fill out your copyright notice in the Description page of Project Settings.

#include "move4Direction.h"
#include "Switch.h"

// Sets default values
Amove4Direction::Amove4Direction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("customSceneRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("customStaticMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

}

Amove4Direction::~Amove4Direction()
{
}

// Called when the game starts or when spawned
void Amove4Direction::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &Amove4Direction::EventOverlap);
}

// Called every frame
void Amove4Direction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_isPlay == false)
		return;

	switch (MoveType) {
	case EN_MoveTypeCode::MoveRight:
		m_PosX++;
		StaticMesh->SetRelativeLocation(FVector(m_PosX, 0, m_PosZ));
		if (m_PosX >= 100)  MoveType = EN_MoveTypeCode::MoveUp;
		break;
	case EN_MoveTypeCode::MoveUp:
		m_PosZ++;
		StaticMesh->SetRelativeLocation(FVector(m_PosX, 0, m_PosZ));
		if (m_PosZ >= 100) MoveType = EN_MoveTypeCode::MoveLeft;
		break;
	case EN_MoveTypeCode::MoveLeft:
		m_PosX--;
		StaticMesh->SetRelativeLocation(FVector(m_PosX, 0, m_PosZ));
		if (m_PosX <= 0) MoveType = EN_MoveTypeCode::MoveDown;
		break;
	case EN_MoveTypeCode::MoveDown:
		m_PosZ--;
		StaticMesh->SetRelativeLocation(FVector(m_PosX, 0, m_PosZ));
		if (m_PosZ <= 0) MoveType = EN_MoveTypeCode::MoveRight;
		break;
	}
}

void Amove4Direction::EventOverlap(bool isBegin)
{
	m_isPlay = isBegin;
}

void Amove4Direction::cPlay_Implementation(bool isPlay)
{
	m_isPlay = isPlay;
}


