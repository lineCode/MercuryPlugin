// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkSubnet.h"

#include "MercuryNetworkAddress.h"
#include "MercuryNetworkLibrary.h"
#include "MercuryNetworkMask.h"


TSharedPtr<FIPv4Subnet> UMercuryNetworkSubnet::CreateResource()
{
	return MakeShareable(new FIPv4Subnet());
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::GetAddress() const
{
	return Resource ? UMercuryNetworkLibrary::CreateNetworkAddress(Resource->Address) : nullptr;
}

UMercuryNetworkMask* UMercuryNetworkSubnet::GetMask() const
{
	return Resource ? UMercuryNetworkLibrary::CreateNetworkMask(Resource->Mask) : nullptr;
}

UMercuryNetworkAddress* UMercuryNetworkSubnet::BroadcastAddress() const
{
	return Resource ? UMercuryNetworkLibrary::CreateNetworkAddress(Resource->BroadcastAddress()) : nullptr;
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
	OutSubnet = UMercuryNetworkLibrary::CreateNetworkSubnet();
	FIPv4Subnet::Parse(SubnetString, *OutSubnet->GetResource());
}
