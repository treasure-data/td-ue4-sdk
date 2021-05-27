// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class TreasureData : ModuleRules
	{
		public TreasureData(ReadOnlyTargetRules Target): base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"TreasureData/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
                                        "CoreUObject",
                                        "Engine",
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                                        "Analytics",
                                        "HTTP",
                                        "Json",
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
                        //PublicIncludePathModuleNames.Add("Analytics");
		}
	}
}
