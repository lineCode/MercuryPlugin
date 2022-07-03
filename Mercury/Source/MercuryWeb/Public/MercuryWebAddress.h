// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryWebAddress.generated.h"

struct FIPv4Address;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Web Address")
class MERCURYWEB_API UMercuryWebAddress : public UObject
{
	GENERATED_BODY()
	
	TSharedPtr<FIPv4Address> Resource;

public:
	explicit UMercuryWebAddress(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "A",
		Keywords = "Web IPv4Address Get A"
	))
	virtual uint8 GetA() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "B",
		Keywords = "Web IPv4Address Get B"
	))
	virtual uint8 GetB() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "C",
		Keywords = "Web IPv4Address Get C"
	))
	virtual uint8 GetC() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "D",
		Keywords = "Web IPv4Address Get D"
	))
	virtual uint8 GetD() const;
	
	virtual uint32 GetValue() const;

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Address To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Address To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Global Multicast", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Global Multicast"
	))
	virtual bool IsGlobalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Link Local"
	))
	virtual bool IsLinkLocal() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Loopback Address", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Loopback Address"
	))
	virtual bool IsLoopbackAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Multicast Address", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Multicast Address"
	))
	virtual bool IsMulticastAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local Multicast", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Link Local Multicast"
	))
	virtual bool IsLinkLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Organization Local Multicast", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Organization Local Multicast"
	))
	virtual bool IsOrganizationLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Session Frontend Multicast", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Session Frontend Multicast"
	))
	virtual bool IsSessionFrontendMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Address", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Site Local Address"
	))
	virtual bool IsSiteLocalAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Multicast", Category = "Web|IPv4Address", meta = (
		Keywords = "Web IPv4Address Is Site Local Multicast"
	))
	virtual bool IsSiteLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Web IPv4Address Get Any"
	))
	static const UMercuryWebAddress* const& GetAny();

	UFUNCTION(BlueprintPure, DisplayName = "Parse", Category = "Web|IPv4Address", meta = (
		Keywords = "Static Web IPv4Address Parse Address String"
	))
	static void Parse(const FString& AddressString, UMercuryWebAddress*& OutAddress);

	UFUNCTION(BlueprintPure, DisplayName = "Get Internal Loopback", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "Internal Loopback",
		Keywords = "Static Web IPv4Address Get Internal Loopback"
	))
	static const UMercuryWebAddress* const& GetInternalLoopback();

	UFUNCTION(BlueprintPure, DisplayName = "Get LAN Broadcast", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "LAN Broadcast",
		Keywords = "Static Web IPv4Address Get Lan Broadcast"
	))
	static const UMercuryWebAddress* const& GetLanBroadcast();

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Web|IPv4Address", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Web IPv4Address Get Value"
	))
	virtual int32 K2_GetValue() const;

public:
	FORCEINLINE const TSharedPtr<FIPv4Address>& GetResource() const { return Resource; }
	FORCEINLINE TSharedPtr<FIPv4Address>& GetResource() { return Resource; }
};
