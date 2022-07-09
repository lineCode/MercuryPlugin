// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonObject.h"

#include "MercuryJsonLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury JSON Blueprint Function Library")
class MERCURYJSON_API UMercuryJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Create JSON Object", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Object"
	))
	static UMercuryJsonObject* CreateJsonObject();
	static UMercuryJsonObject* CreateJsonObject(const FJsonObject& Resource);
	static UMercuryJsonObject* CreateJsonObject(const TSharedPtr<FJsonObject>& Resource);

	UFUNCTION(BlueprintCallable, DisplayName = "Create JSON Value", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value"
	))
	static UMercuryJsonValue* CreateJsonValue();
	static UMercuryJsonValue* CreateJsonValue(const FJsonValue& Resource);
	static UMercuryJsonValue* CreateJsonValue(const TSharedPtr<FJsonValue>& Resource);
};
