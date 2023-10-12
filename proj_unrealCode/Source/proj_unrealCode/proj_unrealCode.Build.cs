// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class proj_unrealCode : ModuleRules
{
	public proj_unrealCode(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
