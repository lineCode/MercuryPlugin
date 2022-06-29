// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpClassBase.h"

#include "HttpModule.h"

FHttpModule* const UMercuryHttpClassBase::HttpModule = &FHttpModule::Get();


UMercuryHttpClassBase::UMercuryHttpClassBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	check(HttpModule);
}
