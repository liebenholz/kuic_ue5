// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfacePlayObj.generated.h"

UINTERFACE(Blueprintable)	// �������Ʈ ȣ�� �������̽� Ŭ���� ����
class PROJ_UNREALCODE_API UInterfacePlayObj : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJ_UNREALCODE_API IInterfacePlayObj	// �������̽� �Լ� ���� Ŭ����
{
	GENERATED_BODY()

public:
	// BlueprintCallable : �������Ʈ���� ȣ�� ����
	// BlueprintNativeEvent: �������Ʈ���� ��� �� �籸�� �����ϵ��� �Լ� ����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void cPlay(bool isPlay);	// �������Ʈ ȣ��� �Լ��� ���� 

	virtual void cPlay_Implementation(bool isPlay) {};	// c++���� ����� �Լ�
};
