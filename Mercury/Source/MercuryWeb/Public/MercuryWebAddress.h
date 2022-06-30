// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryWebClassBase.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"

#include "MercuryWebAddress.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Web Address")
class MERCURYWEB_API UMercuryWebAddress : public UMercuryWebClassBase
{
	GENERATED_BODY()
	
	TSharedPtr<FIPv4Address> Resource;

public:
	explicit UMercuryWebAddress(const FObjectInitializer& ObjectInitializer);
	
	FORCEINLINE const TSharedPtr<FIPv4Address>& GetResource() const { return Resource; }
	FORCEINLINE TSharedPtr<FIPv4Address>& GetResource() { return Resource; }
};
