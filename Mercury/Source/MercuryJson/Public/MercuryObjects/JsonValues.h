// Copyright (c) 2022 Kaya Adrian

#pragma once

#include <any>

#include "Dom/JsonValue.h"
#include "MercuryEnums/JsonValueType.h"
#include "MercuryResourceOwner.h"

#include "JsonValues.generated.h"

class UMercuryJsonObject;


/** JSON Value container that holds a field's name and data of all types */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury JSON Value")
class MERCURYJSON_API UMercuryJsonValue : public UObject,
public TResourceOwner<FJsonValue, EMercuryJsonValueType, std::any>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default JSON Value resource.
	 *
	 * @param Arguments Tuple containing the JSON Value's type and its matching data
	 * @return The FJsonValue object resource
	 * 
	 * @see CreateNullResource,\n
	 * CreateNumberResource,\n
	 * CreateBooleanResource,\n
	 * CreateStringResource,\n
	 * CreateNumberStringResource,\n
	 * CreateArrayResource,\n
	 * CreateObjectResource
	 */
	virtual TSharedPtr<FJsonValue> CreateResource(
		const std::tuple<EMercuryJsonValueType, std::any>& Arguments
	) override;

	/**
	 * Creates a JSON NULL Value resource.
	 *
	 * @return The FJsonValueNull object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValue
	 */
	virtual TSharedPtr<FJsonValueNull> CreateNullResource();

	/**
	 * Creates a JSON Number Value resource.
	 *
	 * @param Argument Real number value
	 * @return The FJsonValueNumber object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueNumber
	 */
	virtual TSharedPtr<FJsonValueNumber> CreateNumberResource(const double& Argument);

	/**
	 * Creates a JSON Boolean Value resource.
	 *
	 * @param bArgument Is the Boolean value true?
	 * @return The FJsonValueBoolean object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueBoolean
	 */
	virtual TSharedPtr<FJsonValueBoolean> CreateBooleanResource(const bool& bArgument);

	/**
	 * Creates a JSON String Value resource.
	 *
	 * @param Argument String value
	 * @return The FJsonValueString object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueString
	 */
	virtual TSharedPtr<FJsonValueString> CreateStringResource(const FString& Argument);

	/**
	 * Creates a JSON Number String Value resource.
	 *
	 * @param Argument Number string value
	 * @return The FJsonValueNumberString object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueNumberString
	 */
	virtual TSharedPtr<FJsonValueNumberString> CreateNumberStringResource(const FString& Argument);

	/**
	 * Creates a JSON Array Value resource.
	 *
	 * @param Argument Array value
	 * @return The FJsonValueArray object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueArray
	 */
	virtual TSharedPtr<FJsonValueArray> CreateArrayResource(const TArray<TSharedPtr<FJsonValue>>& Argument);

	/**
	 * Creates a JSON Object Value resource.
	 *
	 * @param Argument JSON Object value
	 * @return The FJsonValueObject object resource
	 * 
	 * @see UMercuryJsonLibrary::CreateJsonValueObject
	 */
	virtual TSharedPtr<FJsonValueObject> CreateObjectResource(const TSharedPtr<FJsonObject>& Argument);

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "JSON|Value", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the type of held data. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Type", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Type",
		Keywords = "JSON Value Get Type"
	))
	virtual EMercuryJsonValueType GetType() const;

	/**
	 * Modifies the type of data to hold.
	 *
	 * @param Value New field type
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Type", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Set Type"
	))
	virtual UMercuryJsonValue* SetType(EMercuryJsonValueType Value);

	/** Obtains data as an array. */
	UFUNCTION(BlueprintPure, DisplayName = "As Array", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "JSON Value As Array"
	))
	virtual TArray<UMercuryJsonValue*> AsArray() const;

	/** Obtains data as a Boolean. */
	UFUNCTION(BlueprintPure, DisplayName = "As Bool", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "JSON Value As Bool Boolean"
	))
	virtual bool AsBool() const;

	/** Obtains data as a real number. */
	UFUNCTION(BlueprintPure, DisplayName = "As Number", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "JSON Value As Number Float Double Real"
	))
	virtual double AsNumber() const;

	/** Obtains data as a JSON Object. */
	UFUNCTION(BlueprintPure, DisplayName = "As Object", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "JSON Value As Object"
	))
	virtual UMercuryJsonObject* AsObject() const;

	/** Obtains data as a string. */
	UFUNCTION(BlueprintPure, DisplayName = "As String", Category = "JSON|Value", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "JSON Value As String Character"
	))
	virtual FString AsString() const;

	/** Checks if the JSON Value type is None or Null. */
	UFUNCTION(BlueprintPure, DisplayName = "Is Null", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Is Null"
	))
	virtual bool IsNull() const;

	/**
	 * Obtains data as an array.
	 *
	 * @param Value Array containing resulting data
	 */
	virtual void AsArgumentType(TArray<UMercuryJsonValue*>& Value) const;

	/**
	 * Obtains data as a Boolean.
	 *
	 * @param Value Is the resulting data true?
	 */
	virtual void AsArgumentType(bool& Value) const;

	/**
	 * Obtains data as a real number.
	 *
	 * @param Value Real number containing resulting data
	 */
	virtual void AsArgumentType(double& Value) const;

	/**
	 * Obtains data as a JSON Object.
	 *
	 * @param Value JSON Object containing resulting data
	 */
	virtual void AsArgumentType(UMercuryJsonObject*& Value) const;

	/**
	 * Obtains data as a string.
	 *
	 * @param Value String containing resulting data
	 */
	virtual void AsArgumentType(FString& Value) const;

	/**
	 * Tries to obtain field data as an array.
	 *
	 * @param OutArray Array to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Array Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Array"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetArray(TArray<UMercuryJsonValue*>& OutArray) const;

	/**
	 * Tries to obtain field data as a Boolean.
	 *
	 * @param OutBool Is the returned Boolean true?
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Bool Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Bool Boolean"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetBool(bool& OutBool) const;

	/**
	 * Tries to obtain field data as a real number.
	 *
	 * @param OutNumber Real number to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Number Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Number Float Double Real"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetNumber(double& OutNumber) const;

	/**
	 * Tries to obtain field data as a JSON Object.
	 *
	 * @param OutObject JSON Object to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get Object Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Object"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetObject(UMercuryJsonObject*& OutObject) const;

	/**
	 * Tries to obtain field data as a string.
	 *
	 * @param OutString String to get
	 * @return Was the value successfully claimed?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get String Character"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetString(FString& OutString) const;

	/**
	 * Copies data from one JSON Value to another.
	 *
	 * @param Source JSON Value to copy data from
	 * @return The new JSON Value with the copied data
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Duplicate", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Duplicate Copy Source"
	))
	static UMercuryJsonValue* Duplicate(const UMercuryJsonValue* const& Source);

	/**
	 * Compares two JSON Value instances to check for equality.
	 *
	 * @param Left 1st JSON Value to compare
	 * @param Right 2nd JSON Value to compare
	 * @return Are the JSON Values equal?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Compare Equal", Category = "JSON|Value", meta = (
		CompactNodeTitle = "==",
		Keywords = "JSON Value Compare Not Equal Same Clone Copy Different Left Right"
	))
	static bool CompareEqual(const UMercuryJsonValue* const& Left, const UMercuryJsonValue* const& Right);

protected:
	/**
	 * Obtains data as an array.
	 *
	 * @param Value Array containing resulting data
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Array)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Array"
	))
	virtual void K2_AsArgumentTypeArray(TArray<UMercuryJsonValue*>& Value) const;

	/**
	 * Obtains data as a Boolean.
	 *
	 * @param Value Is the resulting data true?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Bool)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Bool Boolean"
	))
	virtual void K2_AsArgumentTypeBool(bool& Value) const;

	/**
	 * Obtains data as a real number.
	 *
	 * @param Value Real number containing resulting data
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Number)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Number Float Double Real"
	))
	virtual void K2_AsArgumentTypeNumber(double& Value) const;

	/**
	 * Obtains data as a JSON Object.
	 *
	 * @param Value JSON Object containing resulting data
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Object)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Object"
	))
	virtual void K2_AsArgumentTypeObject(UMercuryJsonObject*& Value) const;

	/**
	 * Obtains data as a string.
	 *
	 * @param Value String containing resulting data
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (String)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type String Character"
	))
	virtual void K2_AsArgumentTypeString(FString& Value) const;
};
