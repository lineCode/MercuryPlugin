// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebEndpoint.h"

#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "MercuryWeb.h"
#include "MercuryWebAddress.h"


UMercuryWebEndpoint::UMercuryWebEndpoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Endpoint());
}

UMercuryWebAddress* UMercuryWebEndpoint::GetAddress() const
{
	if (!Resource)
		return nullptr;
	
	UMercuryWebAddress* const&& Address = NewObject<UMercuryWebAddress>();
	*Address->GetResource() = Resource->Address;
	return Address;
}

const UMercuryWebEndpoint* const& UMercuryWebEndpoint::GetAny()
{
	static const UMercuryWebEndpoint* const& WebEndpoint = NewObject<const UMercuryWebEndpoint>();
	*WebEndpoint->GetResource() = FIPv4Endpoint::Any;
	return WebEndpoint;
}

void UMercuryWebEndpoint::Initialize()
{
	FIPv4Endpoint::Initialize();
}

void UMercuryWebEndpoint::Parse(const FString& EndpointString, UMercuryWebEndpoint*& OutEndpoint)
{
	OutEndpoint = NewObject<UMercuryWebEndpoint>();
	FIPv4Endpoint::Parse(EndpointString, *OutEndpoint->GetResource());
}

uint16 UMercuryWebEndpoint::GetPort() const
{
	return Resource ? Resource->Port : 0u;
}

FString UMercuryWebEndpoint::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryWebEndpoint::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

TSharedPtr<FInternetAddr> UMercuryWebEndpoint::ToInternetAddr() const
{
	return Resource ? MakeShareable(&Resource->ToInternetAddr().Get()) : nullptr;
}

bool UMercuryWebEndpoint::FromHostAndPort(const FString& HostAndPortString, UMercuryWebEndpoint*& OutEndpoint)
{
	OutEndpoint = NewObject<UMercuryWebEndpoint>();
	return FIPv4Endpoint::FromHostAndPort(HostAndPortString, *OutEndpoint->GetResource());
}

TSharedPtr<FInternetAddr> UMercuryWebEndpoint::ToInternetAddrIPv4() const
{
	return Resource ? MakeShareable(&Resource->ToInternetAddrIPV4().Get()) : nullptr;
}

ISocketSubsystem* const& UMercuryWebEndpoint::CachedSocketSubsystem()
{
	return FMercuryWebModule::GetSocketSubsystem();
}

int32 UMercuryWebEndpoint::K2_GetPort() const
{
	return GetPort();
}
