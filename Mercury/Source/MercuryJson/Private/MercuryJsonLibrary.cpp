// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonLibrary.h"

#include "MercuryJsonValue.h"


UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject()
{
	return CreateJsonObject(nullptr);
}
UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject(const FJsonObject& Resource)
{
	UMercuryJsonObject* const&& JsonObject = NewObject<UMercuryJsonObject>();
	*JsonObject->GetResource() = Resource;
	return JsonObject;
}
UMercuryJsonObject* UMercuryJsonLibrary::CreateJsonObject(const TSharedPtr<FJsonObject>& Resource)
{
	UMercuryJsonObject* const&& JsonObject = NewObject<UMercuryJsonObject>();
	JsonObject->GetResource() = Resource ? Resource : JsonObject->CreateResource();
	return JsonObject;
}

UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValue()
{
	return CreateJsonValue(nullptr);
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValue(const FJsonValue& Resource)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	*JsonValue->GetResource() = Resource;
	return JsonValue;
}
UMercuryJsonValue* UMercuryJsonLibrary::CreateJsonValue(const TSharedPtr<FJsonValue>& Resource)
{
	UMercuryJsonValue* const&& JsonValue = NewObject<UMercuryJsonValue>();
	JsonValue->GetResource() = Resource ? Resource : JsonValue->CreateResource();
	return JsonValue;
}
