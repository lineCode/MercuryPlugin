// Copyright (c) 2022 Kaya Adrian

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

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Mask", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintPure, DisplayName = "Get Subnet Class", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Subnet Class",
		Keywords = "Network IPv4SubnetMask Get Subnet Class"
	))
	virtual EMercuryNetworkSubnetClass GetSubnetClass() const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "A",
		Keywords = "Network IPv4SubnetMask Get A"
	))
	virtual uint8 GetA() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set A", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set A"
	))
	virtual UMercuryNetworkMask* SetA(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "B",
		Keywords = "Network IPv4SubnetMask Get B"
	))
	virtual uint8 GetB() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set B", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set B"
	))
	virtual UMercuryNetworkMask* SetB(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "C",
		Keywords = "Network IPv4SubnetMask Get C"
	))
	virtual uint8 GetC() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set C", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set C"
	))
	virtual UMercuryNetworkMask* SetC(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "D",
		Keywords = "Network IPv4SubnetMask Get D"
	))
	virtual uint8 GetD() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set D", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set D"
	))
	virtual UMercuryNetworkMask* SetD(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Network IPv4SubnetMask Get Value"
	))
	virtual int32 GetValue() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set Value", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set Value"
	))
	virtual UMercuryNetworkMask* SetValue(int32 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Parse Mask", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4SubnetMask Parse Mask String"
	))
	static void Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask);
};
