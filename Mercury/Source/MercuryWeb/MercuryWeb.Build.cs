// Copyright (c) 2022 Kaya Adrian

using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryWeb : ModuleRules
{
	public MercuryWeb(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Networking",
			"Sockets",
			"WebSockets"
		});
	}
}
