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
	// -1 : 에러 키 값을 넣는다. 특별히 없으면 -1
	// 10.0f : 출력시간
	// FColor::Green : 텍스트 색상
	// TEXT("BeginOverlap") : 출력할 텍스트
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	/*
	// 인터페이스를 활용한 변수 읽어오기
	for (AActor* pActor : arrActors) {
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);	// 상속한 인터페이스 형변환
		if (InterfaceObj) {
			// 인터페이스 형변환 성공 후 Execute_(function) 으로 인터페이스 함수 호출
			// Execute_(function)의 첫번째 파라미터는 함수 호출 대상 객체, 이후는 함수 파라미터
			InterfaceObj->Execute_cPlay(pActor, true);
		}
	}
	*/
	if (FDele_EventOverlap.IsBound())		// 바인딩된 함수가 있는지 체크
		FDele_EventOverlap.Broadcast(true);	// 델리게이트 이벤트 호출(디스패처 호출과 같음)

	/*
	// 형변환을 활용한 변수 읽어오기
	for (AActor* pActor : arrActors) {
		// AmoveLR로 형변환
		AmoveLR* pLeftRight = Cast<AmoveLR>(pActor);
		if (pLeftRight) {
			pLeftRight->m_isPlay = true;
			continue;
		}
		// Amove$Direction로 형변환
		Amove4Direction* pRect = Cast<Amove4Direction>(pActor);
		if (pRect) {
			pRect->isPlay = true;
			continue;
		}
	}
	*/

	/*
	// 배열 활용한 변수 읽어오기
	// if (IsValid(leftright) == false) // isValid : 언리얼에서 객체의 유효한지 체크
	//	return;
	// leftright->isPlay = true;
	
	for (int i = 0; i < arrLR.Num(); i++) {
		arrLR[i]->isPlay = true;	// 포인터배열이기 때문에 "->"를 사용해서 참조
	}
	
	for (AmoveLR* leftright : arrLR) {
		leftright->isPlay = true;
	}

	// if(IsValid(rect) == false) // isValid : 언리얼에서 객체의 유효한지 체크
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
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);	// 상속한 인터페이스 형변환
		if (InterfaceObj) {
			// 인터페이스 형변환 성공 후 Execute_(function) 으로 인터페이스 함수 호출
			// Execute_(function)의 첫번째 파라미터는 함수 호출 대상 객체, 이후는 함수 파라미터
			InterfaceObj->Execute_cPlay(pActor, false);
		}
	}
	*/

	if (FDele_EventOverlap.IsBound())		// 바인딩된 함수가 있는지 체크
		FDele_EventOverlap.Broadcast(false);	// 델리게이트 이벤트 호출(디스패처 호출과 같음)

	/*
	for (AActor* pActor : arrActors) {
		// AmoveLR로 형변환
		AmoveLR* pLeftRight = Cast<AmoveLR>(pActor);
		if (pLeftRight) {
			pLeftRight->m_isPlay = false;
			continue;
		}
		// Amove$Direction로 형변환
		Amove4Direction* pRect = Cast<Amove4Direction>(pActor);
		if (pRect) {
			pRect->isPlay = false;
			continue;
		}
	}
	*/

	// if (IsValid(leftright) == false) // isValid : 언리얼에서 객체의 유효한지 체크
	// 	return;
	// leftright->isPlay = false;

	/*
	for (AmoveLR* leftright : arrLR) {
		leftright->isPlay = false;
	}

	// if (IsValid(rect) == false) // isValid : 언리얼에서 객체의 유효한지 체크
	//	return;
	// rect->isPlay = false;

	for (Amove4Direction* rect : arrRect) {
		rect->isPlay = false;
	}
	*/
}

