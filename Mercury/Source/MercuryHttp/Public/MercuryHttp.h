// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"
#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryHttp, All, All);

/** Mercury module that allows HTTP communication */
class FMercuryHttpModule : public IModuleInterface
{
	/** Used to create requests */
	static FHttpModule* HttpModule;

protected:
	/** Logs that MercuryHttp was loaded as a warning. */
	virtual void StartupModule() override;

	/** Logs that MercuryHttp was unloaded as a warning. */
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static FHttpModule* const& GetHttpModule() { return HttpModule; }
};
