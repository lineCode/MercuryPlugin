// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonLibrary.h"

#include "MercuryJsonValue.h"


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
	JsonValue->SetResource(Resource ? Resource : JsonValue->CreateResource());
	return JsonValue;
}
