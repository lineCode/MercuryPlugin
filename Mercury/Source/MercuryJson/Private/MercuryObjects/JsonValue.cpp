// Copyright (c) 2022 Kaya Adrian

#include "JsonValue.h"

#include "JsonObject.h"
#include "MercuryJsonLibrary.h"


TSharedPtr<FJsonValue> UMercuryJsonValue::CreateResource()
{
	return MakeShareable(new FJsonValueNull());
}

bool UMercuryJsonValue::HasResource() const
{
	return Resource != nullptr;
}

EMercuryJsonValueType UMercuryJsonValue::GetType() const
{
	return MercuryEnums::JsonValue::Convert(HasResource() ? Resource->Type : EJson::None);
}
UMercuryJsonValue* UMercuryJsonValue::SetType(const EMercuryJsonValueType Value)
{
	if (!HasResource())
		return nullptr;

	Resource->Type = MercuryEnums::JsonValue::Convert(Value);
	return this;
}

TArray<UMercuryJsonValue*> UMercuryJsonValue::AsArray() const
{
	TArray<UMercuryJsonValue*>&& MercuryJsonValues = TArray<UMercuryJsonValue*>();
	const TArray<TSharedPtr<FJsonValue>>&& JsonValues = HasResource() ?
		Resource->AsArray() : TArray<TSharedPtr<FJsonValue>>();
	
	for (const TSharedPtr<FJsonValue>& JsonValue : JsonValues)
	{
		MercuryJsonValues.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}

	return MercuryJsonValues;
}

bool UMercuryJsonValue::AsBool() const
{
	return HasResource() && Resource->AsBool();
}

double UMercuryJsonValue::AsNumber() const
{
	return HasResource() ? Resource->AsNumber() : 0.0;
}

UMercuryJsonObject* UMercuryJsonValue::AsObject() const
{
	return HasResource() ? UMercuryJsonLibrary::CreateJsonObject(Resource->AsObject()) : nullptr;
}

FString UMercuryJsonValue::AsString() const
{
	return HasResource() ? Resource->AsString() : TEXT("");
}

bool UMercuryJsonValue::IsNull() const
{
	return HasResource() && Resource->IsNull();
}

void UMercuryJsonValue::AsArgumentType(TArray<UMercuryJsonValue*>& Value) const
{
	Value.Empty();
	if (!HasResource())
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
	if (!HasResource())
		return;

	Resource->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(double& Value) const
{
	Value = 0.0;
	if (!HasResource())
		return;

	Resource->AsArgumentType(Value);
}

void UMercuryJsonValue::AsArgumentType(UMercuryJsonObject*& Value) const
{
	Value->SetResource(nullptr);
	if (!HasResource())
		return;

	TSharedPtr<FJsonObject>&& ResourceObject = nullptr;
	Resource->AsArgumentType(ResourceObject);
	Value->SetResource(ResourceObject);
}

void UMercuryJsonValue::AsArgumentType(FString& Value) const
{
	Value = TEXT("");
	if (!HasResource())
		return;

	Resource->AsArgumentType(Value);
}

bool UMercuryJsonValue::TryGetArray(TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();

	const TArray<TSharedPtr<FJsonValue>>*&& ArrayField = nullptr;
	const bool&& bGotArray = HasResource() && Resource->TryGetArray(ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField ? *ArrayField : TArray<TSharedPtr<FJsonValue>>())
	{
		OutArray.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}
	return bGotArray;
}

bool UMercuryJsonValue::TryGetBool(bool& OutBool) const
{
	OutBool = false;
	return HasResource() && Resource->TryGetBool(OutBool);
}

bool UMercuryJsonValue::TryGetNumber(double& OutNumber) const
{
	OutNumber = 0.0;
	return HasResource() && Resource->TryGetNumber(OutNumber);
}

bool UMercuryJsonValue::TryGetObject(UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>*&& ObjectField = nullptr;
	const bool&& bGotObject = HasResource() ? Resource->TryGetObject(ObjectField) : false;

	OutObject->SetResource(ObjectField ? *ObjectField : nullptr);
	return bGotObject;
}

bool UMercuryJsonValue::TryGetString(FString& OutString) const
{
	OutString = TEXT("");
	return HasResource() && Resource->TryGetString(OutString);
}

UMercuryJsonValue* UMercuryJsonValue::Duplicate(const UMercuryJsonValue* const& Source)
{
	return UMercuryJsonLibrary::CreateJsonValue(
		HasResource() ? Resource->Duplicate(Source->GetResource()) : nullptr
	);
}

bool UMercuryJsonValue::CompareEqual(const UMercuryJsonValue* const& Left, const UMercuryJsonValue* const& Right) const
{
	const FJsonValue* const&& LeftResource = Left->GetResource().Get();
	const FJsonValue* const&& RightResource = Right->GetResource().Get();
	
	return LeftResource && RightResource
	&& HasResource() && Resource->CompareEqual(*LeftResource, *RightResource);
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
