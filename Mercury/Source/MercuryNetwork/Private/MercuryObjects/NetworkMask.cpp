// Copyright (c) 2022 Kaya Adrian

#include "NetworkMask.h"

#include "MercuryNetworkLibrary.h"


TSharedPtr<FIPv4SubnetMask> UMercuryNetworkMask::CreateResource()
{
	return MakeShareable(new FIPv4SubnetMask());
}

bool UMercuryNetworkMask::HasResource() const
{
	return Resource != nullptr;
}

EMercuryNetworkSubnetClass UMercuryNetworkMask::GetSubnetClass() const
{
	return MercuryEnums::SubnetMask::Convert(HasResource() ? Resource->GetClass() : EIPv4SubnetClasses::Invalid);
}

FString UMercuryNetworkMask::ToString() const
{
	return HasResource() ? Resource->ToString() : TEXT("");
}

FText UMercuryNetworkMask::ToText() const
{
	return HasResource() ? Resource->ToText() : FText::GetEmpty();
}

uint8 UMercuryNetworkMask::GetA() const
{
	return HasResource() ? Resource->A : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetA(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->A = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetB() const
{
	return HasResource() ? Resource->B : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetB(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->B = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetC() const
{
	return HasResource() ? Resource->C : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetC(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->C = Value;
	return this;
}

uint8 UMercuryNetworkMask::GetD() const
{
	return HasResource() ? Resource->D : 0u;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetD(const uint8 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->D = Value;
	return this;
}

int32 UMercuryNetworkMask::GetValue() const
{
	return HasResource() ? Resource->Value : 0;
}
UMercuryNetworkMask* UMercuryNetworkMask::SetValue(const int32 Value)
{
	if (!HasResource())
		return nullptr;

	Resource->Value = Value;
	return this;
}

void UMercuryNetworkMask::Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask)
{
	OutMask = UMercuryNetworkLibrary::CreateNetworkMask();
	FIPv4SubnetMask::Parse(MaskString, *OutMask->GetResource());
}
