// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebAddress.h"


UMercuryWebAddress::UMercuryWebAddress(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Reference = MakeShareable(new FIPv4Address());
}
