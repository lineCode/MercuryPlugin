// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"
#include "SocketSubsystem.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryProtocols, All, All);

class FMercuryProtocolsModule : public IModuleInterface
{
	static ISocketSubsystem* SocketSubsystem;
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static ISocketSubsystem* const& GetSocketSubsystem() { return SocketSubsystem; }
};
