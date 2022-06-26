// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttp.h"


DEFINE_LOG_CATEGORY(LogMercuryHttp);

#define LOCTEXT_NAMESPACE "FMercuryHttpModule"

void FMercuryHttpModule::StartupModule()
{
	UE_LOG(LogMercuryHttp, Warning, TEXT("MercuryHttp: Log Started"));
}

void FMercuryHttpModule::ShutdownModule()
{
	UE_LOG(LogMercuryHttp, Warning, TEXT("MercuryHttp: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryHttpModule, MercuryHttp);
