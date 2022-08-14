// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"
#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryHttp, All, All);

class FMercuryHttpModule : public IModuleInterface
{
	static FHttpModule* HttpModule;

protected:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static FHttpModule* const& GetHttpModule() { return HttpModule; }
};
