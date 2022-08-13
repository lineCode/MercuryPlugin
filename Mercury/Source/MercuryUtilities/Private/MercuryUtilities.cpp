// Copyright (c) 2022 Kaya Adrian

#include "MercuryUtilities.h"

#include "Modules/ModuleManager.h"


DEFINE_LOG_CATEGORY(LogMercuryUtilities);

#define LOCTEXT_NAMESPACE "FMercuryUtilitiesModule"

void FMercuryUtilitiesModule::StartupModule()
{
	UE_LOG(LogMercuryUtilities, Warning, TEXT("MercuryUtilities: Log Started"));
}

void FMercuryUtilitiesModule::ShutdownModule()
{
	UE_LOG(LogMercuryUtilities, Warning, TEXT("MercuryUtilities: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryUtilitiesModule, MercuryUtilities);
