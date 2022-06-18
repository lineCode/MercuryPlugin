// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonObject.h"

#include "MercuryJson.h"
#include "MercuryJsonValue.h"


UMercuryJsonObject::UMercuryJsonObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Reference = MakeShareable(new FJsonObject());
}

void UMercuryJsonObject::Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination)
{
	if (!Reference)
		return;

	Reference->Duplicate(Source->GetReference(), Destination->GetReference());
}

TMap<FString, UMercuryJsonValue*> UMercuryJsonObject::GetValues() const
{
	if (!Reference)
		return TMap<FString, UMercuryJsonValue*>();
	
	TMap<FString, UMercuryJsonValue*> MercuryJsonValues;
	for (const TTuple<FString, TSharedPtr<FJsonValue>>& JsonValues : Reference->Values)
	{
		MercuryJsonValues[JsonValues.Key] = NewObject<UMercuryJsonValue>();
		MercuryJsonValues[JsonValues.Key]->GetReference() = JsonValues.Value;
	}
	return MercuryJsonValues;
}

UMercuryJsonValue* UMercuryJsonObject::GetField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!Reference)
		return nullptr;

	TSharedPtr<FJsonValue> JsonValue;
	switch (ValueType)
	{
	case EMercuryJsonValueType::None:
		JsonValue = Reference->GetField<EJson::None>(FieldName);
		break;

	case EMercuryJsonValueType::Null:
		JsonValue = Reference->GetField<EJson::Null>(FieldName);
		break;

	case EMercuryJsonValueType::Number:
		JsonValue = Reference->GetField<EJson::Number>(FieldName);
		break;

	case EMercuryJsonValueType::Boolean:
		JsonValue = Reference->GetField<EJson::Boolean>(FieldName);
		break;

	case EMercuryJsonValueType::String:
		JsonValue = Reference->GetField<EJson::String>(FieldName);
		break;

	case EMercuryJsonValueType::Array:
		JsonValue = Reference->GetField<EJson::Array>(FieldName);
		break;

	case EMercuryJsonValueType::Object:
		JsonValue = Reference->GetField<EJson::Object>(FieldName);
		break;

	default:
		UE_LOG(LogMercuryJson, Fatal, TEXT("Invalid Mercury JSON Value Type enum passed in!"));
	}
	
	UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
	MercuryJsonValue->GetReference() = JsonValue;
	return MercuryJsonValue;
}

bool UMercuryJsonObject::HasField(const FString& FieldName) const
{
	return Reference ? Reference->HasField(FieldName) : false;
}

void UMercuryJsonObject::RemoveField(const FString& FieldName)
{
	if (!Reference)
		return;
	
	Reference->RemoveField(FieldName);
}

void UMercuryJsonObject::SetField(const FString& FieldName, const UMercuryJsonValue* const& Value)
{
	if (!Reference)
		return;
	
	Reference->SetField(FieldName, Value->GetReference());
}

TArray<UMercuryJsonValue*> UMercuryJsonObject::GetArrayField(const FString& FieldName) const
{
	const TArray<TSharedPtr<FJsonValue>>& ArrayField =
		Reference ? Reference->GetArrayField(FieldName) : TArray<TSharedPtr<FJsonValue>>();

	TArray<UMercuryJsonValue*> MercuryArrayField;
	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetReference() = JsonValue;
		MercuryArrayField.Add(MercuryJsonValue);
	}

	return MercuryArrayField;
}

bool UMercuryJsonObject::GetBoolField(const FString& FieldName) const
{
	return Reference ? Reference->GetBoolField(FieldName) : false;
}

int32 UMercuryJsonObject::GetIntegerField(const FString& FieldName) const
{
	return Reference ? Reference->GetIntegerField(FieldName) : 0;
}

double UMercuryJsonObject::GetNumberField(const FString& FieldName) const
{
	return Reference ? Reference->GetNumberField(FieldName) : 0.0;
}

UMercuryJsonObject* UMercuryJsonObject::GetObjectField(const FString& FieldName) const
{
	UMercuryJsonObject* const& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->GetReference() = Reference ? Reference->GetObjectField(FieldName) : nullptr;
	return JsonObject;
}

FString UMercuryJsonObject::GetStringField(const FString& FieldName) const
{
	return Reference ? Reference->GetStringField(FieldName) : TEXT("");
}

