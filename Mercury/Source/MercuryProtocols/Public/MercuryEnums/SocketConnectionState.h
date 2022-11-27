// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"
#include "SocketTypes.h"
#include "UObject/ObjectMacros.h"


/**
 * Mercury implementation of ESocketConnectionState to allow Blueprints integration
 *
 * @see ESocketConnectionState
 */
UENUM(BlueprintType, meta = (Keywords = "Socket Object Connection State Connected Error Not"))
enum class EMercurySocketConnectionState : uint8
{
	Connected UMETA(DisplayName = "Connected"),
	ConnectionError UMETA(DisplayName = "Connection Error"),
	NotConnected UMETA(DisplayName = "Not Connected")
};

namespace MercuryEnums::SocketConnection
{
	/** Converts UE enum values to the equivalent Mercury ones. */
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

	/** Converts Mercury enum values to the equivalent UE ones. */
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
}
