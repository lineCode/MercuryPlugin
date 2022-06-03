// Copyright (c) 2022 Kaya Adrian

#include "Mercury.h"


DEFINE_LOG_CATEGORY(LogMercury);

#define LOCTEXT_NAMESPACE "FMercuryModule"

void FMercuryModule::StartupModule()
{
	UE_LOG(LogMercury, Warning, TEXT("Mercury: Log Started"));
}

void FMercuryModule::ShutdownModule()
{
	UE_LOG(LogMercury, Warning, TEXT("Mercury: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMercuryModule, Mercury);
