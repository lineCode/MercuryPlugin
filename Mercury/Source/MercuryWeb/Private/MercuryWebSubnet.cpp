// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebSubnet.h"

#include "MercuryWebAddress.h"
#include "Interfaces/IPv4/IPv4Subnet.h"


UMercuryWebSubnet::UMercuryWebSubnet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4Subnet());
}

UMercuryWebAddress* UMercuryWebSubnet::GetAddress() const
{
	if (!Resource)
		return nullptr;
	
	UMercuryWebAddress* const&& Address = NewObject<UMercuryWebAddress>();
	*Address->GetResource() = Resource->Address;
	return Address;
}
/*
UMercuryWebSubnetMask* UMercuryWebSubnet::GetMask() const
{
	if (!Resource)
		return nullptr;

	UMercuryWebSubnetMask* const&& Mask = NewObject<UMercuryWebSubnetMask>();
	*Mask->GetResource() = Resource->Mask;
	return Mask;
}*/

UMercuryWebAddress* UMercuryWebSubnet::BroadcastAddress() const
{
	if (!Resource)
		return nullptr;

	UMercuryWebAddress* const&& Address = NewObject<UMercuryWebAddress>();
	*Address->GetResource() = Resource->BroadcastAddress();
	return Address;
}

bool UMercuryWebSubnet::ContainsAddress(const UMercuryWebAddress* const& TestAddress) const
{
	return Resource && Resource->ContainsAddress(*TestAddress->GetResource());
}

FString UMercuryWebSubnet::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryWebSubnet::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

void UMercuryWebSubnet::Parse(const FString& SubnetString, UMercuryWebSubnet*& OutSubnet)
{
	OutSubnet = NewObject<UMercuryWebSubnet>();
	FIPv4Subnet::Parse(SubnetString, *OutSubnet->GetResource());
}
