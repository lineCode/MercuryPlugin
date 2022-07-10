// Copyright (c) 2022 Kaya Adrian

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryUtilities, All, All);

class FMercuryUtilitiesModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
