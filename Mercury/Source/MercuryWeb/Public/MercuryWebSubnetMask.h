// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryCommon/Public/ResourceOwner.h"

#include "MercuryWebSubnetMask.generated.h"

struct FIPv4SubnetMask;


UENUM(BlueprintType, meta = (Keywords = "Web Subnet Mask Class Invalid A B C"))
enum class EMercuryWebSubnetMaskClass : uint8
{
	Invalid UMETA(DisplayName = "Invalid"),
	ClassA UMETA(DisplayName = "Class A"),
	ClassB UMETA(DisplayName = "Class B"),
	ClassC UMETA(DisplayName = "Class C")
};


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Web Subnet Mask")
class MERCURYWEB_API UMercuryWebSubnetMask : public UObject, public TResourceOwner<FIPv4SubnetMask>
{
	GENERATED_BODY()

public:
	explicit UMercuryWebSubnetMask(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Get Subnet Class", Category = "Web|IPv4SubnetMask", meta = (
		Keywords = "Web IPv4SubnetMask Get Subnet Class"
	))
	virtual EMercuryWebSubnetMaskClass GetSubnetClass() const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4SubnetMask Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4SubnetMask Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "A",
		Keywords = "Web IPv4SubnetMask Get A"
	))
	virtual uint8 GetA() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "B",
		Keywords = "Web IPv4SubnetMask Get B"
	))
	virtual uint8 GetB() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "C",
		Keywords = "Web IPv4SubnetMask Get C"
	))
	virtual uint8 GetC() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "D",
		Keywords = "Web IPv4SubnetMask Get D"
	))
	virtual uint8 GetD() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Web|IPv4SubnetMask", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Web IPv4SubnetMask Get Value"
	))
	virtual int32 GetValue() const;

	UFUNCTION(BlueprintPure, DisplayName = "Parse", Category = "Web|IPv4SubnetMask", meta = (
		Keywords = "Static Web IPv4SubnetMask Parse Mask String"
	))
	static void Parse(const FString& MaskString, UMercuryWebSubnetMask*& OutMask);
};
