// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonTypes.h"

#include "MercuryJsonLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury JSON Blueprint Function Library")
class MERCURYJSON_API UMercuryJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Make Mercury JSON", Category = "JSON", meta = (
		Keywords = "JSON Make Create New Object",
		NativeMakeFunc
	))
	static FMercuryJsonObject MakeJson();

	UFUNCTION(BlueprintPure, DisplayName = "Mercury JSON Object To String", Category = "JSON", meta = (
		BlueprintAutocast,
		CompactNodeTitle = "To String",
		Keywords = "JSON Break Cast From Object To String Condensed",
		NativeBreakFunc
	))
	static FString JsonObjectToCondensedString(const FMercuryJsonObject& JsonObject);

	UFUNCTION(BlueprintPure, DisplayName = "Mercury JSON Object To Pretty String", Category = "JSON", meta = (
		BlueprintAutocast,
		CompactNodeTitle = "To Pretty String",
		Keywords = "JSON Break Cast From Object To String Pretty",
		NativeBreakFunc
	))
	static FString JsonObjectToPrettyString(const FMercuryJsonObject& JsonObject);
};


template<class CharType, template<typename> class PrintPolicy>
FString JsonObjectToString(const TSharedPtr<FJsonObject>& JsonObject)
{
	FString Stream;
	if (JsonObject.IsValid())
	{
		const TSharedRef<TJsonWriter<CharType, PrintPolicy<CharType>>>& JsonWriter =
			TJsonWriterFactory<CharType, PrintPolicy<CharType>>::Create(&Stream);
		
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
	}
	return Stream;
}
