// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonValue.h"

#include "MercuryJson.h"
#include "MercuryJsonObject.h"


UMercuryJsonValue::UMercuryJsonValue(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FJsonValueNull());
}

EMercuryJsonValueType UMercuryJsonValue::GetType() const
{
	if (!Resource)
		return EMercuryJsonValueType::Null;
	
	switch (Resource->Type)
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
	TArray<UMercuryJsonValue*>&& MercuryJsonValues = TArray<UMercuryJsonValue*>();
	const TArray<TSharedPtr<FJsonValue>>&& JsonValues = Resource ?
		Resource->AsArray() : TArray<TSharedPtr<FJsonValue>>();
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		UMercuryJsonValue* const&& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetResource() = JsonValue;
		MercuryJsonValues.Add(MercuryJsonValue);
	}

	return MercuryJsonValues;
}

bool UMercuryJsonValue::AsBool() const
{
	return Resource && Resource->AsBool();
}

double UMercuryJsonValue::AsNumber() const
{
	return Resource ? Resource->AsNumber() : 0.0;
}

UMercuryJsonObject* UMercuryJsonValue::AsObject() const
{
	if (!Resource)
		return nullptr;
	
	UMercuryJsonObject* const&& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->GetResource() = Resource->AsObject();
	return JsonObject;
}

FString UMercuryJsonValue::AsString() const
{
	return Resource ? Resource->AsString() : TEXT("");
}

bool UMercuryJsonValue::IsNull() const
{
	return Resource && Resource->IsNull();
}

void UMercuryJsonValue::AsArgumentType(TArray<UMercuryJsonValue*>& Value) const
{
	Value.Empty();
	if (!Resource)
		return;
	
	TArray<TSharedPtr<FJsonValue>>&& JsonValues = TArray<TSharedPtr<FJsonValue>>();
	Resource->AsArgumentType(JsonValues);
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		UMercuryJsonValue* const&& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetResource() = JsonValue;
		Value.Add(MercuryJsonValue);
	}
}

void UMercuryJsonValue::AsArgumentType(bool& Value) const
{
	Value = false;
	if (!Resource)
		return;

	Resource->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(double& Value) const
{
	Value = 0.0;
	if (!Resource)
		return;

	Resource->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(UMercuryJsonObject*& Value) const
{
	Value->GetResource() = nullptr;
	if (!Resource)
		return;
	
	Resource->AsArgumentType(Value->GetResource());
}

void UMercuryJsonValue::AsArgumentType(FString& Value) const
{
	Value = TEXT("");
	if (!Resource)
		return;

	Resource->AsArgumentType(Value);
}

bool UMercuryJsonValue::TryGetArray(TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();

	const TArray<TSharedPtr<FJsonValue>>*&& ArrayField = nullptr;
	const bool&& bGotArray = Resource && Resource->TryGetArray(ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField ? *ArrayField : TArray<TSharedPtr<FJsonValue>>())
	{
		UMercuryJsonValue* const&& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetResource() = JsonValue;
		OutArray.Add(MercuryJsonValue);
	}
	return bGotArray;
}

bool UMercuryJsonValue::TryGetBool(bool& OutBool) const
{
	OutBool = false;
	return Resource && Resource->TryGetBool(OutBool);
}

bool UMercuryJsonValue::TryGetNumber(double& OutNumber) const
{
	OutNumber = 0.0;
	return Resource && Resource->TryGetNumber(OutNumber);
}

bool UMercuryJsonValue::TryGetObject(UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>*&& ObjectField = nullptr;
	const bool&& bGotObject = Resource ? Resource->TryGetObject(ObjectField) : false;

	OutObject->GetResource() = ObjectField ? *ObjectField : nullptr;
	return bGotObject;
}

bool UMercuryJsonValue::TryGetString(FString& OutString) const
{
	OutString = TEXT("");
	return Resource && Resource->TryGetString(OutString);
}

UMercuryJsonValue* UMercuryJsonValue::Duplicate(const UMercuryJsonValue* const& Source)
{
	UMercuryJsonValue* const&& Destination = NewObject<UMercuryJsonValue>();
	Destination->GetResource() = Resource ? Resource->Duplicate(Source->GetResource()) : nullptr;
	return Destination;
}

bool UMercuryJsonValue::CompareEqual(const UMercuryJsonValue* const& Left, const UMercuryJsonValue* const& Right) const
{
	return Resource && Left->GetResource() && Right->GetResource() ?
		Resource->CompareEqual(*Left->GetResource(), *Right->GetResource()) : false;
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
