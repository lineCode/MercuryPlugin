// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "JsonObjects.h"
#include "Kismet/BlueprintFunctionLibrary.h"

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
		Keywords = "Create JSON Value Null"
	))
	static UMercuryJsonValue* CreateJsonValue();
	static UMercuryJsonValue* CreateJsonValue(const TSharedPtr<FJsonValue>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Number)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Number"
	))
	static UMercuryJsonValue* CreateJsonValueNumber(double Value);
	static UMercuryJsonValue* CreateJsonValueNumber(const double& Value, const TSharedPtr<FJsonValue>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Boolean)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Boolean"
	))
	static UMercuryJsonValue* CreateJsonValueBoolean(bool bValue);
	static UMercuryJsonValue* CreateJsonValueBoolean(const bool& bValue, const TSharedPtr<FJsonValue>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (String)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value String"
	))
	static UMercuryJsonValue* CreateJsonValueString(const FString& Value);
	static UMercuryJsonValue* CreateJsonValueString(const FString& Value, const TSharedPtr<FJsonValue>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Number String)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Number String"
	))
	static UMercuryJsonValue* CreateJsonValueNumberString(const FString& Value);
	static UMercuryJsonValue* CreateJsonValueNumberString(const FString& Value, const TSharedPtr<FJsonValue>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Array)", Category = "Mercury|JSON", meta = (
		AutoCreateRefTerm = "Value",
		Keywords = "Create JSON Value Array"
	))
	static UMercuryJsonValue* CreateJsonValueArray(const TArray<UMercuryJsonValue*>& Value);
	static UMercuryJsonValue* CreateJsonValueArray(
		const TArray<UMercuryJsonValue*>& Value,
		const TSharedPtr<FJsonValue>& Resource
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Object)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Object"
	))
	static UMercuryJsonValue* CreateJsonValueObject(UMercuryJsonObject* const& Value);
	static UMercuryJsonValue* CreateJsonValueObject(
		UMercuryJsonObject* const& Value,
		const TSharedPtr<FJsonValue>& Resource
	);
};
