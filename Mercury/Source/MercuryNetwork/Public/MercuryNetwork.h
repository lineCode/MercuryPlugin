// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"
#include "SocketSubsystem.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryNetwork, All, All);

/** Mercury module which defines network objects */
class FMercuryNetworkModule : public IModuleInterface
{
	/** Used to create internet address objects */
	static ISocketSubsystem* SocketSubsystem;

	/** Logs that MercuryNetwork was loaded as a warning. */
	virtual void StartupModule() override;

	/** Logs that MercuryNetwork was unloaded as a warning. */
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static ISocketSubsystem* const& GetSocketSubsystem() { return SocketSubsystem; }
};
