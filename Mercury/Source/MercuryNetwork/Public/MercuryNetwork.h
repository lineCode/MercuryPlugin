// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "SocketSubsystem.h"


DECLARE_LOG_CATEGORY_EXTERN(LogMercuryNetwork, All, All);

class FMercuryNetworkModule : public IModuleInterface
{
	static ISocketSubsystem* const SocketSubsystem;
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static ISocketSubsystem* const& GetSocketSubsystem() { return SocketSubsystem; }
};
