// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkEndpoint.h"

#include "MercuryInternetAddr.h"
#include "MercuryNetworkAddress.h"
#include "MercuryNetworkLibrary.h"


TSharedPtr<FIPv4Endpoint> UMercuryNetworkEndpoint::CreateResource()
{
	return MakeShareable(new FIPv4Endpoint());
}

UMercuryNetworkAddress* UMercuryNetworkEndpoint::GetAddress() const
{
	return Resource ? UMercuryNetworkLibrary::CreateNetworkAddress(Resource->Address) : nullptr;
}

const UMercuryNetworkEndpoint* const& UMercuryNetworkEndpoint::GetAny()
{
	static const UMercuryNetworkEndpoint* const&& WebEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint(
		FIPv4Endpoint::Any
	);
	return WebEndpoint;
}

void UMercuryNetworkEndpoint::Initialize()
{
	FIPv4Endpoint::Initialize();
}

void UMercuryNetworkEndpoint::Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint();
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
	return Resource ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->ToInternetAddr()) : nullptr;
}

bool UMercuryNetworkEndpoint::FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint();
	return FIPv4Endpoint::FromHostAndPort(HostAndPortString, *OutEndpoint->GetResource());
}

UMercuryInternetAddr* UMercuryNetworkEndpoint::ToInternetAddrIPv4() const
{
	return Resource ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->ToInternetAddrIPV4()) : nullptr;
}

int32 UMercuryNetworkEndpoint::K2_GetPort() const
{
	return GetPort();
}
