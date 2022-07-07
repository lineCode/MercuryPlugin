// Copyright (c) 2022 Kaya Adrian

#include "MercurySocket.h"

#include "SocketSubsystem.h"

ISocketSubsystem* const FMercurySocketModule::SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


DEFINE_LOG_CATEGORY(LogMercurySocket);

#define LOCTEXT_NAMESPACE "FMercurySocketModule"

void FMercurySocketModule::StartupModule()
{
	UE_LOG(LogMercurySocket, Warning, TEXT("MercurySocket: Log Started"));
}

void FMercurySocketModule::ShutdownModule()
{
	UE_LOG(LogMercurySocket, Warning, TEXT("MercurySocket: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercurySocketModule, MercurySocket);
