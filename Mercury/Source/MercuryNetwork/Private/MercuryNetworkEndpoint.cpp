// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkEndpoint.h"

#include "Interfaces/IPv4/IPv4Endpoint.h"
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

TSharedPtr<FInternetAddr> UMercuryNetworkEndpoint::ToInternetAddr() const
{
	return Resource ? MakeShareable(&Resource->ToInternetAddr().Get()) : nullptr;
}

bool UMercuryNetworkEndpoint::FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = NewObject<UMercuryNetworkEndpoint>();
	return FIPv4Endpoint::FromHostAndPort(HostAndPortString, *OutEndpoint->GetResource());
}

TSharedPtr<FInternetAddr> UMercuryNetworkEndpoint::ToInternetAddrIPv4() const
{
	return Resource ? MakeShareable(&Resource->ToInternetAddrIPV4().Get()) : nullptr;
}

int32 UMercuryNetworkEndpoint::K2_GetPort() const
{
	return GetPort();
}
