// Copyright (c) 2022 Kaya Adrian

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(LogMercury, All, All);

class FMercuryModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
