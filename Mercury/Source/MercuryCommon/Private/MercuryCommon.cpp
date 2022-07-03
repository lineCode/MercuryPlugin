// Copyright (c) 2022 Kaya Adrian

#include "MercuryCommon.h"


DEFINE_LOG_CATEGORY(LogMercuryCommon);

#define LOCTEXT_NAMESPACE "FMercuryCommonModule"

void FMercuryCommonModule::StartupModule()
{
	UE_LOG(LogMercuryCommon, Warning, TEXT("MercuryCommon: Log Started"));
}

void FMercuryCommonModule::ShutdownModule()
{
	UE_LOG(LogMercuryCommon, Warning, TEXT("MercuryCommon: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryCommonModule, MercuryCommon);
