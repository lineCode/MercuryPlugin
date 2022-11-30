// Copyright (c) 2022 Kaya Adrian

#include "NetworkEndpoint.h"

#include "MercuryNetworkLibrary.h"
#include "NetworkAddress.h"


TSharedPtr<FIPv4Endpoint> UMercuryNetworkEndpoint::CreateResource()
{
	return MakeShareable(new FIPv4Endpoint());
}

bool UMercuryNetworkEndpoint::HasResource() const
{
	return Resource != nullptr;
}

UMercuryNetworkAddress* UMercuryNetworkEndpoint::GetAddress() const
{
	return HasResource() ? UMercuryNetworkLibrary::CreateNetworkAddress(new FIPv4Address(Resource->Address)) : nullptr;
}
UMercuryNetworkEndpoint* UMercuryNetworkEndpoint::SetAddress(const UMercuryNetworkAddress* const& Value)
{
	const TSharedPtr<FIPv4Address>& ValueResource = Value->GetResource();
	if (!HasResource() || !Value || !ValueResource)
		return nullptr;

	Resource->Address = *ValueResource;
	return this;
}

const UMercuryNetworkEndpoint* const& UMercuryNetworkEndpoint::GetAny()
{
	static const UMercuryNetworkEndpoint* const&& WebEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint(
		new FIPv4Endpoint(FIPv4Endpoint::Any)
	);
	return WebEndpoint;
}

void UMercuryNetworkEndpoint::Initialize()
{
	FIPv4Endpoint::Initialize();
}

bool UMercuryNetworkEndpoint::Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint();
	return FIPv4Endpoint::Parse(EndpointString, *OutEndpoint->GetResource());
}

uint16 UMercuryNetworkEndpoint::GetPort() const
{
	return HasResource() ? Resource->Port : 0u;
}
UMercuryNetworkEndpoint* UMercuryNetworkEndpoint::SetPort(const uint16& Value)
{
	if (!HasResource())
		return nullptr;

	Resource->Port = Value;
	return this;
}

FString UMercuryNetworkEndpoint::ToString() const
{
	return HasResource() ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkEndpoint::ToText() const
{
	return HasResource() ? Resource->ToText() : FText::GetEmpty();
}

UMercuryInternetAddr* UMercuryNetworkEndpoint::ToInternetAddr() const
{
	return HasResource() ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->ToInternetAddr()) : nullptr;
}

bool UMercuryNetworkEndpoint::FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint)
{
	OutEndpoint = UMercuryNetworkLibrary::CreateNetworkEndpoint();
	return FIPv4Endpoint::FromHostAndPort(HostAndPortString, *OutEndpoint->GetResource());
}

UMercuryInternetAddr* UMercuryNetworkEndpoint::ToInternetAddrIPv4() const
{
	return HasResource() ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->ToInternetAddrIPV4()) : nullptr;
}

int32 UMercuryNetworkEndpoint::K2_GetPort() const
{
	return GetPort();
}
UMercuryNetworkEndpoint* UMercuryNetworkEndpoint::K2_SetPort(const int32 Value)
{
	return SetPort(Value);
}
