// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebSubnetMask.h"

#include "Interfaces/IPv4/IPv4SubnetMask.h"
#include "MercuryWeb.h"


UMercuryWebSubnetMask::UMercuryWebSubnetMask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = MakeShareable(new FIPv4SubnetMask());
}

EMercuryWebSubnetMaskClass UMercuryWebSubnetMask::GetSubnetClass() const
{
	switch (const EIPv4SubnetClasses::Type&& Class = Resource ? Resource->GetClass() : EIPv4SubnetClasses::Invalid)
	{
	case EIPv4SubnetClasses::Invalid:
		return EMercuryWebSubnetMaskClass::Invalid;

	case EIPv4SubnetClasses::ClassA:
		return EMercuryWebSubnetMaskClass::ClassA;

	case EIPv4SubnetClasses::ClassB:
		return EMercuryWebSubnetMaskClass::ClassB;

	case EIPv4SubnetClasses::ClassC:
		return EMercuryWebSubnetMaskClass::ClassC;

	default:
		UE_LOG(LogMercuryWeb, Error, TEXT("Unknown subnet class: %d"), Class);
		return EMercuryWebSubnetMaskClass::Invalid;
	}
}

FString UMercuryWebSubnetMask::ToString() const
{
	return Resource ? Resource->ToString() : TEXT("");
}

FText UMercuryWebSubnetMask::ToText() const
{
	return Resource ? Resource->ToText() : FText::GetEmpty();
}

uint8 UMercuryWebSubnetMask::GetA() const
{
	return Resource ? Resource->A : 0u;
}

uint8 UMercuryWebSubnetMask::GetB() const
{
	return Resource ? Resource->B : 0u;
}

uint8 UMercuryWebSubnetMask::GetC() const
{
	return Resource ? Resource->C : 0u;
}

uint8 UMercuryWebSubnetMask::GetD() const
{
	return Resource ? Resource->D : 0u;
}

int32 UMercuryWebSubnetMask::GetValue() const
{
	return Resource ? Resource->Value : 0;
}

void UMercuryWebSubnetMask::Parse(const FString& MaskString, UMercuryWebSubnetMask*& OutMask)
{
	OutMask = NewObject<UMercuryWebSubnetMask>();
	FIPv4SubnetMask::Parse(MaskString, *OutMask->GetResource());
}
