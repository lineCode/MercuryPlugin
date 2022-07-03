// Copyright (c) 2022 Kaya Adrian

#include "MercurySockets.h"

#include "SocketSubsystem.h"

ISocketSubsystem* const FMercurySocketsModule::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


DEFINE_LOG_CATEGORY(LogMercurySockets);

#define LOCTEXT_NAMESPACE "FMercurySocketsModule"

void FMercurySocketsModule::StartupModule()
{
	UE_LOG(LogMercurySockets, Warning, TEXT("MercurySockets: Log Started"));
}

void FMercurySocketsModule::ShutdownModule()
{
	UE_LOG(LogMercurySockets, Warning, TEXT("MercurySockets: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercurySocketsModule, MercurySockets);
