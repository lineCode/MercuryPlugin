// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonValue.h"

#include "MercuryJson.h"
#include "MercuryJsonObject.h"


UMercuryJsonValue::UMercuryJsonValue(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Reference = MakeShareable(new FJsonValueNull());
}

EMercuryJsonValueType UMercuryJsonValue::GetType() const
{
	if (!Reference)
		return EMercuryJsonValueType::Null;
	
	switch (Reference->Type)
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
		UE_LOG(LogMercuryJson, Fatal, TEXT("Unknown JSON Value Type passed in!"));
	}

	return EMercuryJsonValueType::None;
}

TArray<UMercuryJsonValue*> UMercuryJsonValue::AsArray() const
{
	TArray<UMercuryJsonValue*> MercuryJsonValues;
	TArray<TSharedPtr<FJsonValue>> JsonValues = Reference ? Reference->AsArray() : TArray<TSharedPtr<FJsonValue>>();
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetReference() = JsonValue;
		MercuryJsonValues.Add(MercuryJsonValue);
	}

	return MercuryJsonValues;
}

bool UMercuryJsonValue::AsBool() const
{
	return Reference ? Reference->AsBool() : false;
}

double UMercuryJsonValue::AsNumber() const
{
	return Reference ? Reference->AsNumber() : 0.0;
}

UMercuryJsonObject* UMercuryJsonValue::AsObject() const
{
	if (!Reference)
		return nullptr;
	
	UMercuryJsonObject* const& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->GetReference() = Reference->AsObject();
	return JsonObject;
}

FString UMercuryJsonValue::AsString() const
{
	return Reference ? Reference->AsString() : TEXT("");
}

bool UMercuryJsonValue::IsNull() const
{
	return Reference ? Reference->IsNull() : true;
}

void UMercuryJsonValue::AsArgumentType(TArray<UMercuryJsonValue*>& Value) const
{
	Value.Empty();
	if (!Reference)
		return;
	
	TArray<TSharedPtr<FJsonValue>> JsonValues;
	Reference->AsArgumentType(JsonValues);
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetReference() = JsonValue;
		Value.Add(MercuryJsonValue);
	}
}

void UMercuryJsonValue::AsArgumentType(bool& Value) const
{
	Value = false;
	if (!Reference)
		return;

	Reference->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(double& Value) const
{
	Value = 0.0;
	if (!Reference)
		return;

	Reference->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(UMercuryJsonObject*& Value) const
{
	Value->GetReference() = nullptr;
	if (!Reference)
		return;
	
	Reference->AsArgumentType(Value->GetReference());
}

void UMercuryJsonValue::AsArgumentType(FString& Value) const
{
	Value = TEXT("");
	if (!Reference)
		return;

	Reference->AsArgumentType(Value);
}

bool UMercuryJsonValue::TryGetArray(TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();
	if (!Reference)
		return false;
	
	const TArray<TSharedPtr<FJsonValue>>* ArrayField;
	const bool& bGotArray = Reference->TryGetArray(ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : *ArrayField)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetReference() = JsonValue;
		OutArray.Add(MercuryJsonValue);
	}
	return bGotArray;
}

bool UMercuryJsonValue::TryGetBool(bool& OutBool) const
{
	OutBool = false;
	if (!Reference)
		return false;
	
	return Reference->TryGetBool(OutBool);
}

bool UMercuryJsonValue::TryGetNumber(double& OutNumber) const
{
	OutNumber = 0.0;
	if (!Reference)
		return false;

	return Reference->TryGetNumber(OutNumber);
}

bool UMercuryJsonValue::TryGetObject(UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>* ObjectField = nullptr;
	const bool& bGotObject = Reference ? Reference->TryGetObject(ObjectField) : false;

	OutObject->GetReference() = bGotObject && ObjectField ? *ObjectField : nullptr;
	return bGotObject;
}

bool UMercuryJsonValue::TryGetString(FString& OutString) const
{
	OutString = TEXT("");
	if (!Reference)
		return false;

	return Reference->TryGetString(OutString);
}

UMercuryJsonValue* UMercuryJsonValue::Duplicate(const UMercuryJsonValue* const& Source)
{
	UMercuryJsonValue* const& Destination = NewObject<UMercuryJsonValue>();
	Destination->GetReference() = Reference ? Reference->Duplicate(Source->GetReference()) : nullptr;
	return Destination;
}

bool UMercuryJsonValue::CompareEqual(const UMercuryJsonValue* const& Left, const UMercuryJsonValue* const& Right) const
{
	return Reference && Left->GetReference() && Right->GetReference() ?
		Reference->CompareEqual(*Left->GetReference(), *Right->GetReference()) : false;
}

void UMercuryJsonValue::K2_AsArgumentTypeArray(TArray<UMercuryJsonValue*>& Value) const
{
	AsArgumentType(Value);
}

void UMercuryJsonValue::K2_AsArgumentTypeBool(bool& Value) const
{
	AsArgumentType(Value);
}

void UMercuryJsonValue::K2_AsArgumentTypeNumber(double& Value) const
{
	AsArgumentType(Value);
}

void UMercuryJsonValue::K2_AsArgumentTypeObject(UMercuryJsonObject*& Value) const
{
	AsArgumentType(Value);
}

void UMercuryJsonValue::K2_AsArgumentTypeString(FString& Value) const
{
	AsArgumentType(Value);
}
