// Copyright (c) 2022 Kaya Adrian

#include "MercuryWeb.h"

#include "SocketSubsystem.h"


DEFINE_LOG_CATEGORY(LogMercuryWeb);

#define LOCTEXT_NAMESPACE "FMercuryWebModule"

ISocketSubsystem* const FMercuryWebModule::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

void FMercuryWebModule::StartupModule()
{
	UE_LOG(LogMercuryWeb, Warning, TEXT("MercuryWeb: Log Started"));
}

void FMercuryWebModule::ShutdownModule()
{
	UE_LOG(LogMercuryWeb, Warning, TEXT("MercuryWeb: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryWebModule, MercuryWeb);
