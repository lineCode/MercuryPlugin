// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryJsonValue.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury JSON Value")
class MERCURYJSON_API UMercuryJsonValue : public UObject
{
	GENERATED_BODY()

protected:
	TSharedPtr<FJsonValue> Reference;

public:
	FORCEINLINE const TSharedPtr<FJsonValue>& GetReference() const { return Reference; }
	FORCEINLINE TSharedPtr<FJsonValue>& GetReference() { return Reference; }
};
