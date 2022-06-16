// Copyright (c) 2022 Kaya Adrian

#include "MercuryJsonLibrary.h"


FMercuryJsonObject UMercuryJsonLibrary::MakeJson()
{
	return FMercuryJsonObject();
}

FString UMercuryJsonLibrary::JsonObjectToCondensedString(const FMercuryJsonObject& JsonObject)
{
	return JsonObjectToString<TCHAR, TCondensedJsonPrintPolicy>(JsonObject.Reference);
}

FString UMercuryJsonLibrary::JsonObjectToPrettyString(const FMercuryJsonObject& JsonObject)
{
	return JsonObjectToString<TCHAR, TPrettyJsonPrintPolicy>(JsonObject.Reference);
}
