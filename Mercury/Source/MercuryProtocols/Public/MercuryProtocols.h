// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"
#include "SocketSubsystem.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryProtocols, All, All);

/** Mercury module which contains TCP and UDP features */
class FMercuryProtocolsModule : public IModuleInterface
{
	/** Used to create sockets */
	static ISocketSubsystem* SocketSubsystem;

	/** Logs that MercuryProtocols was loaded as a warning. */
	virtual void StartupModule() override;
	
	/** Logs that MercuryProtocols was unloaded as a warning. */
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static ISocketSubsystem* const& GetSocketSubsystem() { return SocketSubsystem; }
};
