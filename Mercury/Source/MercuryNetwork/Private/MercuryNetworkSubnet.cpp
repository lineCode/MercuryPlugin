﻿// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkSubnet.h"

#include "Interfaces/IPv4/IPv4Subnet.h"
#include "MercuryNetworkAddress.h"
#include "MercuryNetworkSubnetMask.h"


UMercuryNetworkSubnet::UMercuryNetworkSubnet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Subnet());
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::GetAddress() const
{
	if (!Resource)
		return nullptr;
	
	UMercuryNetworkAddress* const&& Address = NewObject<UMercuryNetworkAddress>();
	*Address->GetResource() = Resource->Address;
	return Address;
}

UMercuryNetworkSubnetMask* UMercuryNetworkSubnet::GetMask() const
{
	if (!Resource)
		return nullptr;

	UMercuryNetworkSubnetMask* const&& Mask = NewObject<UMercuryNetworkSubnetMask>();
	*Mask->GetResource() = Resource->Mask;
	return Mask;
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::BroadcastAddress() const
{
	if (!Resource)
		return nullptr;

	UMercuryNetworkAddress* const&& Address = NewObject<UMercuryNetworkAddress>();
	*Address->GetResource() = Resource->BroadcastAddress();
	return Address;
}

bool UMercuryNetworkSubnet::ContainsAddress(const UMercuryNetworkAddress* const& TestAddress) const
{
	return Resource && Resource->ContainsAddress(*TestAddress->GetResource());
}

FString UMercuryNetworkSubnet::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkSubnet::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

void UMercuryNetworkSubnet::Parse(const FString& SubnetString, UMercuryNetworkSubnet*& OutSubnet)
{
	OutSubnet = NewObject<UMercuryNetworkSubnet>();
	FIPv4Subnet::Parse(SubnetString, *OutSubnet->GetResource());
}