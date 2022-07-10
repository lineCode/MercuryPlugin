// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkLibrary.h"


UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr()
{
	return CreateInternetAddr(nullptr);
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(FInternetAddr* const& Resource)
{
	return CreateInternetAddr(MakeShareable(Resource));
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const TSharedPtr<FInternetAddr>& Resource)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->SetResource(Resource ? Resource : InternetAddr->CreateResource());
	return InternetAddr;
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const uint32& Address, const uint32& Port)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->SetResource(InternetAddr->CreateResource());
	InternetAddr->SetIp(Address);
	InternetAddr->SetPort(Port);
	return InternetAddr;
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const FName& ProtocolType)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->SetResource(InternetAddr->CreateResource(ProtocolType));
	return NewObject<UMercuryInternetAddr>();
}

UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress()
{
	return CreateNetworkAddress(nullptr);
}
UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress(FIPv4Address* const& Resource)
{
	return CreateNetworkAddress(MakeShareable(Resource));
}
UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress(const TSharedPtr<FIPv4Address>& Resource)
{
	UMercuryNetworkAddress* const&& NetworkAddress = NewObject<UMercuryNetworkAddress>();
	NetworkAddress->SetResource(Resource ? Resource : NetworkAddress->CreateResource());
	return NetworkAddress;
}

UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint()
{
	return CreateNetworkEndpoint(nullptr);
}
UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint(FIPv4Endpoint* const& Resource)
{
	return CreateNetworkEndpoint(MakeShareable(Resource));
}
UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint(const TSharedPtr<FIPv4Endpoint>& Resource)
{
	UMercuryNetworkEndpoint* const&& NetworkEndpoint = NewObject<UMercuryNetworkEndpoint>();
	NetworkEndpoint->SetResource(Resource ? Resource : NetworkEndpoint->CreateResource());
	return NetworkEndpoint;
}

UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask()
{
	return CreateNetworkMask(nullptr);
}
UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask(FIPv4SubnetMask* const& Resource)
{
	return CreateNetworkMask(MakeShareable(Resource));
}
UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask(const TSharedPtr<FIPv4SubnetMask>& Resource)
{
	UMercuryNetworkMask* const&& NetworkMask = NewObject<UMercuryNetworkMask>();
	NetworkMask->SetResource(Resource ? Resource : NetworkMask->CreateResource());
	return NetworkMask;
}

UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet()
{
	return CreateNetworkSubnet(nullptr);
}
UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet(FIPv4Subnet* const& Resource)
{
	return CreateNetworkSubnet(MakeShareable(Resource));
}
UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet(const TSharedPtr<FIPv4Subnet>& Resource)
{
	UMercuryNetworkSubnet* const&& NetworkSubnet = NewObject<UMercuryNetworkSubnet>();
	NetworkSubnet->SetResource(Resource ? Resource : NetworkSubnet->CreateResource());
	return NetworkSubnet;
}

UMercuryInternetAddr* UMercuryNetworkLibrary::K2_CreateInternetAddr(const int32 Address, const int32 Port)
{
	return CreateInternetAddr(Address, Port);
}

UMercuryInternetAddr* UMercuryNetworkLibrary::K2_CreateInternetAddrWithProtocol(const FName& ProtocolType)
{
	return CreateInternetAddr(ProtocolType);
}
