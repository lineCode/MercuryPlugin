﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryNetworkSubnetClass.h"
#include "ResourceOwner.h"

#include "MercuryNetworkMask.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Mask")
class MERCURYNETWORK_API UMercuryNetworkMask : public UObject, public TResourceOwner<FIPv4SubnetMask>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FIPv4SubnetMask> CreateResource() override;

	UFUNCTION(BlueprintPure, DisplayName = "Get Subnet Class", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Subnet Class",
		Keywords = "Network IPv4SubnetMask Get Subnet Class"
	))
	virtual EMercuryNetworkSubnetClass GetSubnetClass() const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "A",
		Keywords = "Network IPv4SubnetMask Get A"
	))
	virtual uint8 GetA() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "B",
		Keywords = "Network IPv4SubnetMask Get B"
	))
	virtual uint8 GetB() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "C",
		Keywords = "Network IPv4SubnetMask Get C"
	))
	virtual uint8 GetC() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "D",
		Keywords = "Network IPv4SubnetMask Get D"
	))
	virtual uint8 GetD() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Network IPv4SubnetMask Get Value"
	))
	virtual int32 GetValue() const;

	UFUNCTION(BlueprintPure, DisplayName = "Parse Mask", Category = "Network|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4SubnetMask Parse Mask String"
	))
	static void Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask);
};
