// Copyright (c) 2022 Kaya Adrian

#include "NetworkAddress.h"

#include "MercuryNetworkLibrary.h"


TSharedPtr<FIPv4Address> UMercuryNetworkAddress::CreateResource()
{
	return MakeShareable(new FIPv4Address());
}

bool UMercuryNetworkAddress::HasResource() const
{
	return Resource != nullptr;
}

uint8 UMercuryNetworkAddress::GetA() const
{
	return HasResource() ? Resource->A : 0u;
}
UMercuryNetworkAddress* UMercuryNetworkAddress::SetA(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->A = Value;
	return this;
}

uint8 UMercuryNetworkAddress::GetB() const
{
	return HasResource() ? Resource->B : 0u;
}
UMercuryNetworkAddress* UMercuryNetworkAddress::SetB(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->B = Value;
	return this;
}

uint8 UMercuryNetworkAddress::GetC() const
{
	return HasResource() ? Resource->C : 0u;
}
UMercuryNetworkAddress* UMercuryNetworkAddress::SetC(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->C = Value;
	return this;
}

uint8 UMercuryNetworkAddress::GetD() const
{
	return HasResource() ? Resource->D : 0u;
}
UMercuryNetworkAddress* UMercuryNetworkAddress::SetD(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->D = Value;
	return this;
}

uint32 UMercuryNetworkAddress::GetValue() const
{
	return HasResource() ? Resource->Value : 0u;
}
UMercuryNetworkAddress* UMercuryNetworkAddress::SetValue(const uint32& Value)
{
	if (!HasResource())
		return nullptr;

	Resource->Value = Value;
	return this;
}

FString UMercuryNetworkAddress::ToString() const
{
	return HasResource() ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkAddress::ToText() const
{
	return HasResource() ? Resource->ToText() : FText::GetEmpty();
}

bool UMercuryNetworkAddress::IsGlobalMulticast() const
{
	return HasResource() && Resource->IsGlobalMulticast();
}

bool UMercuryNetworkAddress::IsLinkLocal() const
{
	return HasResource() && Resource->IsLinkLocal();
}

bool UMercuryNetworkAddress::IsLoopbackAddress() const
{
	return HasResource() && Resource->IsLoopbackAddress();
}

bool UMercuryNetworkAddress::IsMulticastAddress() const
{
	return HasResource() && Resource->IsMulticastAddress();
}

bool UMercuryNetworkAddress::IsLinkLocalMulticast() const
{
	return HasResource() && Resource->IsLinkLocalMulticast();
}

bool UMercuryNetworkAddress::IsOrganizationLocalMulticast() const
{
	return HasResource() && Resource->IsOrganizationLocalMulticast();
}

bool UMercuryNetworkAddress::IsSessionFrontendMulticast() const
{
	return HasResource() && Resource->IsSessionFrontendMulticast();
}

bool UMercuryNetworkAddress::IsSiteLocalAddress() const
{
	return HasResource() && Resource->IsSiteLocalAddress();
}

bool UMercuryNetworkAddress::IsSiteLocalMulticast() const
{
	return HasResource() && Resource->IsSiteLocalMulticast();
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetAny()
{
	static const UMercuryNetworkAddress* const&& Address = UMercuryNetworkLibrary::CreateNetworkAddress(
		new FIPv4Address(FIPv4Address::Any)
	);
	return Address;
}

void UMercuryNetworkAddress::Parse(const FString& AddressString, UMercuryNetworkAddress*& OutAddress)
{
	OutAddress = UMercuryNetworkLibrary::CreateNetworkAddress();
	FIPv4Address::Parse(AddressString, *OutAddress->GetResource());
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetInternalLoopback()
{
	static const UMercuryNetworkAddress* const&& Address = UMercuryNetworkLibrary::CreateNetworkAddress(
		new FIPv4Address(FIPv4Address::InternalLoopback)
	);
	return Address;
}

const UMercuryNetworkAddress* const& UMercuryNetworkAddress::GetLanBroadcast()
{
	static const UMercuryNetworkAddress* const&& Address = UMercuryNetworkLibrary::CreateNetworkAddress(
		new FIPv4Address(FIPv4Address::LanBroadcast)
	);
	return Address;
}

int32 UMercuryNetworkAddress::K2_GetValue() const
{
	return GetValue();
}
UMercuryNetworkAddress* UMercuryNetworkAddress::K2_SetValue(const int32 Value)
{
	return SetValue(Value);
}
