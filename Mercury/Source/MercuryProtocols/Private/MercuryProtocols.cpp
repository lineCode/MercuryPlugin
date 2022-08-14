// Copyright (c) 2022 Kaya Adrian

#include "MercuryProtocols.h"

#include "Modules/ModuleManager.h"

ISocketSubsystem* FMercuryProtocolsModule::SocketSubsystem = nullptr;


DEFINE_LOG_CATEGORY(LogMercuryProtocols);

#define LOCTEXT_NAMESPACE "FMercuryProtocolsModule"

void FMercuryProtocolsModule::StartupModule()
{
	UE_LOG(LogMercuryProtocols, Warning, TEXT("MercuryProtocols: Log Started"));

	SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	check(SocketSubsystem);
}

void FMercuryProtocolsModule::ShutdownModule()
{
	UE_LOG(LogMercuryProtocols, Warning, TEXT("MercuryProtocols: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryProtocolsModule, MercuryProtocols);
