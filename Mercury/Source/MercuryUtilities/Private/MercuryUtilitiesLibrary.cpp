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

int32 UMercuryUtilitiesLibrary::StringToByteArray(const FString& In, TArray<uint8>& Out, const int32 MaxBufferSize)
{
	uint8*&& BrokenBytes = new uint8[MaxBufferSize];
	Out.SetNumUninitialized(MaxBufferSize);
	
	const int32&& BytesCopied = StringToBytes(In, BrokenBytes, MaxBufferSize);
	for (int32&& Index = 0; Index < BytesCopied; ++Index)
	{
		Out[Index] = BrokenBytes[Index] + 1;
	}
	Out.Shrink();

	delete[] BrokenBytes;
	return BytesCopied;
}

void UMercuryUtilitiesLibrary::ByteArrayToColours(const TArray<uint8>& In, TArray<FColor>& Out, const bool bMonochrome)
{
	if (bMonochrome)
	{
		const uint64&& ByteCount = In.Num();
		Out.SetNumUninitialized(ByteCount);
		
		for (uint64&& Index = 0u; Index < ByteCount; ++Index)
		{
			Out[Index] = FColor(In[Index]);
		}
	}
	else
	{
		TArray<uint8> ExtendedIn = In;
		while (ExtendedIn.Num() % 4u != 0u)
		{
			ExtendedIn.Add(0u);
		}

		const uint64&& ByteCount = ExtendedIn.Num();
		Out.SetNumUninitialized(0.25f * ByteCount);

		for (uint64&& Index = 0u; Index < ByteCount; Index += 4u)
		{
			Out[Index] = FColor(
				ExtendedIn[Index + 0u],
				ExtendedIn[Index + 1u],
				ExtendedIn[Index + 2u],
				ExtendedIn[Index + 3u]
			);
		}
	}
}

void UMercuryUtilitiesLibrary::ColoursToByteArray(const TArray<FColor>& In, TArray<uint8>& Out, const bool bMonochrome)
{
	if (bMonochrome)
	{
		const uint64&& ColourCount = In.Num();
		Out.SetNumUninitialized(ColourCount);

		for (uint64&& Index = 0u; Index < ColourCount; ++Index)
		{
			Out[Index] = In[Index].R;
		}
	}
	else
	{
		const uint64&& ColourCount = In.Num();
		Out.SetNumUninitialized(4u * ColourCount);

		for (uint64&& Index = 0u; Index < ColourCount; ++Index)
		{
			const FColor& Colour = In[Index];
		
			Out[4u * Index + 0u] = Colour.R;
			Out[4u * Index + 1u] = Colour.G;
			Out[4u * Index + 2u] = Colour.B;
			Out[4u * Index + 3u] = Colour.A;
		}
	}
}

FString UMercuryUtilitiesLibrary::EncodeStringToBase64(const FString& Source)
{
	return FBase64::Encode(Source);
}

FString UMercuryUtilitiesLibrary::EncodeBytesToBase64(const TArray<uint8>& Source)
{
	return FBase64::Encode(Source);
}

bool UMercuryUtilitiesLibrary::DecodeBase64ToString(const FString& Source, FString& OutDestination)
{
	return FBase64::Decode(Source, OutDestination);
}

bool UMercuryUtilitiesLibrary::DecodeBase64ToBytes(const FString& Source, TArray<uint8>& Destination)
{
	return FBase64::Decode(Source, Destination);
}
