// Copyright (c) 2022 Kaya Adrian

#include "JsonObjects.h"

#include "JsonValues.h"
#include "MercuryJsonLibrary.h"


TSharedPtr<FJsonObject> UMercuryJsonObject::CreateResource()
{
	return MakeShareable(new FJsonObject());
}

bool UMercuryJsonObject::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryJsonObject::Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination)
{
	TSharedPtr<FJsonObject>&& ResourceDestination = Destination->CreateResource();
	FJsonObject::Duplicate(Source->GetResource(), ResourceDestination);
	Destination->SetResource(ResourceDestination);
}

TMap<FString, UMercuryJsonValue*> UMercuryJsonObject::GetValues() const
{
	TMap<FString, UMercuryJsonValue*>&& MercuryJsonValues = TMap<FString, UMercuryJsonValue*>();
	if (!HasResource())
		return std::move(MercuryJsonValues);
	
	for (const TTuple<FString, TSharedPtr<FJsonValue>>& JsonValues : Resource->Values)
	{
		MercuryJsonValues[JsonValues.Key] = UMercuryJsonLibrary::CreateJsonValue(JsonValues.Value);
	}
	return std::move(MercuryJsonValues);
}
UMercuryJsonObject* UMercuryJsonObject::SetValues(const TMap<FString, UMercuryJsonValue*>& Value)
{
	if (!HasResource())
		return nullptr;
	
	Resource->Values.Empty();
	for (const TTuple<FString, UMercuryJsonValue*>& MercuryValues : Value)
	{
		Resource->Values[MercuryValues.Key] = MercuryValues.Value->GetResource();
	}
	return this;
}

UMercuryJsonValue* UMercuryJsonObject::GetField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!HasResource())
		return nullptr;

	TSharedPtr<FJsonValue>&& JsonValue = nullptr;
	switch (ValueType)
	{
	case EMercuryJsonValueType::None:
		JsonValue = Resource->GetField<EJson::None>(FieldName);
		break;

	case EMercuryJsonValueType::Null:
		JsonValue = Resource->GetField<EJson::Null>(FieldName);
		break;

	case EMercuryJsonValueType::Number:
		JsonValue = Resource->GetField<EJson::Number>(FieldName);
		break;

	case EMercuryJsonValueType::Boolean:
		JsonValue = Resource->GetField<EJson::Boolean>(FieldName);
		break;

	case EMercuryJsonValueType::String:
		JsonValue = Resource->GetField<EJson::String>(FieldName);
		break;

	case EMercuryJsonValueType::Array:
		JsonValue = Resource->GetField<EJson::Array>(FieldName);
		break;

	case EMercuryJsonValueType::Object:
		JsonValue = Resource->GetField<EJson::Object>(FieldName);
		break;

	default:
		UE_LOG(LogMercuryJson, Error, TEXT("Unknown value type: %d"), ValueType);
		JsonValue = Resource->GetField<EJson::None>(FieldName);
	}
	
	return UMercuryJsonLibrary::CreateJsonValue(JsonValue);
}

bool UMercuryJsonObject::HasField(const FString& FieldName) const
{
	return HasResource() && Resource->HasField(FieldName);
}

void UMercuryJsonObject::RemoveField(const FString& FieldName)
{
	if (!HasResource())
		return;
	
	Resource->RemoveField(FieldName);
}

UMercuryJsonObject* UMercuryJsonObject::SetField(const FString& FieldName, const UMercuryJsonValue* const& Value)
{
	if (!HasResource())
		return this;
	
	Resource->SetField(FieldName, Value->GetResource());
	return this;
}

TArray<UMercuryJsonValue*> UMercuryJsonObject::GetArrayField(const FString& FieldName) const
{
	const TArray<TSharedPtr<FJsonValue>>&& ArrayField =
		HasResource() ? Resource->GetArrayField(FieldName) : TArray<TSharedPtr<FJsonValue>>();

	TArray<UMercuryJsonValue*>&& MercuryArrayField = TArray<UMercuryJsonValue*>();
	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField)
	{
		MercuryArrayField.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}

	return std::move(MercuryArrayField);
}

bool UMercuryJsonObject::GetBoolField(const FString& FieldName) const
{
	return HasResource() && Resource->GetBoolField(FieldName);
}

int32 UMercuryJsonObject::GetIntegerField(const FString& FieldName) const
{
	return HasResource() ? Resource->GetIntegerField(FieldName) : 0;
}

double UMercuryJsonObject::GetNumberField(const FString& FieldName) const
{
	return HasResource() ? Resource->GetNumberField(FieldName) : 0.0;
}

