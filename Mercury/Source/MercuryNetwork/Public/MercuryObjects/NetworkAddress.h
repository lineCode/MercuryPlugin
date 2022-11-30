// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Address.h"
#include "MercuryResourceOwner.h"

#include "NetworkAddress.generated.h"


/** Structure representing an IPv4 address */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Address")
class MERCURYNETWORK_API UMercuryNetworkAddress : public UObject, public TResourceOwner<FIPv4Address>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default IPv4 address resource.
	 *
	 * @return The FIPv4Address object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateNetworkAddress
	 */
	virtual TSharedPtr<FIPv4Address> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Address", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the 1st byte of the network IP address. */
	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "A",
		Keywords = "Network IPv4Address Get A"
	))
	virtual uint8 GetA() const;

	/**
	 * Sets the 1st byte of the network IP address.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set A", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set A"
	))
	virtual UMercuryNetworkAddress* SetA(uint8 Value);

	/** Obtains the 2nd byte of the network IP address. */
	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "B",
		Keywords = "Network IPv4Address Get B"
	))
	virtual uint8 GetB() const;

	/**
	 * Sets the 2nd byte of the network IP address.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set B", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set B"
	))
	virtual UMercuryNetworkAddress* SetB(uint8 Value);

	/** Obtains the 3rd byte of the network IP address. */
	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "C",
		Keywords = "Network IPv4Address Get C"
	))
	virtual uint8 GetC() const;

	/**
	 * Sets the 3rd byte of the network IP address.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set C", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set C"
	))
	virtual UMercuryNetworkAddress* SetC(uint8 Value);

	/** Obtains the 4th byte of the network IP address. */
	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "D",
		Keywords = "Network IPv4Address Get D"
	))
	virtual uint8 GetD() const;

	/**
	 * Sets the 4th byte of the network IP address.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set D", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set D"
	))
	virtual UMercuryNetworkAddress* SetD(uint8 Value);

	/** Obtains the network IP address as an integer. */
	virtual uint32 GetValue() const;

	/**
	 * Sets the network IP address from an integer.
	 *
	 * @param Value New IP address
	 * @return The same object for method chaining
	 */
	virtual UMercuryNetworkAddress* SetValue(const uint32& Value);

	/** Obtains the string representation of the network address. */
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Address Cast To String"
	))
	virtual FString ToString() const;

	/** Obtains the text representation of the network address. */
	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Address Cast To Text"
	))
	virtual FText ToText() const;

	/**
	 * Checks if the IP is a global multicast address.
	 *
	 * @note Global multicast addresses are in the range (224.0.1.0 - 238.255.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Global Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Global Multicast"
	))
	virtual bool IsGlobalMulticast() const;

	/**
	 * Checks if the IP is a link local address.
	 *
	 * @note Link local addresses are in the range (169.254.0.0 - 169.254.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Link Local"
	))
	virtual bool IsLinkLocal() const;

	/**
	 * Checks if the IP is a loopback address.
	 *
	 * @note Loopback addresses are in the range (127.0.0.0 - 127.255.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Loopback Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Loopback Address"
	))
	virtual bool IsLoopbackAddress() const;

	/**
	 * Checks if the IP is a multicast address.
	 *
	 * @note Multicast addresses are in the range (224.0.0.0 - 239.255.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Multicast Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Multicast Address"
	))
	virtual bool IsMulticastAddress() const;

	/**
	 * Checks if the IP is a link local multicast address.
	 *
	 * @note Multicast addresses are in the range (224.0.0.0 - 224.255.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Link Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Link Local Multicast"
	))
	virtual bool IsLinkLocalMulticast() const;

	/**
	 * Checks if the IP is an organization local multicast address.
	 *
	 * @note Organization local multicast addresses are in the range (239.192.0.0 - 239.195.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Organization Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Organization Local Multicast"
	))
	virtual bool IsOrganizationLocalMulticast() const;

	/**
	 * Checks if the IP is the multicast address used for Session Frontend.
	 *
	 * @note The Session Frontend multicast address is [230.0.0.1].
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Session Frontend Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Session Frontend Multicast"
	))
	virtual bool IsSessionFrontendMulticast() const;

	/**
	 * Checks if the IP is a site local address.
	 *
	 * @note Site local addresses are in the ranges:\n
	 * (10.0.0.0 - 10.255.255.255),\n
	 * (172.16.0.0 - 172.31.255.255),\n
	 * (192.168.0.0 - 192.168.255.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Address", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Site Local Address"
	))
	virtual bool IsSiteLocalAddress() const;

	/**
	 * Checks if the IP is a site local multicast address.
	 *
	 * @note Site local multicast addresses are in the range (239.255.0.0 - 239.255.0.255).
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Site Local Multicast", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Is Site Local Multicast"
	))
	virtual bool IsSiteLocalMulticast() const;

	/** Gets the wild card address [0.0.0.0]. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Network IPv4Address Get Any"
	))
	static const UMercuryNetworkAddress* const& GetAny();

	/**
	 * Converts a string containing an IP address to this structure.
	 *
	 * @param AddressString Given IP as a string
	 * @param OutAddress Resulting object with the IP set
	 * @return Was the conversion successful?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Parse Address", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Address Parse Address String"
	))
	static UPARAM(DisplayName = "Success") bool
	Parse(const FString& AddressString, UMercuryNetworkAddress*& OutAddress);

	/** Gets the internal loopback address [127.0.0.1]. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Internal Loopback", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Internal Loopback",
		Keywords = "Static Network IPv4Address Get Internal Loopback"
	))
	static const UMercuryNetworkAddress* const& GetInternalLoopback();

	/** Gets the LAN broadcast address [255.255.255.255]. */
	UFUNCTION(BlueprintPure, DisplayName = "Get LAN Broadcast", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "LAN Broadcast",
		Keywords = "Static Network IPv4Address Get LAN Broadcast"
	))
	static const UMercuryNetworkAddress* const& GetLanBroadcast();

protected:
	/**
	 * Obtains the network IP address as an integer.
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Network|IPv4Address", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Network IPv4Address Get Value"
	))
	virtual int32 K2_GetValue() const;

	/**
	 * Sets the network IP address from an integer.
	 *
	 * @param Value New IP address
	 * @return The same object for method chaining
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Value", Category = "Network|IPv4Address", meta = (
		Keywords = "Network IPv4Address Set Value"
	))
	virtual UMercuryNetworkAddress* K2_SetValue(int32 Value);
};
