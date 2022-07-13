// Copyright (c) 2022 Kaya Adrian

using System.IO;
using UnrealBuildTool;


// ReSharper disable once InconsistentNaming
public class MercuryJson : ModuleRules
{
	public MercuryJson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Json",
			"JsonUtilities",
			"MercuryUtilities"
		});
		
		PrivateIncludePaths.AddRange(new[]
		{
			Path.Combine(ModuleDirectory, "Public/MercuryEnums"),
			Path.Combine(ModuleDirectory, "Public/MercuryObjects")
		});
	}
}
