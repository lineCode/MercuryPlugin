// Copyright (c) 2022 Kaya Adrian

using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryHttp : ModuleRules
{
	public MercuryHttp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"HTTP"
		});
	}
}
