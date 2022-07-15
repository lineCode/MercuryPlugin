// Copyright (c) 2022 Kaya Adrian

#include "MercuryProtocols.h"

#include "SocketSubsystem.h"

ISocketSubsystem* const FMercuryProtocolsModule::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


DEFINE_LOG_CATEGORY(LogMercuryProtocols);

#define LOCTEXT_NAMESPACE "FMercuryProtocolsModule"

void FMercuryProtocolsModule::StartupModule()
{
	UE_LOG(LogMercuryProtocols, Warning, TEXT("MercuryProtocols: Log Started"));
}

void FMercuryProtocolsModule::ShutdownModule()
{
	UE_LOG(LogMercuryProtocols, Warning, TEXT("MercuryProtocols: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryProtocolsModule, MercuryProtocols);
