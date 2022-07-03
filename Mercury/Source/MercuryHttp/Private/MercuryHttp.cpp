// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttp.h"

#include "HttpModule.h"

FHttpModule* const FMercuryHttpModule::HttpModule = &FHttpModule::Get();


DEFINE_LOG_CATEGORY(LogMercuryHttp);

#define LOCTEXT_NAMESPACE "FMercuryHttpModule"

void FMercuryHttpModule::StartupModule()
{
	check(HttpModule);
	UE_LOG(LogMercuryHttp, Warning, TEXT("MercuryHttp: Log Started"));
}

void FMercuryHttpModule::ShutdownModule()
{
	UE_LOG(LogMercuryHttp, Warning, TEXT("MercuryHttp: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryHttpModule, MercuryHttp);
