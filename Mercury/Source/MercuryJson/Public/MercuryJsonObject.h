// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonClassBase.h"

#include "MercuryJsonObject.generated.h"

class UMercuryJsonValue;
enum class EMercuryJsonValueType : uint8;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury JSON Object")
class MERCURYJSON_API UMercuryJsonObject : public UMercuryJsonClassBase
{
	GENERATED_BODY()

protected:
	TSharedPtr<FJsonObject> Reference;

public:
	explicit UMercuryJsonObject(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, DisplayName = "Duplicate", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Duplicate Copy Source Destination"
	))
	virtual void Duplicate(const UMercuryJsonObject* const& Source, UMercuryJsonObject* const& Destination);

	UFUNCTION(BlueprintPure, DisplayName = "Get Values", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Values Map Name Value"
	))
	virtual TMap<FString, UMercuryJsonValue*> GetValues() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Field Name Value Type"
	))
	virtual UMercuryJsonValue* GetField(const FString& FieldName, EMercuryJsonValueType ValueType) const;

	UFUNCTION(BlueprintPure, DisplayName = "Has Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Has Field Name Value"
	))
	virtual bool HasField(const FString& FieldName) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Remove Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Remove Field Name Value"
	))
	virtual void RemoveField(const FString& FieldName);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Field Name Value"
	))
	virtual void SetField(const FString& FieldName, const UMercuryJsonValue* const& Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Array Field Name Value"
	))
	virtual TArray<UMercuryJsonValue*> GetArrayField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Bool Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Bool Boolean Field Name Value"
	))
	virtual bool GetBoolField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Integer Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Integer Natural Field Name Value"
	))
	virtual int32 GetIntegerField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Number Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Number Float Double Real Field Name Value"
	))
	virtual double GetNumberField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Object Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get Object Field Name Value"
	))
	virtual UMercuryJsonObject* GetObjectField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get String Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Get String Character Field Name Value"
	))
	virtual FString GetStringField(const FString& FieldName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Has Typed Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Has Typed Field Name Value Type"
	))
	virtual bool HasTypedField(const FString& FieldName, EMercuryJsonValueType ValueType) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Array Field Name Value"
	))
	virtual void SetArrayField(const FString& FieldName, const TArray<UMercuryJsonValue*>& Array);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Bool Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Bool Boolean Field Name Value"
	))
	virtual void SetBoolField(const FString& FieldName, bool bInValue);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Number Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Number Float Double Real Field Name Value"
	))
	virtual void SetNumberField(const FString& FieldName, double Number);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Object Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set Object Field Name Value"
	))
	virtual void SetObjectField(const FString& FieldName, const UMercuryJsonObject* const& JsonObject);

	UFUNCTION(BlueprintCallable, DisplayName = "Set String Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Set String Character Field Name Value"
	))
	virtual void SetStringField(const FString& FieldName, const FString& StringValue);

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetArrayField(const FString& FieldName, TArray<UMercuryJsonValue*>& OutArray) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Bool Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Bool Boolean Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetBoolField(const FString& FieldName, bool& OutBool) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Number Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Number Float Double Real Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetNumberField(const FString& FieldName, double& OutNumber) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Object Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Object Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetObjectField(const FString& FieldName, UMercuryJsonObject*& OutObject) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get String Character Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetStringField(const FString& FieldName, FString& OutString) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get Enum Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get Enum Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetEnumArrayField(const FString& FieldName, TArray<int32>& OutArray) const;

	UFUNCTION(BlueprintPure, DisplayName = "Try Get String Array Field", Category = "JSON|Object", meta = (
		Keywords = "JSON Object Try Attempt Get String Character Array Field Name Value"
	))
	virtual UPARAM(DisplayName = "Success") bool
	TryGetStringArrayField(const FString& FieldName, TArray<FString>& OutArray) const;

	FORCEINLINE const TSharedPtr<FJsonObject>& GetReference() const { return Reference; }
	FORCEINLINE TSharedPtr<FJsonObject>& GetReference() { return Reference; }
};
