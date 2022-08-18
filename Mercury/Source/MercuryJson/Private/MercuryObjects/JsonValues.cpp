// Copyright (c) 2022 Kaya Adrian

#include "JsonValues.h"

#include "JsonObjects.h"
#include "MercuryJsonLibrary.h"


TSharedPtr<FJsonValue> UMercuryJsonValue::CreateResource(const std::tuple<EMercuryJsonValueType, std::any>& Arguments)
{
	const std::any& JsonValueParam = std::get<1>(Arguments);
	
	switch (const EMercuryJsonValueType& ValueType = std::get<0>(Arguments))
	{
	case EMercuryJsonValueType::None:
		return nullptr;

	case EMercuryJsonValueType::Null:
		return CreateNullResource();

	case EMercuryJsonValueType::Number:
		return JsonValueParam.type() == typeid(double) ?
			CreateNumberResource(std::any_cast<double>(JsonValueParam)) : nullptr;

	case EMercuryJsonValueType::Boolean:
		return JsonValueParam.type() == typeid(bool) ?
			CreateBooleanResource(std::any_cast<bool>(JsonValueParam)) : nullptr;

	case EMercuryJsonValueType::String:
		return JsonValueParam.type() == typeid(FString) ?
			CreateStringResource(std::any_cast<FString>(JsonValueParam)) : nullptr;

	case EMercuryJsonValueType::Array:
		return JsonValueParam.type() == typeid(TArray<TSharedPtr<FJsonValue>>) ?
			CreateArrayResource(std::any_cast<TArray<TSharedPtr<FJsonValue>>>(JsonValueParam)) : nullptr;

	case EMercuryJsonValueType::Object:
		return JsonValueParam.type() == typeid(TSharedPtr<FJsonObject>) ?
			CreateObjectResource(std::any_cast<TSharedPtr<FJsonObject>>(JsonValueParam)) : nullptr;

	default:
		UE_LOG(LogMercuryJson, Error, TEXT("Unknown value type: %d"), ValueType);
	}

	return nullptr;
}


TSharedPtr<FJsonValueNull> UMercuryJsonValue::CreateNullResource()
{
	return MakeShareable(new FJsonValueNull());
}
TSharedPtr<FJsonValueNumber> UMercuryJsonValue::CreateNumberResource(const std::tuple<double>& Arguments)
{
	return MakeShareable(new FJsonValueNumber(std::get<0>(Arguments)));
}
TSharedPtr<FJsonValueBoolean> UMercuryJsonValue::CreateBooleanResource(const std::tuple<bool>& Arguments)
{
	return MakeShareable(new FJsonValueBoolean(std::get<0>(Arguments)));
}
TSharedPtr<FJsonValueString> UMercuryJsonValue::CreateStringResource(const std::tuple<FString>& Arguments)
{
	return MakeShareable(new FJsonValueString(std::get<0>(Arguments)));
}
TSharedPtr<FJsonValueNumberString> UMercuryJsonValue::CreateNumberStringResource(const std::tuple<FString>& Arguments)
{
	return MakeShareable(new FJsonValueNumberString(std::get<0>(Arguments)));
}
TSharedPtr<FJsonValueArray> UMercuryJsonValue::CreateArrayResource(
	const std::tuple<TArray<TSharedPtr<FJsonValue>>>& Arguments
)
{
	return MakeShareable(new FJsonValueArray(std::get<0>(Arguments)));
}
TSharedPtr<FJsonValueObject> UMercuryJsonValue::CreateObjectResource(
	const std::tuple<TSharedPtr<FJsonObject>>& Arguments
)
{
	return MakeShareable(new FJsonValueObject(std::get<0>(Arguments)));
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

	return std::move(MercuryJsonValues);
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
