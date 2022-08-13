// Copyright (c) 2022 Kaya Adrian

#include "MercuryUtilitiesLibrary.h"


FString UMercuryUtilitiesLibrary::ByteArrayToString(const TArray<uint8>& In, const int32 Count)
{
	const FString&& BrokenString = BytesToString(In.GetData(), Count);
	FString&& FixedString = TEXT("");

	for (int32&& Index = 0; Index < BrokenString.Len(); ++Index)
	{
		FixedString.AppendChar(BrokenString[Index] - 1);
	}
	return std::move(FixedString);
}

int32 UMercuryUtilitiesLibrary::StringToByteArray(
	const FString& String,
	TArray<uint8>& OutBytes,
	const int32 MaxBufferSize
)
{
	uint8*&& BrokenBytes = new uint8[MaxBufferSize];
	OutBytes.SetNumUninitialized(MaxBufferSize);
	
	const int32&& BytesCopied = StringToBytes(String, BrokenBytes, MaxBufferSize);
	for (int32&& Index = 0; Index < BytesCopied; ++Index)
	{
		OutBytes[Index] = BrokenBytes[Index] + 1;
	}
	OutBytes.Shrink();

	delete[] BrokenBytes;
	return BytesCopied;
}
