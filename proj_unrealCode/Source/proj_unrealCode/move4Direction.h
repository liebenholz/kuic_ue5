// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tools/InterfacePlayObj.h"
#include "GameFramework/Actor.h"
#include "move4Direction.generated.h"

UENUM(BlueprintType)	// �𸮾� �������� �������Ʈ������ ��밡���ϵ��� ����.
enum class EN_MoveTypeCode : uint8 {	// EN_MoveTypeCode(�ڷ���=������) : uint8(���� ������ Ÿ��)
	// MoveRight(cpp���� ����ϴ� �̸�), UMETA �ɼ� �� DisplayName = "Right"�� �������Ʈ���� ������ �̸�
	MoveRight UMETA(DisplayName = "Right"),
	MoveUp UMETA(DisplayName = "Right"),
	MoveLeft UMETA(DisplayName = "Left"),
	MoveDown UMETA(DisplayName = "Down")
};

UCLASS()
class PROJ_UNREALCODE_API Amove4Direction : public AActor, public IInterfacePlayObj
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amove4Direction();
	~Amove4Direction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void cPlay(bool isPlay);	// �������Ʈ ȣ��� �Լ��� ���� 

	virtual void cPlay_Implementation(bool IsPlay) override;	// c++���� ����� �Լ�

public:

	EN_MoveTypeCode MoveType = EN_MoveTypeCode::MoveRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float m_PosX = 0;
	float m_PosZ = 0;
	bool m_isPlay = false;
};
