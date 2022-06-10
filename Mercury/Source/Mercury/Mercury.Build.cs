// Copyright (c) 2022 Kaya Adrian

using UnrealBuildTool;


public class Mercury : ModuleRules
{
	public Mercury(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"HTTP",
			"Json",
			"JsonUtilities",
			"WebSockets"
		});
	}
}
