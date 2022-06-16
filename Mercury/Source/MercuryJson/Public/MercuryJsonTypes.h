// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonTypes.generated.h"


UENUM(BlueprintType, meta = (
	Keywords = "JSON Type None Null Number"
))
enum class EMercuryJsonType : uint8
{
	None UMETA(DisplayName = "NONE"),
	Null UMETA(DisplayName = "Null"),
	Number UMETA(DisplayName = "Number"),
	Boolean UMETA(DisplayName = "Boolean"),
	String UMETA(DisplayName = "String"),
	Array UMETA(DisplayName = "Array"),
	Object UMETA(DisplayName = "Object")
};

USTRUCT(Atomic, BlueprintType, DisplayName = "Mercury JSON Object", meta = (
	HasNativeBreak = "MercuryJson.MercuryJsonLibrary.JsonObjectToString",
	HasNativeMake = "MercuryJson.MercuryJsonLibrary.MakeJson"
))
struct FMercuryJsonObject
{
	GENERATED_BODY();
	
	TSharedPtr<FJsonObject> Reference = MakeShareable(new FJsonObject());
};

USTRUCT(Atomic, BlueprintType, DisplayName = "Mercury JSON Value", meta = (
	HasNativeMake = "MercuryJson.MercuryJsonLibrary."
))
struct FMercuryJsonValue
{
	GENERATED_BODY();
	
	TSharedPtr<FJsonValue> Reference;
};
