// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryCore, All, All);

class FMercuryCoreModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
