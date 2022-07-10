// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonObject.h"

#include "MercuryJsonLibrary.h"
#include "MercuryJsonValue.h"


TSharedPtr<FJsonObject> UMercuryJsonObject::CreateResource()
{
	return MakeShareable(new FJsonObject());
}

void UMercuryJsonObject::Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination)
{
	if (!Resource)
		return;

	Resource->Duplicate(Source->GetResource(), Destination->GetResource());
}

TMap<FString, UMercuryJsonValue*> UMercuryJsonObject::GetValues() const
{
	TMap<FString, UMercuryJsonValue*>&& MercuryJsonValues = TMap<FString, UMercuryJsonValue*>();
	if (!Resource)
		return MercuryJsonValues;
	
	for (const TTuple<FString, TSharedPtr<FJsonValue>>& JsonValues : Resource->Values)
	{
		MercuryJsonValues[JsonValues.Key] = UMercuryJsonLibrary::CreateJsonValue(JsonValues.Value);
	}
	return MercuryJsonValues;
}
UMercuryJsonObject* UMercuryJsonObject::SetValues(const TMap<FString, UMercuryJsonValue*>& Value)
{
	if (!Resource)
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
	if (!Resource)
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
	return Resource && Resource->HasField(FieldName);
}

void UMercuryJsonObject::RemoveField(const FString& FieldName)
{
	if (!Resource)
		return;
	
	Resource->RemoveField(FieldName);
}

void UMercuryJsonObject::SetField(const FString& FieldName, const UMercuryJsonValue* const& Value)
{
	if (!Resource)
		return;
	
	Resource->SetField(FieldName, Value->GetResource());
}

TArray<UMercuryJsonValue*> UMercuryJsonObject::GetArrayField(const FString& FieldName) const
{
	const TArray<TSharedPtr<FJsonValue>>&& ArrayField =
		Resource ? Resource->GetArrayField(FieldName) : TArray<TSharedPtr<FJsonValue>>();

	TArray<UMercuryJsonValue*>&& MercuryArrayField = TArray<UMercuryJsonValue*>();
	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField)
	{
		MercuryArrayField.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}

	return MercuryArrayField;
}

bool UMercuryJsonObject::GetBoolField(const FString& FieldName) const
{
	return Resource && Resource->GetBoolField(FieldName);
}

int32 UMercuryJsonObject::GetIntegerField(const FString& FieldName) const
{
	return Resource ? Resource->GetIntegerField(FieldName) : 0;
}

double UMercuryJsonObject::GetNumberField(const FString& FieldName) const
{
	return Resource ? Resource->GetNumberField(FieldName) : 0.0;
}

UMercuryJsonObject* UMercuryJsonObject::GetObjectField(const FString& FieldName) const
{
	return Resource ? UMercuryJsonLibrary::CreateJsonObject(Resource->GetObjectField(FieldName)) : nullptr;
}

FString UMercuryJsonObject::GetStringField(const FString& FieldName) const
{
	return Resource ? Resource->GetStringField(FieldName) : TEXT("");
}

bool UMercuryJsonObject::HasTypedField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!Resource)
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

void UMercuryJsonObject::SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array)
{
	if (!Resource)
		return;

	TArray<TSharedPtr<FJsonValue>>&& JsonValues = TArray<TSharedPtr<FJsonValue>>();
	for (const UMercuryJsonValue* const& MercuryJsonValue : Array)
	{
		JsonValues.Add(MercuryJsonValue->GetResource());
	}
	
	Resource->SetArrayField(FieldName, JsonValues);
}

void UMercuryJsonObject::SetBoolField(const FString& FieldName, const bool bInValue)
{
	if (!Resource)
		return;
	
	Resource->SetBoolField(FieldName, bInValue);
}

void UMercuryJsonObject::SetNumberField(const FString& FieldName, const double Number)
{
	if (!Resource)
		return;

	Resource->SetNumberField(FieldName, Number);
}

void UMercuryJsonObject::SetObjectField(const FString& FieldName, const UMercuryJsonObject* const& JsonObject)
{
	if (!Resource)
		return;

	Resource->SetObjectField(FieldName, JsonObject->GetResource());
}

void UMercuryJsonObject::SetStringField(const FString& FieldName, const FString& StringValue)
{
	if (!Resource)
		return;

	Resource->SetStringField(FieldName, StringValue);
}

bool UMercuryJsonObject::TryGetArrayField(const FString& FieldName, TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();

	const TArray<TSharedPtr<FJsonValue>>*&& ArrayField = nullptr;
	const bool&& bGotArray = Resource && Resource->TryGetArrayField(FieldName, ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField ? *ArrayField: TArray<TSharedPtr<FJsonValue>>())
	{
		OutArray.Add(UMercuryJsonLibrary::CreateJsonValue(JsonValue));
	}
	return bGotArray;
}

bool UMercuryJsonObject::TryGetBoolField(const FString& FieldName, bool& OutBool) const
{
	OutBool = false;
	return Resource && Resource->TryGetBoolField(FieldName, OutBool);
}

bool UMercuryJsonObject::TryGetNumberField(const FString& FieldName, double& OutNumber) const
{
	OutNumber = 0.0;
	return Resource && Resource->TryGetNumberField(FieldName, OutNumber);
}

bool UMercuryJsonObject::TryGetObjectField(const FString& FieldName, UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>*&& ObjectField = nullptr;
	const bool&& bGotObject = Resource ? Resource->TryGetObjectField(FieldName, ObjectField) : false;

	OutObject->GetResource() = ObjectField ? *ObjectField : nullptr;
	return bGotObject;
}

bool UMercuryJsonObject::TryGetStringField(const FString& FieldName, FString& OutString) const
{
	OutString = TEXT("");
	return Resource && Resource->TryGetStringField(FieldName, OutString);
}

bool UMercuryJsonObject::TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const
{
	OutArray.Empty();
	return Resource && Resource->TryGetEnumArrayField(FieldName, OutArray);
}

bool UMercuryJsonObject::TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const
{
	OutArray.Empty();
	return Resource && Resource->TryGetStringArrayField(FieldName, OutArray);
}
