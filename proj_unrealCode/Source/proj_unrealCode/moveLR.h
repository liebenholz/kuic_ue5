// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	// ���� �������� ���� �ּ����� �⺻ ���̺귯���� ������ ���
#include "GameFramework/Actor.h"	// AActor Ŭ���� ��� ����

// *** generated.h �𸮾� Ŭ���� ���� ó���ϴ� ��� *** - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ��� �ڵ带 �־���� ��
// �ݵ�� ��� #include�� �������� ��ġ�Ǿ�� ��
#include "moveLR.generated.h"

// �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS()
class PROJ_UNREALCODE_API AmoveLR : public AActor	// AActor�� ��� ��ӹްڴ�.
{
	GENERATED_BODY()	// �𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
	
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	// �ݵ�� �پ��־�� ��
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	// �ݵ�� �پ��־�� ��
	UStaticMeshComponent* StaticMesh; 

	float LocX;
	bool IsMoveRight = true;
};
