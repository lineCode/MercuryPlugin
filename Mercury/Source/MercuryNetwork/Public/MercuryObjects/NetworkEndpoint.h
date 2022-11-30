// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "MercuryResourceOwner.h"

#include "NetworkEndpoint.generated.h"

class UMercuryInternetAddr;
class UMercuryNetworkAddress;


/** Structure representing an IPv4 endpoint */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Endpoint")
class MERCURYNETWORK_API UMercuryNetworkEndpoint : public UObject, public TResourceOwner<FIPv4Endpoint>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default IPv4 endpoint resource.
	 *
	 * @return The FIPv4Endpoint object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateNetworkEndpoint
	 */
	virtual TSharedPtr<FIPv4Endpoint> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the endpoint's IP address by creating a new UMercuryNetworkAddress object. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Network IPv4Endpoint Get Address"
	))
	virtual UMercuryNetworkAddress* GetAddress() const;

	/**
	 * Sets the endpoint's IP address.
	 *
	 * @param Value UMercuryNetworkAddress object containing the new IP
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Address", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Set Address"
	))
	virtual UMercuryNetworkEndpoint* SetAddress(const UMercuryNetworkAddress* const& Value);

	/** Gets the wild card address [0.0.0.0]. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Network IPv4Endpoint Get Any"
	))
	static const UMercuryNetworkEndpoint* const& GetAny();

	/** Starts the IP endpoint functionality. */
	UFUNCTION(BlueprintCallable, DisplayName = "Initialize", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint Initialize"
	))
	static void Initialize();

	/**
	 * Converts a string containing an endpoint address to this structure.
	 *
	 * @param EndpointString Given endpoint as a string
	 * @param OutEndpoint Resulting object with the endpoint set
	 * @return Was the conversion successful?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Parse Endpoint", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Endpoint Parse Endpoint String"
	))
	static UPARAM(DisplayName = "Success") bool
	Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint);

	/** Obtains the endpoint's port number. */
	virtual uint16 GetPort() const;

	/**
	 * Sets the endpoint's port number.
	 *
	 * @param Value New port number
	 * @return The same object for method chaining
	 */
	virtual UMercuryNetworkEndpoint* SetPort(const uint16& Value);

	/** Obtains the string representation of the network endpoint. */
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To String"
	))
	virtual FString ToString() const;

	/** Obtains the text representation of the network endpoint. */
	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To Text"
	))
	virtual FText ToText() const;

	/**
	 * Converts this endpoint to a brand new internet address object.
	 *
	 * @warning This method will be removed after the socket subsystem is refactored.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "To Internet Addr", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To Internet Addr Address"
	))
	virtual UMercuryInternetAddr* ToInternetAddr() const;

	/**
	 * Resolves a string containing a hostname and port to this structure.
	 *
	 * @param HostAndPortString Given hostname and port as a string
	 * @param OutEndpoint Resulting object with the IP set
	 * @return Were the host and port successfully parsed and resolved?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "From Host And Port", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint From Host And Port String Endpoint"
	))
	static UPARAM(DisplayName = "Success") bool
	FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint);

	/**
	 * Converts this endpoint to a brand new internet address object.
	 *
	 * @warning This method will be removed after the socket subsystem is refactored.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "To Internet Addr IPv4", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Cast To Internet Addr Address IPv4"
	))
	virtual UMercuryInternetAddr* ToInternetAddrIPv4() const;

protected:
	/**
	 * Obtains the endpoint's port number.
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Network IPv4Endpoint Get Port"
	))
	virtual int32 K2_GetPort() const;

	/**
	 * Sets the endpoint's port number.
	 *
	 * @param Value New port number
	 * @return The same object for method chaining
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Port", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Set Port"
	))
	virtual UMercuryNetworkEndpoint* K2_SetPort(int32 Value);
};
