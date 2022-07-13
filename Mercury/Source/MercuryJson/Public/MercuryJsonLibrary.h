// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "JsonObject.h"

#include "MercuryJsonLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury JSON Blueprint Function Library")
class MERCURYJSON_API UMercuryJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Object", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Object"
	))
	static UMercuryJsonObject* CreateJsonObject();
	static UMercuryJsonObject* CreateJsonObject(FJsonObject* const& Resource);
	static UMercuryJsonObject* CreateJsonObject(const TSharedPtr<FJsonObject>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value"
	))
	static UMercuryJsonValue* CreateJsonValue();
	static UMercuryJsonValue* CreateJsonValue(const TSharedPtr<FJsonValue>& Resource);
};
