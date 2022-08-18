// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonLibrary.h"

#include "JsonValues.h"


UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject()
{
	return CreateJsonObject(nullptr);
}
UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject(FJsonObject* const& Resource)
{
	return CreateJsonObject(MakeShareable(Resource));
}
UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject(const TSharedPtr<FJsonObject>& Resource)
{
	UMercuryJsonObject* const&& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->SetResource(Resource ? Resource : JsonObject->CreateResource());
	return JsonObject;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValue()
{
	return CreateJsonValue(nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValue(const TSharedPtr<FJsonValue>& Resource)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateNullResource());
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueNumber(const double Value)
{
	return CreateJsonValueNumber(Value, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueNumber(
	const double& Value,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateNumberResource(Value));
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueBoolean(const bool bValue)
{
	return CreateJsonValueBoolean(bValue, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueBoolean(
	const bool& bValue,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateBooleanResource(bValue));
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueString(const FString& Value)
{
	return CreateJsonValueString(Value, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueString(
	const FString& Value,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateStringResource(Value));
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueNumberString(const FString& Value)
{
	return CreateJsonValueNumberString(Value, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueNumberString(
	const FString& Value,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateNumberStringResource(Value));
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueArray(const TArray<UMercuryJsonValue*>& Value)
{
	return CreateJsonValueArray(Value, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueArray(
	const TArray<UMercuryJsonValue*>& Value,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	if (Resource)
	{
		JsonValue->SetResource(Resource);
		return JsonValue;
	}

	TArray<TSharedPtr<FJsonValue>>&& ResourceValues = TArray<TSharedPtr<FJsonValue>>();
	for (const UMercuryJsonValue* const& ArrayValue : Value)
	{
		ResourceValues.Add(ArrayValue->GetResource());
	}
	
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateArrayResource(ResourceValues));
	return JsonValue;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueObject(UMercuryJsonObject* const& Value)
{
	return CreateJsonValueObject(Value, nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValueObject(
	UMercuryJsonObject* const& Value,
	const TSharedPtr<FJsonValue>& Resource
)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateObjectResource(Value->GetResource()));
	return JsonValue;
}
