// Copyright (c) 2022 Kaya Adrian

using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercurySockets : ModuleRules
{
	public MercurySockets(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Sockets"
		});
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"MercuryCommon"
		});
	}
}
