// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkSubnetMask.h"

#include "Interfaces/IPv4/IPv4SubnetMask.h"
#include "MercuryNetwork.h"


UMercuryNetworkSubnetMask::UMercuryNetworkSubnetMask(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4SubnetMask());
}

EMercuryNetworkSubnetMaskClass UMercuryNetworkSubnetMask::GetSubnetClass() const
{
	switch (const EIPv4SubnetClasses::Type&& Class = Resource ? Resource->GetClass() : EIPv4SubnetClasses::Invalid)
	{
	case EIPv4SubnetClasses::Invalid:
		return EMercuryNetworkSubnetMaskClass::Invalid;

	case EIPv4SubnetClasses::ClassA:
		return EMercuryNetworkSubnetMaskClass::ClassA;

	case EIPv4SubnetClasses::ClassB:
		return EMercuryNetworkSubnetMaskClass::ClassB;

	case EIPv4SubnetClasses::ClassC:
		return EMercuryNetworkSubnetMaskClass::ClassC;

	default:
		UE_LOG(LogMercuryNetwork, Error, TEXT("Unknown subnet class: %d"), Class);
		return EMercuryNetworkSubnetMaskClass::Invalid;
	}
}

FString UMercuryNetworkSubnetMask::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkSubnetMask::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

uint8 UMercuryNetworkSubnetMask::GetA() const
{
	return Resource ? Resource->A : 0u;
}

uint8 UMercuryNetworkSubnetMask::GetB() const
{
	return Resource ? Resource->B : 0u;
}

uint8 UMercuryNetworkSubnetMask::GetC() const
{
	return Resource ? Resource->C : 0u;
}

uint8 UMercuryNetworkSubnetMask::GetD() const
{
	return Resource ? Resource->D : 0u;
}

int32 UMercuryNetworkSubnetMask::GetValue() const
{
	return Resource ? Resource->Value : 0;
}

void UMercuryNetworkSubnetMask::Parse(const FString& MaskString, UMercuryNetworkSubnetMask*& OutMask)
{
	OutMask = NewObject<UMercuryNetworkSubnetMask>();
	FIPv4SubnetMask::Parse(MaskString, *OutMask->GetResource());
}
