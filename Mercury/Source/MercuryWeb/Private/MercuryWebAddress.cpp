// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebAddress.h"

#include "Interfaces/IPv4/IPv4Address.h"


UMercuryWebAddress::UMercuryWebAddress(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Address());
}

uint8 UMercuryWebAddress::GetA() const
{
	return Resource ? Resource->A : 0u;
}

uint8 UMercuryWebAddress::GetB() const
{
	return Resource ? Resource->B : 0u;
}

uint8 UMercuryWebAddress::GetC() const
{
	return Resource ? Resource->C : 0u;
}

uint8 UMercuryWebAddress::GetD() const
{
	return Resource ? Resource->D : 0u;
}

uint32 UMercuryWebAddress::GetValue() const
{
	return Resource ? Resource->Value : 0u;
}

FString UMercuryWebAddress::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryWebAddress::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

bool UMercuryWebAddress::IsGlobalMulticast() const
{
	return Resource && Resource->IsGlobalMulticast();
}

bool UMercuryWebAddress::IsLinkLocal() const
{
	return Resource && Resource->IsLinkLocal();
}

bool UMercuryWebAddress::IsLoopbackAddress() const
{
	return Resource && Resource->IsLoopbackAddress();
}

bool UMercuryWebAddress::IsMulticastAddress() const
{
	return Resource && Resource->IsMulticastAddress();
}

bool UMercuryWebAddress::IsLinkLocalMulticast() const
{
	return Resource && Resource->IsLinkLocalMulticast();
}

bool UMercuryWebAddress::IsOrganizationLocalMulticast() const
{
	return Resource && Resource->IsOrganizationLocalMulticast();
}

bool UMercuryWebAddress::IsSessionFrontendMulticast() const
{
	return Resource && Resource->IsSessionFrontendMulticast();
}

bool UMercuryWebAddress::IsSiteLocalAddress() const
{
	return Resource && Resource->IsSiteLocalAddress();
}

bool UMercuryWebAddress::IsSiteLocalMulticast() const
{
	return Resource && Resource->IsSiteLocalMulticast();
}

const UMercuryWebAddress* const& UMercuryWebAddress::GetAny()
{
	static const UMercuryWebAddress* const& WebAddress = NewObject<const UMercuryWebAddress>();
	*WebAddress->GetResource() = FIPv4Address::Any;
	return WebAddress;
}

void UMercuryWebAddress::Parse(const FString& AddressString, UMercuryWebAddress*& OutAddress)
{
	OutAddress = NewObject<UMercuryWebAddress>();
	FIPv4Address::Parse(AddressString, *OutAddress->GetResource());
}

const UMercuryWebAddress* const& UMercuryWebAddress::GetInternalLoopback()
{
	static const UMercuryWebAddress* const& WebAddress = NewObject<const UMercuryWebAddress>();
	*WebAddress->GetResource() = FIPv4Address::InternalLoopback;
	return WebAddress;
}

const UMercuryWebAddress* const& UMercuryWebAddress::GetLanBroadcast()
{
	static const UMercuryWebAddress* const& WebAddress = NewObject<const UMercuryWebAddress>();
	*WebAddress->GetResource() = FIPv4Address::LanBroadcast;
	return WebAddress;
}

int32 UMercuryWebAddress::K2_GetValue() const
{
	return GetValue();
}
