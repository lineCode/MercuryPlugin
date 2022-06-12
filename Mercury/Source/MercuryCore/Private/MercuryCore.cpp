// Copyright (c) 2022 Kaya Adrian

#include "MercuryCore.h"


DEFINE_LOG_CATEGORY(LogMercuryCore);

#define LOCTEXT_NAMESPACE "FMercuryCoreModule"

void FMercuryCoreModule::StartupModule()
{
	UE_LOG(LogMercuryCore, Warning, TEXT("MercuryCore: Log Started"));
}

void FMercuryCoreModule::ShutdownModule()
{
	UE_LOG(LogMercuryCore, Warning, TEXT("MercuryCore: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryCoreModule, MercuryCore);
