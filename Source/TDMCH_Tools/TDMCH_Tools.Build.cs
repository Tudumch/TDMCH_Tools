// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TDMCH_Tools : ModuleRules
{
    public TDMCH_Tools(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
            }
            );


        PrivateIncludePaths.AddRange(
            new string[] {
                "TDMCH_Tools"
            }
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "UMG", "EnhancedInput"
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
