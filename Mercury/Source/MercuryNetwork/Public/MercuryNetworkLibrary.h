// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryInternetAddr.h"
#include "MercuryNetworkAddress.h"
#include "MercuryNetworkEndpoint.h"
#include "MercuryNetworkMask.h"
#include "MercuryNetworkSubnet.h"

#include "MercuryNetworkLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Network Blueprint Function Library")
class MERCURYNETWORK_API UMercuryNetworkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Create Internet Addr (Empty)", Category = "Mercury|Network", meta = (
		Keywords = "Create Internet Addr Empty"
	))
	static UMercuryInternetAddr* CreateInternetAddr();
	static UMercuryInternetAddr* CreateInternetAddr(const FInternetAddr& Resource);
	static UMercuryInternetAddr* CreateInternetAddr(const TSharedPtr<FInternetAddr>& Resource);
	static UMercuryInternetAddr* CreateInternetAddr(const uint32& Address, const uint32& Port = 0u);
	static UMercuryInternetAddr* CreateInternetAddr(const FName& ProtocolType);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Network Address", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Address"
	))
	static UMercuryNetworkAddress* CreateNetworkAddress();
	static UMercuryNetworkAddress* CreateNetworkAddress(const FIPv4Address& Resource);
	static UMercuryNetworkAddress* CreateNetworkAddress(const TSharedPtr<FIPv4Address>& Resource);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Network Endpoint", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Endpoint"
	))
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint();
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(const FIPv4Endpoint& Resource);
	static UMercuryNetworkEndpoint* CreateNetworkEndpoint(const TSharedPtr<FIPv4Endpoint>& Resource);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Network Mask", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet Mask"
	))
	static UMercuryNetworkMask* CreateNetworkMask();
	static UMercuryNetworkMask* CreateNetworkMask(const FIPv4SubnetMask& Resource);
	static UMercuryNetworkMask* CreateNetworkMask(const TSharedPtr<FIPv4SubnetMask>& Resource);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Network Subnet", Category = "Mercury|Network", meta = (
		Keywords = "Create Network Subnet"
	))
	static UMercuryNetworkSubnet* CreateNetworkSubnet();
	static UMercuryNetworkSubnet* CreateNetworkSubnet(const FIPv4Subnet& Resource);
	static UMercuryNetworkSubnet* CreateNetworkSubnet(const TSharedPtr<FIPv4Subnet>& Resource);

protected:
	UFUNCTION(BlueprintCallable, DisplayName = "Create Internet Addr", Category = "Mercury|Network", meta = (
		Keywords = "Create Internet Addr Address Port"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddr(int32 Address, int32 Port = 0);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Internet Addr (Protocol)", Category = "Mercury|Network", meta = (
		Keywords = "Create Internet Addr Protocol Type"
	))
	static UMercuryInternetAddr* K2_CreateInternetAddrWithProtocol(const FName& ProtocolType);
};
