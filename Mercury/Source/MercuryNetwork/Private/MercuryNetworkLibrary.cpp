// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkLibrary.h"


UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr()
{
	return CreateInternetAddr(nullptr);
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const FInternetAddr& Resource)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	*InternetAddr->GetResource() = Resource;
	return InternetAddr;
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const TSharedPtr<FInternetAddr>& Resource)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->GetResource() = Resource ? Resource : InternetAddr->CreateResource();
	return InternetAddr;
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const uint32& Address, const uint32& Port)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->GetResource() = InternetAddr->CreateResource();
	InternetAddr->SetIp(Address);
	InternetAddr->SetPort(Port);
	return InternetAddr;
}
UMercuryInternetAddr* UMercuryNetworkLibrary::CreateInternetAddr(const FName& ProtocolType)
{
	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->GetResource() = InternetAddr->CreateResource(ProtocolType);
	return NewObject<UMercuryInternetAddr>();
}

UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress()
{
	return CreateNetworkAddress(nullptr);
}
UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress(const FIPv4Address& Resource)
{
	UMercuryNetworkAddress* const&& NetworkAddress = NewObject<UMercuryNetworkAddress>();
	*NetworkAddress->GetResource() = Resource;
	return NetworkAddress;
}
UMercuryNetworkAddress* UMercuryNetworkLibrary::CreateNetworkAddress(const TSharedPtr<FIPv4Address>& Resource)
{
	UMercuryNetworkAddress* const&& NetworkAddress = NewObject<UMercuryNetworkAddress>();
	NetworkAddress->GetResource() = Resource ? Resource : NetworkAddress->CreateResource();
	return NetworkAddress;
}

UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint()
{
	return CreateNetworkEndpoint(nullptr);
}
UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint(const FIPv4Endpoint& Resource)
{
	UMercuryNetworkEndpoint* const&& NetworkEndpoint = NewObject<UMercuryNetworkEndpoint>();
	*NetworkEndpoint->GetResource() = Resource;
	return NetworkEndpoint;
}
UMercuryNetworkEndpoint* UMercuryNetworkLibrary::CreateNetworkEndpoint(const TSharedPtr<FIPv4Endpoint>& Resource)
{
	UMercuryNetworkEndpoint* const&& NetworkEndpoint = NewObject<UMercuryNetworkEndpoint>();
	NetworkEndpoint->GetResource() = Resource ? Resource : NetworkEndpoint->CreateResource();
	return NetworkEndpoint;
}

UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask()
{
	return CreateNetworkMask(nullptr);
}
UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask(const FIPv4SubnetMask& Resource)
{
	UMercuryNetworkMask* const&& NetworkMask = NewObject<UMercuryNetworkMask>();
	*NetworkMask->GetResource() = Resource;
	return NetworkMask;
}
UMercuryNetworkMask* UMercuryNetworkLibrary::CreateNetworkMask(const TSharedPtr<FIPv4SubnetMask>& Resource)
{
	UMercuryNetworkMask* const&& NetworkMask = NewObject<UMercuryNetworkMask>();
	NetworkMask->GetResource() = Resource ? Resource : NetworkMask->CreateResource();
	return NetworkMask;
}

UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet()
{
	return CreateNetworkSubnet(nullptr);
}
UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet(const FIPv4Subnet& Resource)
{
	UMercuryNetworkSubnet* const&& NetworkSubnet = NewObject<UMercuryNetworkSubnet>();
	*NetworkSubnet->GetResource() = Resource;
	return NetworkSubnet;
}
UMercuryNetworkSubnet* UMercuryNetworkLibrary::CreateNetworkSubnet(const TSharedPtr<FIPv4Subnet>& Resource)
{
	UMercuryNetworkSubnet* const&& NetworkSubnet = NewObject<UMercuryNetworkSubnet>();
	NetworkSubnet->GetResource() = Resource ? Resource : NetworkSubnet->CreateResource();
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
