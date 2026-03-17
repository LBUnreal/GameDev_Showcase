// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlasterSam : ModuleRules
{
	public BlasterSam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"BlasterSam",
			"BlasterSam/Variant_Platforming",
			"BlasterSam/Variant_Platforming/Animation",
			"BlasterSam/Variant_Combat",
			"BlasterSam/Variant_Combat/AI",
			"BlasterSam/Variant_Combat/Animation",
			"BlasterSam/Variant_Combat/Gameplay",
			"BlasterSam/Variant_Combat/Interfaces",
			"BlasterSam/Variant_Combat/UI",
			"BlasterSam/Variant_SideScrolling",
			"BlasterSam/Variant_SideScrolling/AI",
			"BlasterSam/Variant_SideScrolling/Gameplay",
			"BlasterSam/Variant_SideScrolling/Interfaces",
			"BlasterSam/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
