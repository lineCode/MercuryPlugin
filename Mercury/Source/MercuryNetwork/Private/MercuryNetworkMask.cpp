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

uint8 UMercuryNetworkMask::GetB() const
{
	return Resource ? Resource->B : 0u;
}

uint8 UMercuryNetworkMask::GetC() const
{
	return Resource ? Resource->C : 0u;
}

uint8 UMercuryNetworkMask::GetD() const
{
	return Resource ? Resource->D : 0u;
}

int32 UMercuryNetworkMask::GetValue() const
{
	return Resource ? Resource->Value : 0;
}

void UMercuryNetworkMask::Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask)
{
	OutMask = UMercuryNetworkLibrary::CreateNetworkMask();
	FIPv4SubnetMask::Parse(MaskString, *OutMask->GetResource());
}
