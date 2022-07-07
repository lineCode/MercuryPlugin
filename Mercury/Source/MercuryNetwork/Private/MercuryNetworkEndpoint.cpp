// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkEndpoint.h"

#include "MercuryInternetAddr.h"
#include "MercuryNetworkAddress.h"


UMercuryNetworkEndpoint::UMercuryNetworkEndpoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Endpoint());
}

UMercuryNetworkAddress* UMercuryNetworkEndpoint::GetAddress() const
{
	if (!Resource)
		return nullptr;
	
	UMercuryNetworkAddress* const&& Address = NewObject<UMercuryNetworkAddress>();
	*Address->GetResource() = Resource->Address;
	return Address;
}

const UMercuryNetworkEndpoint* const& UMercuryNetworkEndpoint::GetAny()
{
	static const UMercuryNetworkEndpoint* const& WebEndpoint = NewObject<const UMercuryNetworkEndpoint>();
	*WebEndpoint->GetResource() = FIPv4Endpoint::Any;
	return WebEndpoint;
}

void UMercuryNetworkEndpoint::Initialize()
{
	FIPv4Endpoint::Initialize();
}

void UMercuryNetworkEndpoint::Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = NewObject<UMercuryNetworkEndpoint>();
	FIPv4Endpoint::Parse(EndpointString, *OutEndpoint->GetResource());
}

uint16 UMercuryNetworkEndpoint::GetPort() const
{
	return Resource ? Resource->Port : 0u;
}

FString UMercuryNetworkEndpoint::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkEndpoint::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

UMercuryInternetAddr* UMercuryNetworkEndpoint::ToInternetAddr() const
{
	if (!Resource)
		return nullptr;

	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->GetResource() = Resource->ToInternetAddr();
	return InternetAddr;
}

bool UMercuryNetworkEndpoint::FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = NewObject<UMercuryNetworkEndpoint>();
	return FIPv4Endpoint::FromHostAndPort(HostAndPortString, *OutEndpoint->GetResource());
}

UMercuryInternetAddr* UMercuryNetworkEndpoint::ToInternetAddrIPv4() const
{
	if (!Resource)
		return nullptr;

	UMercuryInternetAddr* const&& InternetAddr = NewObject<UMercuryInternetAddr>();
	InternetAddr->GetResource() = Resource->ToInternetAddrIPV4();
	return InternetAddr;
}

int32 UMercuryNetworkEndpoint::K2_GetPort() const
{
	return GetPort();
}
