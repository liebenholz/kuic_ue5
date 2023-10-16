// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	// ���� �������� ���� �ּ����� �⺻ ���̺귯���� ������ ���
#include "Public/Tools/InterfacePlayObj.h"
#include "GameFramework/Actor.h"	// AActor Ŭ���� ��� ����

// *** generated.h �𸮾� Ŭ���� ���� ó���ϴ� ��� *** - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ��� �ڵ带 �־���� ��
// �ݵ�� ��� #include�� �������� ��ġ�Ǿ�� ��
#include "moveLR.generated.h"

// �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS()
class PROJ_UNREALCODE_API AmoveLR : public AActor, public IInterfacePlayObj	// AActor�� IInterfacePlayObj�� ��� ��ӹްڴ�.
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

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void cPlay(bool IsPlay);// �������Ʈ ȣ��� �Լ��� ����

	virtual void cPlay_Implementation(bool IsPlay) override;// c++���� ����� �Լ�

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)	// �ݵ�� �پ��־�� ��
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	// �ݵ�� �پ��־�� ��
	UStaticMeshComponent* StaticMesh; 

	float m_LocX;
	bool m_IsMoveRight = true;
	bool m_isPlay = false;
};
