// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercurySocket.h"


UENUM(BlueprintType, meta = (Keywords = "Socket Object Shutdown Mode Read Write"))
enum class EMercurySocketShutdownMode : uint8
{
	Read UMETA(DisplayName = "Read"),
	Write UMETA(DisplayName = "Write"),
	ReadWrite UMETA(DisplayName = "Read/Write")
};

namespace MercuryEnums::SocketShutdown
{
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
			UE_LOG(LogMercurySocket, Error, TEXT("Unknown shutdown mode: %d"), ShutdownMode);
			return EMercurySocketShutdownMode::Read;
		}
	}

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
			UE_LOG(LogMercurySocket, Error, TEXT("Unknown shutdown mode: %d"), ShutdownMode);
			return ESocketShutdownMode::Read;
		}
	}
}