bool UMercuryJsonObject::HasTypedField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!Reference)
		return false;

	bool bHasTypedField = false;
	switch (ValueType)
	{
	case EMercuryJsonValueType::None:
		bHasTypedField = Reference->HasTypedField<EJson::None>(FieldName);
		break;

	case EMercuryJsonValueType::Null:
		bHasTypedField = Reference->HasTypedField<EJson::Null>(FieldName);
		break;

	case EMercuryJsonValueType::Number:
		bHasTypedField = Reference->HasTypedField<EJson::Number>(FieldName);
		break;

	case EMercuryJsonValueType::Boolean:
		bHasTypedField = Reference->HasTypedField<EJson::Boolean>(FieldName);
		break;

	case EMercuryJsonValueType::String:
		bHasTypedField = Reference->HasTypedField<EJson::String>(FieldName);
		break;

	case EMercuryJsonValueType::Array:
		bHasTypedField = Reference->HasTypedField<EJson::Array>(FieldName);
		break;

	case EMercuryJsonValueType::Object:
		bHasTypedField = Reference->HasTypedField<EJson::Object>(FieldName);
		break;

	default:
		UE_LOG(LogMercuryJson, Fatal, TEXT("Invalid Mercury JSON Value Type enum passed in!"));
	}
	
	return bHasTypedField;
}

void UMercuryJsonObject::SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array)
{
	if (!Reference)
		return;

	TArray<TSharedPtr<FJsonValue>> JsonValues;
	for (const UMercuryJsonValue* const& MercuryJsonValue : Array)
	{
		JsonValues.Add(MercuryJsonValue->GetReference());
	}
	
	Reference->SetArrayField(FieldName, JsonValues);
}

void UMercuryJsonObject::SetBoolField(const FString& FieldName, const bool bInValue)
{
	if (!Reference)
		return;
	
	Reference->SetBoolField(FieldName, bInValue);
}

void UMercuryJsonObject::SetNumberField(const FString& FieldName, const double Number)
{
	if (!Reference)
		return;

	Reference->SetNumberField(FieldName, Number);
}

void UMercuryJsonObject::SetObjectField(const FString& FieldName, const UMercuryJsonObject* const& JsonObject)
{
	if (!Reference)
		return;

	Reference->SetObjectField(FieldName, JsonObject->GetReference());
}

void UMercuryJsonObject::SetStringField(const FString& FieldName, const FString& StringValue)
{
	if (!Reference)
		return;

	Reference->SetStringField(FieldName, StringValue);
}

bool UMercuryJsonObject::TryGetArrayField(const FString& FieldName, TArray<UMercuryJsonValue*>& OutArray) const
{
	OutArray.Empty();
	if (!Reference)
		return false;
	
	const TArray<TSharedPtr<FJsonValue>>* ArrayField;
	const bool& bGotArray = Reference->TryGetArrayField(FieldName, ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : *ArrayField)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetReference() = JsonValue;
		OutArray.Add(MercuryJsonValue);
	}
	return bGotArray;
}

bool UMercuryJsonObject::TryGetBoolField(const FString& FieldName, bool& OutBool) const
{
	return Reference ? Reference->TryGetBoolField(FieldName, OutBool) : false;
}

bool UMercuryJsonObject::TryGetNumberField(const FString& FieldName, double& OutNumber) const
{
	return Reference ? Reference->TryGetNumberField(FieldName, OutNumber) : false;
}

bool UMercuryJsonObject::TryGetObjectField(const FString& FieldName, UMercuryJsonObject* const& OutObject) const
{
	if (!Reference)
		return false;

	const TSharedPtr<FJsonObject>* ObjectField;
	const bool& bGotObject = Reference->TryGetObjectField(FieldName, ObjectField);

	OutObject->GetReference() = *ObjectField;
	return bGotObject;
}

bool UMercuryJsonObject::TryGetStringField(const FString& FieldName, FString& OutString) const
{
	return Reference ? Reference->TryGetStringField(FieldName, OutString) : false;
}

bool UMercuryJsonObject::TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const
{
	return Reference ? Reference->TryGetEnumArrayField(FieldName, OutArray) : false;
}

bool UMercuryJsonObject::TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const
{
	return Reference ? Reference->TryGetStringArrayField(FieldName, OutArray) : false;
}
