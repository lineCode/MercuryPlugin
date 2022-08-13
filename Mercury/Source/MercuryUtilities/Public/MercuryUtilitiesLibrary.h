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
		CompactNodeTitle = "Cast",
		Keywords = "In Byte Bytes Array Count Cast To String"
	))
	static FString ByteArrayToString(const TArray<uint8>& In, int32 Count);

	UFUNCTION(BlueprintPure, DisplayName = "String To Bytes", Category = "Mercury|Utilities", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "String Cast To Out Byte Bytes Array Max Buffer Size"
	))
	static UPARAM(DisplayName = "Bytes Copied") int32
	StringToByteArray(const FString& String, TArray<uint8>& OutBytes, int32 MaxBufferSize);
};
