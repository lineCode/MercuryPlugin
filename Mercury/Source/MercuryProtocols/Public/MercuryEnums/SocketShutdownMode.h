// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"
#include "SocketTypes.h"
#include "UObject/ObjectMacros.h"


/**
 * Mercury implementation of ESocketShutdownMode to allow Blueprints integration
 *
 * @see ESocketShutdownMode
 */
UENUM(BlueprintType, meta = (Keywords = "Socket Object Shutdown Mode Read Write"))
enum class EMercurySocketShutdownMode : uint8
{
	Read UMETA(DisplayName = "Read"),
	Write UMETA(DisplayName = "Write"),
	ReadWrite UMETA(DisplayName = "Read/Write")
};

namespace MercuryEnums::SocketShutdown
{
	/** Converts UE enum values to the equivalent Mercury ones. */
	constexpr EMercurySocketShutdownMode Convert(const ESocketShutdownMode& ShutdownMode)
	{
		switch (ShutdownMode)
		{
		case ESocketShutdownMode::Read:
			return EMercurySocketShutdownMode::Read;

		case ESocketShutdownMode::Write:
			return EMercurySocketShutdownMode::Write;

		case ESocketShutdownMode::ReadWrite:
			return EMercurySocketShutdownMode::ReadWrite;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown shutdown mode: %d"), ShutdownMode);
			return EMercurySocketShutdownMode::Read;
		}
	}

	/** Converts Mercury enum values to the equivalent UE ones. */
	constexpr ESocketShutdownMode Convert(const EMercurySocketShutdownMode& ShutdownMode)
	{
		switch (ShutdownMode)
		{
		case EMercurySocketShutdownMode::Read:
			return ESocketShutdownMode::Read;

		case EMercurySocketShutdownMode::Write:
			return ESocketShutdownMode::Write;

		case EMercurySocketShutdownMode::ReadWrite:
			return ESocketShutdownMode::ReadWrite;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown shutdown mode: %d"), ShutdownMode);
			return ESocketShutdownMode::Read;
		}
	}
}
