// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	// 빠른 컴파일을 위해 최소한의 기본 라이브러리만 포함한 헤더
#include "Public/Tools/InterfacePlayObj.h"
#include "GameFramework/Actor.h"	// AActor 클래스 헤더 생성

// *** generated.h 언리얼 클래스 생성 처리하는 헤더 *** - 언리얼 클래스 생성 기본 규칙
// 모든 언리얼 클래스가 생성되려면 아래에 코드를 넣어줘야 함
// 반드시 모든 #include의 마지막에 배치되어야 함
#include "moveLR.generated.h"

// 언리얼 클래스 선언 - 언리얼 클래스 생성 기본 규칙
// 이 클래스는 UNREALCODE_API 모듈에 포함된다.
UCLASS()
class PROJ_UNREALCODE_API AmoveLR : public AActor, public IInterfacePlayObj	// AActor와 IInterfacePlayObj의 기능 상속받겠다.
{
	GENERATED_BODY()	// 언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙
	
public:	
	// Sets default values for this actor's properties
	AmoveLR();
	~AmoveLR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()	// 바인딩하는 함수들은 모두 UFUNCTION으로
	void EventOverlap(bool isBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void cPlay(bool IsPlay);// 블루프린트 호출용 함수명 선언

	virtual void cPlay_Implementation(bool IsPlay) override;// c++에서 실행될 함수

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	// 반드시 붙어있어야 함
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	// 반드시 붙어있어야 함
	UStaticMeshComponent* StaticMesh; 

	float m_LocX;
	bool m_IsMoveRight = true;
	bool m_isPlay = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch> m_Switch;
};
