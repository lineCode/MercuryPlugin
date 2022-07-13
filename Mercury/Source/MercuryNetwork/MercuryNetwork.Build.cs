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
		
		PublicIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/Enums"),
			Path.Combine(ModuleDirectory, "Public/Objects")
		});
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Private/Objects")
		});
	}
}
