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
		
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/MercuryDelegates"),
			Path.Combine(ModuleDirectory, "Public/MercuryEnums"),
			Path.Combine(ModuleDirectory, "Public/MercuryNodes"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects")
		});
	}
}
