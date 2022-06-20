// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonValueType.generated.h"


UENUM(BlueprintType, meta = (Keywords = "JSON Value Type None Null Number Boolean String Array Object"))
enum class EMercuryJsonValueType : uint8
{
	None UMETA(DisplayName = "None"),
	Null UMETA(DisplayName = "Null"),
	Number UMETA(DisplayName = "Number"),
	Boolean UMETA(DisplayName = "Boolean"),
	String UMETA(DisplayName = "String"),
	Array UMETA(DisplayName = "Array"),
	Object UMETA(DisplayName = "Object")
};
