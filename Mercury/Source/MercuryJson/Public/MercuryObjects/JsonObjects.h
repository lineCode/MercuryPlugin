// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Dom/JsonObject.h"
#include "MercuryEnums/JsonValueType.h"
#include "MercuryResourceOwner.h"

#include "JsonObjects.generated.h"

class UMercuryJsonValue;


/** JSON Object container that holds multiple JSON Values fields */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury JSON Object")
class MERCURYJSON_API UMercuryJsonObject : public UObject, public TResourceOwner<FJsonObject>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default JSON Object resource.
	 *
	 * @return The FJsonObject object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonObject
	 */
	virtual TSharedPtr<FJsonObject> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "JSON|Object", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/**
	 * Copies data from one JSON Object to another.
	 *
	 * @param Source JSON Object to copy data from
	 * @param Destination JSON Object to copy data to
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Duplicate", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Duplicate Copy Source Destination"
	))
	static void Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination);

	/** Obtains a dictionary of all the values inside this object. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Values", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Values",
		Keywords = "JSON Object Get Values Map Name Value"
	))
	virtual TMap<FString, UMercuryJsonValue*> GetValues() const;

	/**
	 * Sets all new values for this JSON Object.
	 *
	 * @param Value Dictionary of new values to use
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Values", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Values Map Name Value"
	))
	virtual UMercuryJsonObject* SetValues(const TMap<FString, UMercuryJsonValue*>& Value);

	/**
	 * Obtains JSON Value using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @param ValueType Type of JSON Value
	 * @return The JSON Value field or NULL if not found
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Field",
		Keywords = "JSON Object Get Field Name Value Type"
	))
	virtual UMercuryJsonValue* GetField(const FString& FieldName, EMercuryJsonValueType ValueType) const;

	/**
	 * Checks if a JSON Value exist using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return Does this JSON Object have a field with the given name?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Has Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Has Field Name Value"
	))
	virtual bool HasField(const FString& FieldName) const;

	/**
	 * Removes a JSON Value using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Remove Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Remove Field Name Value"
	))
	virtual void RemoveField(const FString& FieldName);

	/**
	 * Modifies a JSON Value using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param Value New JSON Value to replace the old one with
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Field Name Value"
	))
	virtual UMercuryJsonObject* SetField(const FString& FieldName, const UMercuryJsonValue* const& Value);

	/**
	 * Obtains a JSON Value's array field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return The array of the field
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Array Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Array Field",
		Keywords = "JSON Object Get Array Field Name Value"
	))
	virtual TArray<UMercuryJsonValue*> GetArrayField(const FString& FieldName) const;

	/**
	 * Obtains a JSON Value's Boolean field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return Is the Boolean of the field true?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Bool Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Bool Field",
		Keywords = "JSON Object Get Bool Boolean Field Name Value"
	))
	virtual bool GetBoolField(const FString& FieldName) const;

	/**
	 * Obtains a JSON Value's integer field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return The integer of the field
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Integer Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Integer Field",
		Keywords = "JSON Object Get Integer Natural Field Name Value"
	))
	virtual int32 GetIntegerField(const FString& FieldName) const;

	/**
	 * Obtains a JSON Value's real number field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return The real number of the field
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Number Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Number Field",
		Keywords = "JSON Object Get Number Float Double Real Field Name Value"
	))
	virtual double GetNumberField(const FString& FieldName) const;

	/**
	 * Obtains a JSON Value's JSON Object field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return The JSON Object of the field
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Object Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "Object Field",
		Keywords = "JSON Object Get Object Field Name Value"
	))
	virtual UMercuryJsonObject* GetObjectField(const FString& FieldName) const;

	/**
	 * Obtains a JSON Value's string field using its name.
	 *
	 * @param FieldName Name of JSON Value field
	 * @return The string of the field
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get String Field", Category = "JSON|Object", meta = (
		CompactNodeTitle = "String Field",
		Keywords = "JSON Object Get String Character Field Name Value"
	))
	virtual FString GetStringField(const FString& FieldName) const;

	/**
	 * Checks if there exists a JSON Value with a name and a type.
	 *
	 * @param FieldName Name of JSON Value field
	 * @param ValueType Type of JSON Value field
	 * @return Does the object have the specified value?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Has Typed Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Has Typed Field Name Value Type"
	))
	virtual bool HasTypedField(const FString& FieldName, EMercuryJsonValueType ValueType) const;

	/**
	 * Modifies a JSON Value's data using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param Array New array data
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Array Field Name Value"
	))
	virtual UMercuryJsonObject* SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array);

	/**
	 * Modifies a JSON Value's data using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param bInValue Is the new Boolean data true?
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Bool Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Bool Boolean Field Name Value"
	))
	virtual UMercuryJsonObject* SetBoolField(const FString& FieldName, bool bInValue);

	/**
	 * Modifies a JSON Value's data using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param Number New real number
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Number Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Number Float Double Real Field Name Value"
	))
	virtual UMercuryJsonObject* SetNumberField(const FString& FieldName, double Number);

	/**
	 * Modifies a JSON Value's data using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param JsonObject New JSON Object
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Object Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Object Field Name Value"
	))
	virtual UMercuryJsonObject* SetObjectField(const FString& FieldName, const UMercuryJsonObject* const& JsonObject);

	/**
	 * Modifies a JSON Value's data using its name.
	 *
	 * @param FieldName Name of JSON Value field to modify
	 * @param StringValue New string
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set String Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set String Character Field Name Value"
	))
	virtual UMercuryJsonObject* SetStringField(const FString& FieldName, const FString& StringValue);

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutArray Array data to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetArrayField(const FString& FieldName, TArray<UMercuryJsonValue*>& OutArray) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutBool Is the returned Boolean true?
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Bool Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Bool Boolean Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetBoolField(const FString& FieldName, bool& OutBool) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutNumber Real number to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Number Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Number Float Double Real Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetNumberField(const FString& FieldName, double& OutNumber) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutObject JSON Object data to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Object Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Object Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetObjectField(const FString& FieldName, UMercuryJsonObject*& OutObject) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutString String to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get String Character Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetStringField(const FString& FieldName, FString& OutString) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutArray Enum array data to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Enum Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Enum Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const;

	/**
	 * Tries to obtain a JSON Value's field data using its name if it exists.
	 *
	 * @param FieldName Name of JSON Value field to find
	 * @param OutArray String array data to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get String Character Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const;
};
