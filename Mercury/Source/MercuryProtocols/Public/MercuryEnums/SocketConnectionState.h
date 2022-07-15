// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"


UENUM(BlueprintType, meta = (Keywords = "Socket Object Connection State Connected Error Not"))
enum class EMercurySocketConnectionState : uint8
{
	Connected UMETA(DisplayName = "Connected"),
	ConnectionError UMETA(DisplayName = "Connection Error"),
	NotConnected UMETA(DisplayName = "Not Connected")
};

namespace MercuryEnums::SocketConnection
{
	constexpr ESocketConnectionState Convert(const EMercurySocketConnectionState& ConnectionState)
	{
		switch (ConnectionState)
		{
		case EMercurySocketConnectionState::Connected:
			return SCS_Connected;

		case EMercurySocketConnectionState::ConnectionError:
			return SCS_ConnectionError;

		case EMercurySocketConnectionState::NotConnected:
			return SCS_NotConnected;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown connection state: %d"), ConnectionState);
			return SCS_NotConnected;
		}
	}

	constexpr EMercurySocketConnectionState Convert(const ESocketConnectionState& ConnectionState)
	{
		switch (ConnectionState)
		{
		case SCS_Connected:
			return EMercurySocketConnectionState::Connected;

		case SCS_ConnectionError:
			return EMercurySocketConnectionState::ConnectionError;

		case SCS_NotConnected:
			return EMercurySocketConnectionState::NotConnected;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown connection state: %d"), ConnectionState);
			return EMercurySocketConnectionState::NotConnected;
		}
	}
}
