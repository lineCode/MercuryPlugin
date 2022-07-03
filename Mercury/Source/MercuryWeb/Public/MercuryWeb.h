// Copyright (c) 2022 Kaya Adrian

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryWeb, All, All);

class FMercuryWebModule : public IModuleInterface
{
	static ISocketSubsystem* const SocketSubsystem;
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
