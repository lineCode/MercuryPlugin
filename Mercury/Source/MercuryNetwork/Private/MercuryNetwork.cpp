// Copyright (c) 2022 Kaya Adrian

#include "MercuryNetwork.h"

#include "Modules/ModuleManager.h"

ISocketSubsystem* FMercuryNetworkModule::SocketSubsystem = nullptr;


DEFINE_LOG_CATEGORY(LogMercuryNetwork);

#define LOCTEXT_NAMESPACE "FMercuryNetworkModule"

void FMercuryNetworkModule::StartupModule()
{
	UE_LOG(LogMercuryNetwork, Warning, TEXT("MercuryNetwork: Log Started"));

	SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	check(SocketSubsystem);
}

void FMercuryNetworkModule::ShutdownModule()
{
	UE_LOG(LogMercuryNetwork, Warning, TEXT("MercuryNetwork: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryNetworkModule, MercuryNetwork);
