// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tools/InterfacePlayObj.h"
#include "GameFramework/Actor.h"
#include "move4Direction.generated.h"

UENUM(BlueprintType)	// 언리얼 열거형을 블루프린트에서도 사용가능하도록 선언.
enum class EN_MoveTypeCode : uint8 {	// EN_MoveTypeCode(자료형=열거형) : uint8(들어가는 데이터 타입)
	// MoveRight(cpp에서 사용하는 이름), UMETA 옵션 중 DisplayName = "Right"은 블루프린트에서 보여질 이름
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
	void cPlay(bool isPlay);	// 블루프린트 호출용 함수명 선언 

	virtual void cPlay_Implementation(bool IsPlay) override;	// c++에서 실행될 함수

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
