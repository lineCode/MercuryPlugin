// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebClassBase.h"

#include "SocketSubsystem.h"

ISocketSubsystem* const UMercuryWebClassBase::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


UMercuryWebClassBase::UMercuryWebClassBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	check(SocketSubsystem);
}
