﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Subnet.h"
#include "ResourceOwner.h"

#include "MercuryNetworkSubnet.generated.h"

class UMercuryNetworkAddress;
class UMercuryNetworkMask;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Subnet")
class MERCURYNETWORK_API UMercuryNetworkSubnet : public UObject, public TResourceOwner<FIPv4Subnet>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FIPv4Subnet> CreateResource() override;

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Network IPv4Subnet Get Address"
	))
	virtual UMercuryNetworkAddress* GetAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Mask", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Mask",
		Keywords = "Network IPv4Subnet Get Mask"
	))
	virtual UMercuryNetworkMask* GetMask() const;

	UFUNCTION(BlueprintPure, DisplayName = "Broadcast Address", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Broadcast Address"
	))
	virtual UMercuryNetworkAddress* BroadcastAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Contains Address", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Contains Address TestAddress"
	))
	virtual bool ContainsAddress(const UMercuryNetworkAddress* const& TestAddress) const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Subnet Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Subnet Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Parse Subnet", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Subnet Parse Subnet String"
	))
	static void Parse(const FString& SubnetString, UMercuryNetworkSubnet*& OutSubnet);
};
