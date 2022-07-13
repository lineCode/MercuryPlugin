// Copyright (c) 2022 Kaya Adrian

using System.IO;
using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryHttp : ModuleRules
{
	public MercuryHttp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"HTTP",
			"MercuryUtilities"
		});
		
		PublicIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/Delegates"),
			Path.Combine(ModuleDirectory, "Public/Enums"),
			Path.Combine(ModuleDirectory, "Public/Objects")
		});
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Private/Objects")
		});
	}
}
