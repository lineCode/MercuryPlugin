// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryUtilities, All, All);

/** Mercury module for utilities used throughout the plugin */
class FMercuryUtilitiesModule : public IModuleInterface
{
	/** Logs that MercuryUtilities was loaded as a warning. */
	virtual void StartupModule() override;
	
	/** Logs that MercuryUtilities was unloaded as a warning. */
	virtual void ShutdownModule() override;
};
