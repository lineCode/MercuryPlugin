// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetworkMask.h"

#include "MercuryNetworkLibrary.h"


TSharedPtr<FIPv4SubnetMask> UMercuryNetworkMask::CreateResource()
{
	return MakeShareable(new FIPv4SubnetMask());
}

EMercuryNetworkSubnetClass UMercuryNetworkMask::GetSubnetClass() const
{
	return MercuryEnums::SubnetMask::Convert(Resource ? Resource->GetClass() : EIPv4SubnetClasses::Invalid);
}

FString UMercuryNetworkMask::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkMask::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

uint8 UMercuryNetworkMask::GetA() const
{
	return Resource ? Resource->A : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetA(const uint8 Value)
{
	if (!Resource)
		return nullptr;

	Resource->A = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetB() const
{
	return Resource ? Resource->B : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetB(const uint8 Value)
{
	if (!Resource)
		return nullptr;

	Resource->B = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetC() const
{
	return Resource ? Resource->C : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetC(const uint8 Value)
{
	if (!Resource)
		return nullptr;

	Resource->C = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetD() const
{
	return Resource ? Resource->D : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetD(const uint8 Value)
{
	if (!Resource)
		return nullptr;

	Resource->D = Value;
	return this;
}

int32 UMercuryNetworkMask::GetValue() const
{
	return Resource ? Resource->Value : 0;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetValue(const int32 Value)
{
	if (!Resource)
		return nullptr;

	Resource->Value = Value;
	return this;
}

void UMercuryNetworkMask::Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask)
{
	OutMask = UMercuryNetworkLibrary::CreateNetworkMask();
	FIPv4SubnetMask::Parse(MaskString, *OutMask->GetResource());
}
