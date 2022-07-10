// Copyright (c) 2022 Kaya Adrian

using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryUtilities : ModuleRules
{
	public MercuryUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine"
		});
	}
}
