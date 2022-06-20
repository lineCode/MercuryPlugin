// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonValueType.h"

#include "MercuryJsonValue.generated.h"

class UMercuryJsonObject;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury JSON Value")
class MERCURYJSON_API UMercuryJsonValue : public UObject
{
	GENERATED_BODY()

protected:
	TSharedPtr<FJsonValue> Reference;

public:
	explicit UMercuryJsonValue(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Type", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Get Type Mercury"
	))
	virtual EMercuryJsonValueType GetType() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "As Array", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Array"
	))
	virtual TArray<UMercuryJsonValue*> AsArray() const;

	UFUNCTION(BlueprintPure, DisplayName = "As Bool", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Bool Boolean"
	))
	virtual bool AsBool() const;

	UFUNCTION(BlueprintPure, DisplayName = "As Number", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Number Float Double Real"
	))
	virtual double AsNumber() const;

	UFUNCTION(BlueprintPure, DisplayName = "As Object", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Object"
	))
	virtual UMercuryJsonObject* AsObject() const;

	UFUNCTION(BlueprintPure, DisplayName = "As String", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As String Character"
	))
	virtual FString AsString() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Null", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Is Null"
	))
	virtual bool IsNull() const;

	virtual void AsArgumentType(TArray<UMercuryJsonValue*>& Value) const;
	virtual void AsArgumentType(bool& Value) const;
	virtual void AsArgumentType(double& Value) const;
	virtual void AsArgumentType(UMercuryJsonObject*& Value) const;
	virtual void AsArgumentType(FString& Value) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Array Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Array"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetArray(TArray<UMercuryJsonValue*>& OutArray) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Bool Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Bool Boolean"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetBool(bool& OutBool) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Number Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Number Float Double Real"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetNumber(double& OutNumber) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Object Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get Object"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetObject(UMercuryJsonObject*& OutObject) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Field", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Try Attempt Get String Character"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetString(FString& OutString) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Duplicate", Category = "JSON|Value", meta = (
		Keywords = "JSON Value Duplicate Copy Source"
	))
	virtual UMercuryJsonValue* Duplicate(const UMercuryJsonValue* const& Source);

	UFUNCTION(BlueprintPure, DisplayName = "Compare Equal", Category = "JSON|Value", meta = (
		CompactNodeTitle = "==",
		Keywords = "JSON Value Compare Not Equal Same Clone Copy Different Left Right"
	))
	virtual bool CompareEqual(const UMercuryJsonValue* const& Left, const UMercuryJsonValue* const& Right) const;

protected:
	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Array)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Array"
	))
	virtual void K2_AsArgumentTypeArray(TArray<UMercuryJsonValue*>& Value) const;

	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Bool)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Bool Boolean"
	))
	virtual void K2_AsArgumentTypeBool(bool& Value) const;

	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Number)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Number Float Double Real"
	))
	virtual void K2_AsArgumentTypeNumber(double& Value) const;

	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (Object)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type Object"
	))
	virtual void K2_AsArgumentTypeObject(UMercuryJsonObject*& Value) const;

	UFUNCTION(BlueprintPure, DisplayName = "As Argument Type (String)", Category = "JSON|Value", meta = (
		Keywords = "JSON Value As Argument Type String Character"
	))
	virtual void K2_AsArgumentTypeString(FString& Value) const;

public:
	FORCEINLINE const TSharedPtr<FJsonValue>& GetReference() const { return Reference; }
	FORCEINLINE TSharedPtr<FJsonValue>& GetReference() { return Reference; }
};
