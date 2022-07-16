// Copyright (c) 2022 Kaya Adrian

#include "NetworkSubnet.h"

#include "MercuryNetworkLibrary.h"
#include "NetworkAddress.h"
#include "NetworkMask.h"


TSharedPtr<FIPv4Subnet> UMercuryNetworkSubnet::CreateResource()
{
	return MakeShareable(new FIPv4Subnet());
}

bool UMercuryNetworkSubnet::HasResource() const
{
	return Resource != nullptr;
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::GetAddress() const
{
	return HasResource() ? UMercuryNetworkLibrary::CreateNetworkAddress(new FIPv4Address(Resource->Address)) : nullptr;
}
UMercuryNetworkSubnet* UMercuryNetworkSubnet::SetAddress(const UMercuryNetworkAddress* const& Value)
{
	const TSharedPtr<FIPv4Address>& ValueResource = Value->GetResource();
	if (!HasResource() || !Value || !ValueResource)
		return nullptr;

	Resource->Address = *ValueResource;
	return this;
}

UMercuryNetworkMask* UMercuryNetworkSubnet::GetMask() const
{
	return HasResource() ? UMercuryNetworkLibrary::CreateNetworkMask(new FIPv4SubnetMask(Resource->Mask)) : nullptr;
}
UMercuryNetworkSubnet* UMercuryNetworkSubnet::SetMask(const UMercuryNetworkMask* const& Value)
{
	const TSharedPtr<FIPv4SubnetMask>& ValueResource = Value->GetResource();
	if (!HasResource() || !Value || !ValueResource)
		return nullptr;

	Resource->Mask = *ValueResource;
	return this;
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::BroadcastAddress() const
{
	return HasResource() ?
		UMercuryNetworkLibrary::CreateNetworkAddress(new FIPv4Address(Resource->BroadcastAddress())) : nullptr;
}

bool UMercuryNetworkSubnet::ContainsAddress(const UMercuryNetworkAddress* const& TestAddress) const
{
	return HasResource() && Resource->ContainsAddress(*TestAddress->GetResource());
}

FString UMercuryNetworkSubnet::ToString() const
{
	return HasResource() ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkSubnet::ToText() const
{
	return HasResource() ? Resource->ToText() : FText::GetEmpty();
}

void UMercuryNetworkSubnet::Parse(const FString& SubnetString, UMercuryNetworkSubnet*& OutSubnet)
{
	OutSubnet = UMercuryNetworkLibrary::CreateNetworkSubnet();
	FIPv4Subnet::Parse(SubnetString, *OutSubnet->GetResource());
}
