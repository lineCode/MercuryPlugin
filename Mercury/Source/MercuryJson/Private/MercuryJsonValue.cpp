// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonValue.h"

#include "MercuryJsonLibrary.h"
#include "MercuryJsonObject.h"


TSharedPtr<FJsonValue> UMercuryJsonValue::CreateResource()
{
	return MakeShareable(new FJsonValueNull());
}

EMercuryJsonValueType UMercuryJsonValue::GetType() const
{
	return MercuryEnums::JsonValue::Convert(Resource ? Resource->Type : EJson::None);
}
UMercuryJsonValue* UMercuryJsonValue::SetType(const EMercuryJsonValueType Value)
{
	if (!Resource)
		return nullptr;

	Resource->Type = MercuryEnums::JsonValue::Convert(Value);
	return this;
}

TArray<UMercuryJsonValue*> UMercuryJsonValue::AsArray() const
{
	TArray<UMercuryJsonValue*>&& MercuryJsonValues = TArray<UMercuryJsonValue*>();
	const TArray<TSharedPtr<FJsonValue>>&& JsonValues = Resource ?
		Resource->AsArray() : TArray<TSharedPtr<FJsonValue>>();
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		MercuryJsonValues.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
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
	return Resource ? UMercuryJsonLibrary::CreateJsonObject(Resource->AsObject()) : nullptr;
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
		Value.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
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
		OutArray.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
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
	return UMercuryJsonLibrary::CreateJsonValue(Resource ? Resource->Duplicate(Source->GetResource()) : nullptr);
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
