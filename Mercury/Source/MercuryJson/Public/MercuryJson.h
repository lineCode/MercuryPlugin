// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryJson, All, All);

/** Mercury module that exposes JSON features to Blueprints */
class FMercuryJsonModule : public IModuleInterface
{
	/** Logs that MercuryJson was loaded as a warning. */
	virtual void StartupModule() override;

	/** Logs that MercuryJson was unloaded as a warning. */
	virtual void ShutdownModule() override;
};
