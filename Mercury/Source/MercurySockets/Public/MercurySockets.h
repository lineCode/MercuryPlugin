// Copyright (c) 2022 Kaya Adrian

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(LogMercurySockets, All, All);

class FMercurySocketsModule : public IModuleInterface
{
	static ISocketSubsystem* const SocketSubsystem;
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	FORCEINLINE static ISocketSubsystem* const& GetSocketSubsystem() { return SocketSubsystem; }
};