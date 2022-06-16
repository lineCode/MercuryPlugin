// Copyright (c) 2022 Kaya Adrian

#include "MercuryJson.h"


DEFINE_LOG_CATEGORY(LogMercuryJson);

#define LOCTEXT_NAMESPACE "FMercuryJsonModule"

void FMercuryJsonModule::StartupModule()
{
	UE_LOG(LogMercuryJson, Warning, TEXT("MercuryJson: Log Started"));
}

void FMercuryJsonModule::ShutdownModule()
{
	UE_LOG(LogMercuryJson, Warning, TEXT("MercuryJson: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryJsonModule, MercuryJson);
