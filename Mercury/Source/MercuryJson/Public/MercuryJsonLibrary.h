// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "JsonObjects.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MercuryJsonLibrary.generated.h"


/** Library for creating Mercury JSON structures and (de)serializing them */
UCLASS(Abstract, DisplayName = "Mercury JSON Blueprint Function Library")
class MERCURYJSON_API UMercuryJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Creates a JSON Object with a default resource.
	 *
	 * @return The resulting UMercuryJsonObject object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Object", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Object"
	))
	static UMercuryJsonObject* CreateJsonObject();

	/**
	 * Creates a JSON Object using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonObject object or NULL if failed
	 */
	static UMercuryJsonObject* CreateJsonObject(FJsonObject* const& Resource);

	/**
	 * Creates a JSON Object using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonObject object or NULL if failed
	 */
	static UMercuryJsonObject* CreateJsonObject(const TSharedPtr<FJsonObject>& Resource);

	/**
	 * Creates a JSON NULL Value.
	 *
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Null"
	))
	static UMercuryJsonValue* CreateJsonValue();

	/**
	 * Creates a typed JSON Value using an existing resource or a JSON NULL Value.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValue(const TSharedPtr<FJsonValue>& Resource);

	/**
	 * Creates a JSON Number Value with a default resource.
	 *
	 * @param Value Real number
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Number)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Number"
	))
	static UMercuryJsonValue* CreateJsonValueNumber(double Value);

	/**
	 * Creates a JSON Number Value using an existing resource.
	 *
	 * @param Value Real number
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueNumber(const double& Value, const TSharedPtr<FJsonValue>& Resource);

	/**
	 * Creates a JSON Boolean Value with a default resource.
	 *
	 * @param bValue Is the Boolean true?
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Boolean)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Boolean"
	))
	static UMercuryJsonValue* CreateJsonValueBoolean(bool bValue);

	/**
	 * Creates a JSON Boolean Value using an existing resource.
	 *
	 * @param bValue Is the Boolean true?
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueBoolean(const bool& bValue, const TSharedPtr<FJsonValue>& Resource);

	/**
	 * Creates a JSON String Value with a default resource.
	 *
	 * @param Value Any FString object
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (String)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value String"
	))
	static UMercuryJsonValue* CreateJsonValueString(const FString& Value);

	/**
	 * Creates a JSON String Value using an existing resource.
	 *
	 * @param Value Any FString object
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueString(const FString& Value, const TSharedPtr<FJsonValue>& Resource);

	/**
	 * Creates a JSON Number String Value with a default resource.
	 *
	 * @param Value Number as an FString object
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Number String)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Number String"
	))
	static UMercuryJsonValue* CreateJsonValueNumberString(const FString& Value);
	
	/**
	 * Creates a JSON Number String Value using an existing resource.
	 *
	 * @param Value Number as an FString object
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueNumberString(const FString& Value, const TSharedPtr<FJsonValue>& Resource);

	/**
	 * Creates a JSON Array Value with a default resource.
	 *
	 * @param Value Array of other JSON Values
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Array)", Category = "Mercury|JSON", meta = (
		AutoCreateRefTerm = "Value",
		Keywords = "Create JSON Value Array"
	))
	static UMercuryJsonValue* CreateJsonValueArray(const TArray<UMercuryJsonValue*>& Value);

	/**
	 * Creates a JSON Array Value using an existing resource.
	 *
	 * @param Value Array of other JSON Values
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueArray(
		const TArray<UMercuryJsonValue*>& Value,
		const TSharedPtr<FJsonValue>& Resource
	);

	/**
	 * Creates a JSON Object Value with a default resource.
	 *
	 * @param Value JSON Object
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create JSON Value (Object)", Category = "Mercury|JSON", meta = (
		Keywords = "Create JSON Value Object"
	))
	static UMercuryJsonValue* CreateJsonValueObject(UMercuryJsonObject* const& Value);

	/**
	 * Creates a JSON Object Value using an existing resource.
	 *
	 * @param Value JSON Object
	 * @param Resource Given resource
	 * @return The resulting UMercuryJsonValue object or NULL if failed
	 */
	static UMercuryJsonValue* CreateJsonValueObject(
		UMercuryJsonObject* const& Value,
		const TSharedPtr<FJsonValue>& Resource
	);

	/**
	 * Converts a JSON Object into a string.
	 *
	 * @param JsonObject Container for JSON data
	 * @param OutputString Resulting JSON data in string format
	 * @return Did the conversion succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Serialize JSON", Category = "Mercury|JSON", meta = (
		Keywords = "Serialize Serialise JSON Object Output String"
	))
	static UPARAM(DisplayName = "Success") bool
	SerializeJson(const UMercuryJsonObject* const& JsonObject, FString& OutputString);

	/**
	 * Converts a string into a JSON Object.
	 *
	 * @param JsonString JSON data in string format
	 * @param OutputObject Resulting container for JSON data
	 * @return Did the conversion succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Deserialize JSON", Category = "Mercury|JSON", meta = (
		Keywords = "Deserialize Deserialise JSON String Output Object"
	))
	static UPARAM(DisplayName = "Success") bool
	DeserializeJson(const FString& JsonString, UMercuryJsonObject*& OutputObject);
};
