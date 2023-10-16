// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "moveLR.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switch.generated.h"

UCLASS()
class PROJ_UNREALCODE_API ASwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()	// 바인딩 함수는 반드시 UFUNCTION 으로 만들어야 한다.
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()	// 바인딩 함수는 반드시 UFUNCTION 으로 만들어야 한다.
	void OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> arrActors;

	// TObjectPtr 언리얼에서 AmoveLR을 상속받은 모든 클래스를 가리킬 수 있는 변수
	// EditAnyhwere : 인스턴스 편집가능; 레벨에 배치한 인스턴스에서 디테일 창으로 편집 가능하게 한다
	// class : #include로 클래스를 추가하지 않고 차후에 클래스가 있을 것이라도 컴파일 단계에서만 알려주는 키워드
	// TArray : 언리얼에서 배열(Vector) 변수, 예) TArray<int> arr
	// UPROPERTY(EditAnywhere, BlueprintReadOnly)
	// TArray<TObjectPtr<class AmoveLR>> arrLR;
	// TObjectPtr<class AmoveLR> leftright;

	// UPROPERTY(EditAnywhere, BlueprintReadOnly)
	// TArray<TObjectPtr<class Amove4Direction>> arrRect;
	// TObjectPtr<class Amove4Direction> rect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

};
