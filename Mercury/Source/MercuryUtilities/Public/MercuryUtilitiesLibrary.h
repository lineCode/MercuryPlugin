// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "MercuryUtilitiesLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Utilities Blueprint Function Library")
class MERCURYUTILITIES_API UMercuryUtilitiesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Bytes To String", Category = "Mercury|Utilities", meta = (
		Keywords = "In Byte Bytes Array Count Cast To Out String"
	))
	static UPARAM(DisplayName = "Out") FString
	ByteArrayToString(const TArray<uint8>& In, int32 Count);

	UFUNCTION(BlueprintPure, DisplayName = "String To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "In String Cast To Out Byte Bytes Array Max Buffer Size"
	))
	static UPARAM(DisplayName = "Bytes Copied") int32
	StringToByteArray(const FString& In, TArray<uint8>& Out, int32 MaxBufferSize);

	UFUNCTION(BlueprintPure, DisplayName = "Bytes To Colours", Category = "Mercury|Utilities", meta = (
		Keywords = "In Byte Bytes Array Cast To Out Colors Colours Monochrome"
	))
	static void ByteArrayToColours(const TArray<uint8>& In, TArray<FColor>& Out, bool bMonochrome = false);

	UFUNCTION(BlueprintPure, DisplayName = "Colours To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "In Colors Colours Cast To Out Byte Bytes Array Monochrome"
	))
	static void ColoursToByteArray(const TArray<FColor>& In, TArray<uint8>& Out, bool bMonochrome = false);

	UFUNCTION(BlueprintCallable, DisplayName = "Encode String To Base64", Category = "Mercury|Utilities", meta = (
		Keywords = "Encode String Source To Base64"
	))
	static UPARAM(DisplayName = "Base64") FString
	EncodeStringToBase64(const FString& Source);

	UFUNCTION(BlueprintCallable, DisplayName = "Encode Bytes To Base64", Category = "Mercury|Utilities", meta = (
		Keywords = "Encode Byte Bytes Source To Base64"
	))
	static UPARAM(DisplayName = "Base64") FString
	EncodeBytesToBase64(const TArray<uint8>& Source);

	UFUNCTION(BlueprintCallable, DisplayName = "Decode Base64 To String", Category = "Mercury|Utilities", meta = (
		Keywords = "Decode Base64 Source To String Out Destination"
	))
	static UPARAM(DisplayName = "Success") bool
	DecodeBase64ToString(const FString& Source, FString& OutDestination);

	UFUNCTION(BlueprintCallable, DisplayName = "Decode Base64 To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "Decode Base64 Source To Byte Bytes Destination"
	))
	static UPARAM(DisplayName = "Success") bool
	DecodeBase64ToBytes(const FString& Source, TArray<uint8>& Destination);
};
