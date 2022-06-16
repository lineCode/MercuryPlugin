// Copyright (c) 2022 Kaya Adrian

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryJson, All, All);

class FMercuryJsonModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
