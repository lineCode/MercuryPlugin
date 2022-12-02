// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryCore, All, All);

/** Mercury module for creating Gym environments used in reinforcement learning AIs */
class FMercuryCoreModule : public IModuleInterface
{
	/** Logs that MercuryCore was loaded as a warning. */
	virtual void StartupModule() override;

	/** Logs that MercuryCore was unloaded as a warning. */
	virtual void ShutdownModule() override;
};
