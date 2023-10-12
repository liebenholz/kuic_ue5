// Copyright Epic Games, Inc. All Rights Reserved.

#include "proj_unrealCodeGameMode.h"
#include "proj_unrealCodeCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aproj_unrealCodeGameMode::Aproj_unrealCodeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