UMercuryJsonObject* UMercuryJsonObject::GetObjectField(const FString& FieldName) const
{
	return HasResource() ? UMercuryJsonLibrary::CreateJsonObject(Resource->GetObjectField(FieldName)) : nullptr;
}

FString UMercuryJsonObject::GetStringField(const FString& FieldName) const
{
	return HasResource() ? Resource->GetStringField(FieldName) : TEXT("");
}

bool UMercuryJsonObject::HasTypedField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!HasResource())
		return false;

	switch (ValueType)
	{
	case EMercuryJsonValueType::None:
		return Resource->HasTypedField<EJson::None>(FieldName);

	case EMercuryJsonValueType::Null:
		return Resource->HasTypedField<EJson::Null>(FieldName);

	case EMercuryJsonValueType::Number:
		return Resource->HasTypedField<EJson::Number>(FieldName);

	case EMercuryJsonValueType::Boolean:
		return Resource->HasTypedField<EJson::Boolean>(FieldName);

	case EMercuryJsonValueType::String:
		return Resource->HasTypedField<EJson::String>(FieldName);

	case EMercuryJsonValueType::Array:
		return Resource->HasTypedField<EJson::Array>(FieldName);

	case EMercuryJsonValueType::Object:
		return Resource->HasTypedField<EJson::Object>(FieldName);

	default:
		UE_LOG(LogMercuryJson, Error, TEXT("Unknown value type: %d"), ValueType);
		return Resource->HasTypedField<EJson::None>(FieldName);
	}
}

UMercuryJsonObject* UMercuryJsonObject::SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array)
{
	if (!HasResource())
		return this;

	TArray<TSharedPtr<FJsonValue>>&& JsonValues = TArray<TSharedPtr<FJsonValue>>();
	for (const UMercuryJsonValue* const& MercuryJsonValue : Array)
	{
		JsonValues.Add(MercuryJsonValue->GetResource());
	}
	
	Resource->SetArrayField(FieldName, JsonValues);
	return this;
}

UMercuryJsonObject* UMercuryJsonObject::SetBoolField(const FString& FieldName, const bool bInValue)
{
	if (!HasResource())
		return this;
	
	Resource->SetBoolField(FieldName, bInValue);
	return this;
}

UMercuryJsonObject* UMercuryJsonObject::SetNumberField(const FString& FieldName, const double Number)
{
	if (!HasResource())
		return this;

	Resource->SetNumberField(FieldName, Number);
	return this;
}

UMercuryJsonObject* UMercuryJsonObject::SetObjectField(const FString& FieldName, const UMercuryJsonObject* const& JsonObject)
{
	if (!HasResource())
		return this;

	Resource->SetObjectField(FieldName, JsonObject->GetResource());
	return this;
}

UMercuryJsonObject* UMercuryJsonObject::SetStringField(const FString& FieldName, const FString& StringValue)
{
	if (!HasResource())
		return this;

	Resource->SetStringField(FieldName, StringValue);
	return this;
}

bool UMercuryJsonObject::TryGetArrayField(const FString& FieldName, TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();

	const TArray<TSharedPtr<FJsonValue>>*&& ArrayField = nullptr;
	const bool&& bGotArray = HasResource() && Resource->TryGetArrayField(FieldName, ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField ? *ArrayField: TArray<TSharedPtr<FJsonValue>>())
	{
		OutArray.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}
	return bGotArray;
}

bool UMercuryJsonObject::TryGetBoolField(const FString& FieldName, bool& OutBool) const
{
	OutBool = false;
	return HasResource() && Resource->TryGetBoolField(FieldName, OutBool);
}

bool UMercuryJsonObject::TryGetNumberField(const FString& FieldName, double& OutNumber) const
{
	OutNumber = 0.0;
	return HasResource() && Resource->TryGetNumberField(FieldName, OutNumber);
}

bool UMercuryJsonObject::TryGetObjectField(const FString& FieldName, UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>*&& ObjectField = nullptr;
	const bool&& bGotObject = HasResource() ? Resource->TryGetObjectField(FieldName, ObjectField) : false;

	OutObject->SetResource(ObjectField ? *ObjectField : nullptr);
	return bGotObject;
}

bool UMercuryJsonObject::TryGetStringField(const FString& FieldName, FString& OutString) const
{
	OutString = TEXT("");
	return HasResource() && Resource->TryGetStringField(FieldName, OutString);
}

bool UMercuryJsonObject::TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const
{
	OutArray.Empty();
	return HasResource() && Resource->TryGetEnumArrayField(FieldName, OutArray);
}

bool UMercuryJsonObject::TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const
{
	OutArray.Empty();
	return HasResource() && Resource->TryGetStringArrayField(FieldName, OutArray);
}
