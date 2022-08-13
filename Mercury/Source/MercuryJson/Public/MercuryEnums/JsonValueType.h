// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJson.h"
#include "Serialization/JsonTypes.h"
#include "UObject/ObjectMacros.h"


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

namespace MercuryEnums::JsonValue
{
	constexpr EMercuryJsonValueType Convert(const EJson& ValueType)
	{
		switch (ValueType)
		{
		case EJson::None:
			return EMercuryJsonValueType::None;

		case EJson::Null:
			return EMercuryJsonValueType::Null;

		case EJson::Number:
			return EMercuryJsonValueType::Number;

		case EJson::Boolean:
			return EMercuryJsonValueType::Boolean;

		case EJson::String:
			return EMercuryJsonValueType::String;

		case EJson::Array:
			return EMercuryJsonValueType::Array;

		case EJson::Object:
			return EMercuryJsonValueType::Object;

		default:
			UE_LOG(LogMercuryJson, Error, TEXT("Unknown value type: %d"), ValueType);
			return EMercuryJsonValueType::None;
		}
	}

	constexpr EJson Convert(const EMercuryJsonValueType& ValueType)
	{
		switch (ValueType)
		{
		case EMercuryJsonValueType::None:
			return EJson::None;

		case EMercuryJsonValueType::Null:
			return EJson::Null;

		case EMercuryJsonValueType::Number:
			return EJson::Number;

		case EMercuryJsonValueType::Boolean:
			return EJson::Boolean;

		case EMercuryJsonValueType::String:
			return EJson::String;

		case EMercuryJsonValueType::Array:
			return EJson::Array;

		case EMercuryJsonValueType::Object:
			return EJson::Object;

		default:
			UE_LOG(LogMercuryJson, Error, TEXT("Unknown value type: %d"), ValueType);
			return EJson::None;
		}
	}
}
