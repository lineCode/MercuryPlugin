// Copyright (c) 2022 Kaya Adrian

using System.IO;
using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryNetwork : ModuleRules
{
	public MercuryNetwork(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"MercuryUtilities",
			"Networking",
			"Sockets"
		});
		
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/MercuryEnums"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects")
		});
	}
}
