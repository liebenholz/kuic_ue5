// Fill out your copyright notice in the Description page of Project Settings.


#include "Switch.h"
#include "moveLR.h"
#include "move4Direction.h"
#include "Public/Tools/InterfacePlayObj.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("customSceneRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("customStaticMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ASwitch::OnSwitchBeginOverlap);

	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ASwitch::OnSwitchEndOverlap);

}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASwitch::OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Print String
	// -1 : ���� Ű ���� �ִ´�. Ư���� ������ -1
	// 10.0f : ��½ð�
	// FColor::Green : �ؽ�Ʈ ����
	// TEXT("BeginOverlap") : ����� �ؽ�Ʈ
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	/*
	// �������̽��� Ȱ���� ���� �о����
	for (AActor* pActor : arrActors) {
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);	// ����� �������̽� ����ȯ
		if (InterfaceObj) {
			// �������̽� ����ȯ ���� �� Execute_(function) ���� �������̽� �Լ� ȣ��
			// Execute_(function)�� ù��° �Ķ���ʹ� �Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ����
			InterfaceObj->Execute_cPlay(pActor, true);
		}
	}
	*/
	if (FDele_EventOverlap.IsBound())		// ���ε��� �Լ��� �ִ��� üũ
		FDele_EventOverlap.Broadcast(true);	// ��������Ʈ �̺�Ʈ ȣ��(����ó ȣ��� ����)

	/*
	// ����ȯ�� Ȱ���� ���� �о����
	for (AActor* pActor : arrActors) {
		// AmoveLR�� ����ȯ
		AmoveLR* pLeftRight = Cast<AmoveLR>(pActor);
		if (pLeftRight) {
			pLeftRight->m_isPlay = true;
			continue;
		}
		// Amove$Direction�� ����ȯ
		Amove4Direction* pRect = Cast<Amove4Direction>(pActor);
		if (pRect) {
			pRect->isPlay = true;
			continue;
		}
	}
	*/

	/*
	// �迭 Ȱ���� ���� �о����
	// if (IsValid(leftright) == false) // isValid : �𸮾󿡼� ��ü�� ��ȿ���� üũ
	//	return;
	// leftright->isPlay = true;
	
	for (int i = 0; i < arrLR.Num(); i++) {
		arrLR[i]->isPlay = true;	// �����͹迭�̱� ������ "->"�� ����ؼ� ����
	}
	
	for (AmoveLR* leftright : arrLR) {
		leftright->isPlay = true;
	}

	// if(IsValid(rect) == false) // isValid : �𸮾󿡼� ��ü�� ��ȿ���� üũ
	//  return;
	// rect->isPlay = true;

	for (Amove4Direction* rect : arrRect) {
		rect->isPlay = true;
	}
	*/
}

void ASwitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("EndOverlap"));

	/*
	for (AActor* pActor : arrActors) {
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);	// ����� �������̽� ����ȯ
		if (InterfaceObj) {
			// �������̽� ����ȯ ���� �� Execute_(function) ���� �������̽� �Լ� ȣ��
			// Execute_(function)�� ù��° �Ķ���ʹ� �Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ����
			InterfaceObj->Execute_cPlay(pActor, false);
		}
	}
	*/

	if (FDele_EventOverlap.IsBound())		// ���ε��� �Լ��� �ִ��� üũ
		FDele_EventOverlap.Broadcast(false);	// ��������Ʈ �̺�Ʈ ȣ��(����ó ȣ��� ����)

	/*
	for (AActor* pActor : arrActors) {
		// AmoveLR�� ����ȯ
		AmoveLR* pLeftRight = Cast<AmoveLR>(pActor);
		if (pLeftRight) {
			pLeftRight->m_isPlay = false;
			continue;
		}
		// Amove$Direction�� ����ȯ
		Amove4Direction* pRect = Cast<Amove4Direction>(pActor);
		if (pRect) {
			pRect->isPlay = false;
			continue;
		}
	}
	*/

	// if (IsValid(leftright) == false) // isValid : �𸮾󿡼� ��ü�� ��ȿ���� üũ
	// 	return;
	// leftright->isPlay = false;

	/*
	for (AmoveLR* leftright : arrLR) {
		leftright->isPlay = false;
	}

	// if (IsValid(rect) == false) // isValid : �𸮾󿡼� ��ü�� ��ȿ���� üũ
	//	return;
	// rect->isPlay = false;

	for (Amove4Direction* rect : arrRect) {
		rect->isPlay = false;
	}
	*/
}

