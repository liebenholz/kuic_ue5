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

	UFUNCTION()	// ���ε� �Լ��� �ݵ�� UFUNCTION ���� ������ �Ѵ�.
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()	// ���ε� �Լ��� �ݵ�� UFUNCTION ���� ������ �Ѵ�.
	void OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> arrActors;

	// TObjectPtr �𸮾󿡼� AmoveLR�� ��ӹ��� ��� Ŭ������ ����ų �� �ִ� ����
	// EditAnyhwere : �ν��Ͻ� ��������; ������ ��ġ�� �ν��Ͻ����� ������ â���� ���� �����ϰ� �Ѵ�
	// class : #include�� Ŭ������ �߰����� �ʰ� ���Ŀ� Ŭ������ ���� ���̶� ������ �ܰ迡���� �˷��ִ� Ű����
	// TArray : �𸮾󿡼� �迭(Vector) ����, ��) TArray<int> arr
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
