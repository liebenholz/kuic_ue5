// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfacePlayObj.generated.h"

UINTERFACE(Blueprintable)	// 블루프린트 호출 인터페이스 클래스 선언
class PROJ_UNREALCODE_API UInterfacePlayObj : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJ_UNREALCODE_API IInterfacePlayObj	// 인터페이스 함수 구현 클래스
{
	GENERATED_BODY()

public:
	// BlueprintCallable : 블루프린트에서 호출 가능
	// BlueprintNativeEvent: 블루프린트에서 상속 및 재구현 가능하도록 함수 설정
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void cPlay(bool isPlay);	// 블루프린트 호출용 함수명 선언 

	virtual void cPlay_Implementation(bool isPlay) {};	// c++에서 실행될 함수
};
