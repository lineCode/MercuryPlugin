// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "MercuryUtilitiesLibrary.generated.h"


/** Mercury utility functions compiled into a library */
UCLASS(Abstract, DisplayName = "Mercury Utilities Blueprint Function Library")
class MERCURYUTILITIES_API UMercuryUtilitiesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Transforms a byte array into the equivalent FString object.
	 * 
	 * @param In Given array filled with bytes
	 * @param Count Number of bytes to transform
	 * @return The resulting FString object
	 * @note Count will usually just be the array's size, but any integer can be used.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bytes To String", Category = "Mercury|Utilities", meta = (
		Keywords = "In Byte Bytes Array Count Cast To Out String"
	))
	static UPARAM(DisplayName = "Out") FString
	ByteArrayToString(const TArray<uint8>& In, int32 Count);

	/**
	 * Transforms FString object into the equivalent byte array.
	 * 
	 * @param In Given FString object
	 * @param Out Resulting byte array
	 * @param MaxBufferSize Number of bytes to copy
	 * @return The number of bytes successfully copied
	 */
	UFUNCTION(BlueprintPure, DisplayName = "String To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "In String Cast To Out Byte Bytes Array Max Buffer Size"
	))
	static UPARAM(DisplayName = "Bytes Copied") int32
	StringToByteArray(const FString& In, TArray<uint8>& Out, int32 MaxBufferSize);

	/**
	 * Transforms a byte array of an image into the equivalent FColor array.
	 * 
	 * @param In Image data
	 * @param Out Image colours
	 * @param bMonochrome Is the image black-and-white?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bytes To Colours", Category = "Mercury|Utilities", meta = (
		Keywords = "In Byte Bytes Array Cast To Out Colors Colours Monochrome"
	))
	static void ByteArrayToColours(const TArray<uint8>& In, TArray<FColor>& Out, bool bMonochrome = false);

	/**
	 * Transforms an FColor array of an image into the equivalent byte array.
	 *
	 * @param In Image colours
	 * @param Out Image data
	 * @param bMonochrome Is the image black-and-white?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Colours To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "In Colors Colours Cast To Out Byte Bytes Array Monochrome"
	))
	static void ColoursToByteArray(const TArray<FColor>& In, TArray<uint8>& Out, bool bMonochrome = false);

	/**
	 * Encodes a plain text string into a Base64 string.
	 *
	 * @param Source Given plain text FString object
	 * @return The Base64 encoded FString object
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Encode String To Base64", Category = "Mercury|Utilities", meta = (
		Keywords = "Encode String Source To Base64"
	))
	static UPARAM(DisplayName = "Base64") FString
	EncodeStringToBase64(const FString& Source);

	/**
	 * Encodes a byte array into a Base64 string.
	 *
	 * @param Source Given byte array
	 * @return The Base64 encoded FString object
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Encode Bytes To Base64", Category = "Mercury|Utilities", meta = (
		Keywords = "Encode Byte Bytes Source To Base64"
	))
	static UPARAM(DisplayName = "Base64") FString
	EncodeBytesToBase64(const TArray<uint8>& Source);

	/**
	 * Decodes a Base64 string to a plain text string.
	 *
	 * @param Source Given Base64 FString object
	 * @param OutDestination Resulting plain text FString object
	 * @return Was the string decoded?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Decode Base64 To String", Category = "Mercury|Utilities", meta = (
		Keywords = "Decode Base64 Source To String Out Destination"
	))
	static UPARAM(DisplayName = "Success") bool
	DecodeBase64ToString(const FString& Source, FString& OutDestination);

	/**
	 * Decodes a Base64 string to a byte array.
	 *
	 * @param Source Given Base64 FString object
	 * @param Destination Resulting byte array
	 * @return Was the string decoded?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Decode Base64 To Bytes", Category = "Mercury|Utilities", meta = (
		Keywords = "Decode Base64 Source To Byte Bytes Destination"
	))
	static UPARAM(DisplayName = "Success") bool
	DecodeBase64ToBytes(const FString& Source, TArray<uint8>& Destination);
};
