// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryObjects/InternetAddr.h"
#include "MercuryObjects/NetworkAddress.h"
#include "MercuryObjects/NetworkEndpoint.h"
#include "MercuryObjects/NetworkMask.h"
#include "MercuryObjects/NetworkSubnet.h"

#include "MercuryNetworkLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Network Blueprint Function Library")
class MERCURYNETWORK_API UMercuryNetworkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr (Default)", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Default Empty"
	))
	static UMercuryInternetAddr* CreateInternetAddr();
	static UMercuryInternetAddr* CreateInternetAddr(FInternetAddr* const& Resource);
	static UMercuryInternetAddr* CreateInternetAddr(const TSharedPtr<FInternetAddr>& Resource);
	static UMercuryInternetAddr* CreateInternetAddr(const uint32& Address, const uint32& Port = 0u);
	static UMercuryInternetAddr* CreateInternetAddr(const FName& ProtocolType);

	UFUNCTION(BlueprintPure, DisplayName = "Create Network Address", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Address"
	))
	static UMercuryNetworkAddress* CreateNetworkAddress();
	static UMercuryNetworkAddress* CreateNetworkAddress(FIPv4Address* const& Resource);
	static UMercuryNetworkAddress* CreateNetworkAddress(const TSharedPtr<FIPv4Address>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create Network Endpoint", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Endpoint"
	))
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint();
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(FIPv4Endpoint* const& Resource);
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(const TSharedPtr<FIPv4Endpoint>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create Network Mask", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet Mask"
	))
	static UMercuryNetworkMask* CreateNetworkMask();
	static UMercuryNetworkMask* CreateNetworkMask(FIPv4SubnetMask* const& Resource);
	static UMercuryNetworkMask* CreateNetworkMask(const TSharedPtr<FIPv4SubnetMask>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create Network Subnet", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet"
	))
	static UMercuryNetworkSubnet* CreateNetworkSubnet();
	static UMercuryNetworkSubnet* CreateNetworkSubnet(FIPv4Subnet* const& Resource);
	static UMercuryNetworkSubnet* CreateNetworkSubnet(const TSharedPtr<FIPv4Subnet>& Resource);

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Address Port"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddr(int32 Address, int32 Port = 0);

	UFUNCTION(BlueprintPure, DisplayName = "Create Internet Addr (Protocol)", Category = "Mercury|Internet", meta = (
		Keywords = "Create Internet Addr Protocol Type"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddrWithProtocol(const FName& ProtocolType);
};
