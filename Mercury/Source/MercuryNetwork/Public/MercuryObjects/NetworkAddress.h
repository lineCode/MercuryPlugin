// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Address.h"
#include "MercuryResourceOwner.h"

#include "NetworkAddress.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Address")
class MERCURYNETWORK_API UMercuryNetworkAddress : public UObject, public TResourceOwner<FIPv4Address>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FIPv4Address> CreateResource() override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Address", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "A",
		Keywords = "Network IPv4Address Get A"
	))
	virtual uint8 GetA() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set A", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set A"
	))
	virtual UMercuryNetworkAddress* SetA(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "B",
		Keywords = "Network IPv4Address Get B"
	))
	virtual uint8 GetB() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set B", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set B"
	))
	virtual UMercuryNetworkAddress* SetB(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "C",
		Keywords = "Network IPv4Address Get C"
	))
	virtual uint8 GetC() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set C", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set C"
	))
	virtual UMercuryNetworkAddress* SetC(uint8 Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "D",
		Keywords = "Network IPv4Address Get D"
	))
	virtual uint8 GetD() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set D", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set D"
	))
	virtual UMercuryNetworkAddress* SetD(uint8 Value);
	
	virtual uint32 GetValue() const;
	virtual UMercuryNetworkAddress* SetValue(const uint32& Value);

	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Address Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Address Cast To Text"
	))
	virtual FText ToText() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Global Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Global Multicast"
	))
	virtual bool IsGlobalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Link Local"
	))
	virtual bool IsLinkLocal() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Loopback Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Loopback Address"
	))
	virtual bool IsLoopbackAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Multicast Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Multicast Address"
	))
	virtual bool IsMulticastAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Link Local Multicast"
	))
	virtual bool IsLinkLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Organization Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Organization Local Multicast"
	))
	virtual bool IsOrganizationLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Session Frontend Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Session Frontend Multicast"
	))
	virtual bool IsSessionFrontendMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Site Local Address"
	))
	virtual bool IsSiteLocalAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Site Local Multicast"
	))
	virtual bool IsSiteLocalMulticast() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Network IPv4Address Get Any"
	))
	static const UMercuryNetworkAddress* const& GetAny();

	UFUNCTION(BlueprintPure, DisplayName = "Parse Address", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Address Parse Address String"
	))
	static void Parse(const FString& AddressString, UMercuryNetworkAddress*& OutAddress);

	UFUNCTION(BlueprintPure, DisplayName = "Get Internal Loopback", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Internal Loopback",
		Keywords = "Static Network IPv4Address Get Internal Loopback"
	))
	static const UMercuryNetworkAddress* const& GetInternalLoopback();

	UFUNCTION(BlueprintPure, DisplayName = "Get LAN Broadcast", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "LAN Broadcast",
		Keywords = "Static Network IPv4Address Get LAN Broadcast"
	))
	static const UMercuryNetworkAddress* const& GetLanBroadcast();

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Network IPv4Address Get Value"
	))
	virtual int32 K2_GetValue() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set Value", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set Value"
	))
	virtual UMercuryNetworkAddress* K2_SetValue(int32 Value);
};
