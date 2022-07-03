// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryCommon/Public/ResourceOwner.h"

#include "MercuryWebSubnet.generated.h"

struct FIPv4Subnet;
struct FIPv4SubnetMask;

class UMercuryWebAddress;
//class UMercuryWebSubnetMask;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Web Subnet")
class MERCURYWEB_API UMercuryWebSubnet : public UObject, public TResourceOwner<FIPv4Subnet>
{
	GENERATED_BODY()

public:
	explicit UMercuryWebSubnet(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Web|IPv4Subnet", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Web IPv4Subnet Get Address"
	))
	virtual UMercuryWebAddress* GetAddress() const;
/*
	UFUNCTION(BlueprintPure, DisplayName = "Get Mask", Category = "Web|IPv4Subnet", meta = (
		CompactNodeTitle = "Mask",
		Keywords = "Web IPv4Subnet Get Mask"
	))
	virtual UMercuryWebSubnetMask* GetMask() const;*/

	UFUNCTION(BlueprintPure, DisplayName = "Broadcast Address", Category = "Web|IPv4Subnet", meta = (
		Keywords = "Web IPv4Subnet Broadcast Address"
	))
	virtual UMercuryWebAddress* BroadcastAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Contains Address", Category = "Web|IPv4Subnet", meta = (
		Keywords = "Web IPv4Subnet Contains Address TestAddress"
	))
	virtual bool ContainsAddress(const UMercuryWebAddress* const& TestAddress) const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Web|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Subnet Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Web|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Subnet Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Parse", Category = "Web|IPv4Subnet", meta = (
		Keywords = "Static Web IPv4Subnet Parse Subnet String"
	))
	static void Parse(const FString& SubnetString, UMercuryWebSubnet*& OutSubnet);
};
