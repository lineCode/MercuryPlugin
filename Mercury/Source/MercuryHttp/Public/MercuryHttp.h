// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryHttp, All, All);

class FMercuryHttpModule : public IModuleInterface
{
	static FHttpModule* const HttpModule;

protected:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	static FHttpModule* const& GetHttpModule() { return HttpModule; }
};
