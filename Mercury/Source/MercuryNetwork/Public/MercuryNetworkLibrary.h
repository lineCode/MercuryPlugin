// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MercuryObjects/InternetAddr.h"
#include "MercuryObjects/NetworkAddress.h"
#include "MercuryObjects/NetworkEndpoint.h"
#include "MercuryObjects/NetworkMask.h"
#include "MercuryObjects/NetworkSubnet.h"

#include "MercuryNetworkLibrary.generated.h"


/** Library for creating Mercury Internet Addresses and Network objects */
UCLASS(Abstract, DisplayName = "Mercury Network Blueprint Function Library")
class MERCURYNETWORK_API UMercuryNetworkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Creates an internet address with a default resource.
	 *
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr (Default)", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Default Empty"
	))
	static UMercuryInternetAddr* CreateInternetAddr();

	/**
	 * Creates an internet address using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 */
	static UMercuryInternetAddr* CreateInternetAddr(FInternetAddr* const& Resource);

	/**
	 * Creates an internet address using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 */
	static UMercuryInternetAddr* CreateInternetAddr(const TSharedPtr<FInternetAddr>& Resource);

	/**
	 * Creates an internet address with a default resource.
	 *
	 * @param Address Local IP address
	 * @param Port Local port number
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 */
	static UMercuryInternetAddr* CreateInternetAddr(const uint32& Address, const uint32& Port = 0u);

	/**
	 * Creates an internet address with a default resource.
	 *
	 * @param ProtocolType Desired protocol
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 */
	static UMercuryInternetAddr* CreateInternetAddr(const FName& ProtocolType);

	/**
	 * Creates a network address with a default resource.
	 *
	 * @return The resulting UMercuryNetworkAddress object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Network Address", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Address"
	))
	static UMercuryNetworkAddress* CreateNetworkAddress();

	/**
	 * Creates a network address using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkAddress object or NULL if failed
	 */
	static UMercuryNetworkAddress* CreateNetworkAddress(FIPv4Address* const& Resource);

	/**
	 * Creates a network address using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkAddress object or NULL if failed
	 */
	static UMercuryNetworkAddress* CreateNetworkAddress(const TSharedPtr<FIPv4Address>& Resource);

	/**
	 * Creates a network endpoint with a default resource.
	 *
	 * @return The resulting UMercuryNetworkEndpoint object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Network Endpoint", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Endpoint"
	))
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint();

	/**
	 * Creates a network endpoint using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkEndpoint object or NULL if failed
	 */
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(FIPv4Endpoint* const& Resource);

	/**
	 * Creates a network endpoint using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkEndpoint object or NULL if failed
	 */
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(const TSharedPtr<FIPv4Endpoint>& Resource);

	/**
	 * Creates a network mask with a default resource.
	 *
	 * @return The resulting UMercuryNetworkMask object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Network Mask", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet Mask"
	))
	static UMercuryNetworkMask* CreateNetworkMask();

	/**
	 * Creates a network mask using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkMask object or NULL if failed
	 */
	static UMercuryNetworkMask* CreateNetworkMask(FIPv4SubnetMask* const& Resource);

	/**
	 * Creates a network mask using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkMask object or NULL if failed
	 */
	static UMercuryNetworkMask* CreateNetworkMask(const TSharedPtr<FIPv4SubnetMask>& Resource);

	/**
	 * Creates a network subnet mask with a default resource.
	 *
	 * @return The resulting UMercuryNetworkSubnet object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Network Subnet", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet"
	))
	static UMercuryNetworkSubnet* CreateNetworkSubnet();

	/**
	 * Creates a network subnet mask using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkSubnet object or NULL if failed
	 */
	static UMercuryNetworkSubnet* CreateNetworkSubnet(FIPv4Subnet* const& Resource);

	/**
	 * Creates a network subnet mask using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryNetworkSubnet object or NULL if failed
	 */
	static UMercuryNetworkSubnet* CreateNetworkSubnet(const TSharedPtr<FIPv4Subnet>& Resource);

protected:
	/**
	 * Creates an internet address with a default resource while setting a local IP and port.
	 *
	 * @param Address Local IP address to bind to
	 * @param Port Local port number to bind to
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Address Port"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddr(int32 Address, int32 Port = 0);

	/**
	 * Creates an internet address with a default resource.
	 *
	 * @param ProtocolType Desired protocol
	 * @return The resulting UMercuryInternetAddr object or NULL if failed
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr (Protocol)", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Protocol Type"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddrWithProtocol(const FName& ProtocolType);
};
