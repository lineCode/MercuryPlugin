// Copyright (c) 2022 Kaya Adrian

using System.IO;
using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryProtocols : ModuleRules
{
	public MercuryProtocols(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"MercuryNetwork",
			"MercuryUtilities",
			"Networking",
			"Sockets"
		});
		
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/MercuryDelegates"),
			Path.Combine(ModuleDirectory, "Public/MercuryEnums"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects/TCP"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects/UDP")
		});
	}
}
