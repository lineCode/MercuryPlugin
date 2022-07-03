// Copyright (c) 2022 Kaya Adrian

#include "MercuryWeb.h"

#include "SocketSubsystem.h"

ISocketSubsystem* const FMercuryWebModule::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


DEFINE_LOG_CATEGORY(LogMercuryWeb);

#define LOCTEXT_NAMESPACE "FMercuryWebModule"

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
