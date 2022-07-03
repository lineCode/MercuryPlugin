// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkAddress.h"

#include "Interfaces/IPv4/IPv4Address.h"


UMercuryNetworkAddress::UMercuryNetworkAddress(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Address());
}

uint8 UMercuryNetworkAddress::GetA() const
{
	return Resource ? Resource->A : 0u;
}

uint8 UMercuryNetworkAddress::GetB() const
{
	return Resource ? Resource->B : 0u;
}

uint8 UMercuryNetworkAddress::GetC() const
{
	return Resource ? Resource->C : 0u;
}

uint8 UMercuryNetworkAddress::GetD() const
{
	return Resource ? Resource->D : 0u;
}

uint32 UMercuryNetworkAddress::GetValue() const
{
	return Resource ? Resource->Value : 0u;
}

FString UMercuryNetworkAddress::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkAddress::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

bool UMercuryNetworkAddress::IsGlobalMulticast() const
{
	return Resource && Resource->IsGlobalMulticast();
}

bool UMercuryNetworkAddress::IsLinkLocal() const
{
	return Resource && Resource->IsLinkLocal();
}

bool UMercuryNetworkAddress::IsLoopbackAddress() const
{
	return Resource && Resource->IsLoopbackAddress();
}

bool UMercuryNetworkAddress::IsMulticastAddress() const
{
	return Resource && Resource->IsMulticastAddress();
}

bool UMercuryNetworkAddress::IsLinkLocalMulticast() const
{
	return Resource && Resource->IsLinkLocalMulticast();
}

bool UMercuryNetworkAddress::IsOrganizationLocalMulticast() const
{
	return Resource && Resource->IsOrganizationLocalMulticast();
}

bool UMercuryNetworkAddress::IsSessionFrontendMulticast() const
{
	return Resource && Resource->IsSessionFrontendMulticast();
}

bool UMercuryNetworkAddress::IsSiteLocalAddress() const
{
	return Resource && Resource->IsSiteLocalAddress();
}

bool UMercuryNetworkAddress::IsSiteLocalMulticast() const
{
	return Resource && Resource->IsSiteLocalMulticast();
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetAny()
{
	static const UMercuryNetworkAddress* const& Address = NewObject<const UMercuryNetworkAddress>();
	*Address->GetResource() = FIPv4Address::Any;
	return Address;
}

void UMercuryNetworkAddress::Parse(const FString& AddressString, UMercuryNetworkAddress*& OutAddress)
{
	OutAddress = NewObject<UMercuryNetworkAddress>();
	FIPv4Address::Parse(AddressString, *OutAddress->GetResource());
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetInternalLoopback()
{
	static const UMercuryNetworkAddress* const& Address = NewObject<const UMercuryNetworkAddress>();
	*Address->GetResource() = FIPv4Address::InternalLoopback;
	return Address;
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetLanBroadcast()
{
	static const UMercuryNetworkAddress* const& Address = NewObject<const UMercuryNetworkAddress>();
	*Address->GetResource() = FIPv4Address::LanBroadcast;
	return Address;
}

int32 UMercuryNetworkAddress::K2_GetValue() const
{
	return GetValue();
}
