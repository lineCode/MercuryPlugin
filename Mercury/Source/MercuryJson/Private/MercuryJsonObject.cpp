// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonObject.h"

#include "MercuryJson.h"
#include "MercuryJsonValue.h"


UMercuryJsonObject::UMercuryJsonObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FJsonObject());
}

void UMercuryJsonObject::Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination)
{
	if (!Resource)
		return;

	Resource->Duplicate(Source->GetResource(), Destination->GetResource());
}

TMap<FString, UMercuryJsonValue*> UMercuryJsonObject::GetValues() const
{
	if (!Resource)
		return TMap<FString, UMercuryJsonValue*>();
	
	TMap<FString, UMercuryJsonValue*> MercuryJsonValues;
	for (const TTuple<FString, TSharedPtr<FJsonValue>>& JsonValues : Resource->Values)
	{
		MercuryJsonValues[JsonValues.Key] = NewObject<UMercuryJsonValue>();
		MercuryJsonValues[JsonValues.Key]->GetResource() = JsonValues.Value;
	}
	return MercuryJsonValues;
}

UMercuryJsonValue* UMercuryJsonObject::GetField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!Resource)
		return nullptr;

	TSharedPtr<FJsonValue> JsonValue;
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
		UE_LOG(LogMercuryJson, Fatal, TEXT("Invalid Mercury JSON Value Type enum passed in!"));
	}
	
	UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
	MercuryJsonValue->GetResource() = JsonValue;
	return MercuryJsonValue;
}

bool UMercuryJsonObject::HasField(const FString& FieldName) const
{
	return Resource ? Resource->HasField(FieldName) : false;
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
	const TArray<TSharedPtr<FJsonValue>>& ArrayField =
		Resource ? Resource->GetArrayField(FieldName) : TArray<TSharedPtr<FJsonValue>>();

	TArray<UMercuryJsonValue*> MercuryArrayField;
	for (const TSharedPtr<FJsonValue>& JsonValue : ArrayField)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetResource() = JsonValue;
		MercuryArrayField.Add(MercuryJsonValue);
	}

	return MercuryArrayField;
}

bool UMercuryJsonObject::GetBoolField(const FString& FieldName) const
{
	return Resource ? Resource->GetBoolField(FieldName) : false;
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
	UMercuryJsonObject* const& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->GetResource() = Resource ? Resource->GetObjectField(FieldName) : nullptr;
	return JsonObject;
}

FString UMercuryJsonObject::GetStringField(const FString& FieldName) const
{
	return Resource ? Resource->GetStringField(FieldName) : TEXT("");
}

bool UMercuryJsonObject::HasTypedField(const FString& FieldName, const EMercuryJsonValueType ValueType) const
{
	if (!Resource)
		return false;

	bool bHasTypedField = false;
	switch (ValueType)
	{
	case EMercuryJsonValueType::None:
		bHasTypedField = Resource->HasTypedField<EJson::None>(FieldName);
		break;

	case EMercuryJsonValueType::Null:
		bHasTypedField = Resource->HasTypedField<EJson::Null>(FieldName);
		break;

	case EMercuryJsonValueType::Number:
		bHasTypedField = Resource->HasTypedField<EJson::Number>(FieldName);
		break;

	case EMercuryJsonValueType::Boolean:
		bHasTypedField = Resource->HasTypedField<EJson::Boolean>(FieldName);
		break;

	case EMercuryJsonValueType::String:
		bHasTypedField = Resource->HasTypedField<EJson::String>(FieldName);
		break;

	case EMercuryJsonValueType::Array:
		bHasTypedField = Resource->HasTypedField<EJson::Array>(FieldName);
		break;

	case EMercuryJsonValueType::Object:
		bHasTypedField = Resource->HasTypedField<EJson::Object>(FieldName);
		break;

	default:
		UE_LOG(LogMercuryJson, Fatal, TEXT("Invalid Mercury JSON Value Type enum passed in!"));
	}
	
	return bHasTypedField;
}

void UMercuryJsonObject::SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array)
{
	if (!Resource)
		return;

	TArray<TSharedPtr<FJsonValue>> JsonValues;
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
	if (!Resource)
		return false;
	
	const TArray<TSharedPtr<FJsonValue>>* ArrayField;
	const bool& bGotArray = Resource->TryGetArrayField(FieldName, ArrayField);

	for (const TSharedPtr<FJsonValue>& JsonValue : *ArrayField)
	{
		UMercuryJsonValue* const& MercuryJsonValue = NewObject<UMercuryJsonValue>();
		MercuryJsonValue->GetResource() = JsonValue;
		OutArray.Add(MercuryJsonValue);
	}
	return bGotArray;
}

bool UMercuryJsonObject::TryGetBoolField(const FString& FieldName, bool& OutBool) const
{
	OutBool = false;
	if (!Resource)
		return false;
	
	return Resource->TryGetBoolField(FieldName, OutBool);
}

bool UMercuryJsonObject::TryGetNumberField(const FString& FieldName, double& OutNumber) const
{
	OutNumber = 0.0;
	if (!Resource)
		return false;
	
	return Resource->TryGetNumberField(FieldName, OutNumber);
}

bool UMercuryJsonObject::TryGetObjectField(const FString& FieldName, UMercuryJsonObject*& OutObject) const
{
	const TSharedPtr<FJsonObject>* ObjectField = nullptr;
	const bool& bGotObject = Resource ? Resource->TryGetObjectField(FieldName, ObjectField) : false;

	OutObject->GetResource() = bGotObject && ObjectField ? *ObjectField : nullptr;
	return bGotObject;
}

bool UMercuryJsonObject::TryGetStringField(const FString& FieldName, FString& OutString) const
{
	OutString = TEXT("");
	if (!Resource)
		return false;
	
	return Resource->TryGetStringField(FieldName, OutString);
}

bool UMercuryJsonObject::TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const
{
	OutArray.Empty();
	if (!Resource)
		return false;
	
	return Resource->TryGetEnumArrayField(FieldName, OutArray);
}

bool UMercuryJsonObject::TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const
{
	OutArray.Empty();
	if (!Resource)
		return false;
	
	return Resource->TryGetStringArrayField(FieldName, OutArray);
}
