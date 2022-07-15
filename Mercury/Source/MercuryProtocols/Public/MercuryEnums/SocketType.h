// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"


UENUM(BlueprintType, meta = (Keywords = "Socket Object Type Datagram Streaming Unknown TCP UDP"))
enum class EMercurySocketType : uint8
{
	Datagram UMETA(DisplayName = "Datagram"),
	Streaming UMETA(DisplayName = "Streaming"),
	Unknown UMETA(DisplayName = "Unknown")
};

namespace MercuryEnums::SocketType
{
	constexpr ESocketType Convert(const EMercurySocketType& SocketType)
	{
		switch (SocketType)
		{
		case EMercurySocketType::Datagram:
			return SOCKTYPE_Datagram;

		case EMercurySocketType::Streaming:
			return SOCKTYPE_Streaming;

		case EMercurySocketType::Unknown:
			return SOCKTYPE_Unknown;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown socket type: %d"), SocketType);
			return SOCKTYPE_Unknown;
		}
	}

	constexpr EMercurySocketType Convert(const ESocketType& SocketType)
	{
		switch (SocketType)
		{
		case SOCKTYPE_Datagram:
			return EMercurySocketType::Datagram;

		case SOCKTYPE_Streaming:
			return EMercurySocketType::Streaming;

		case SOCKTYPE_Unknown:
			return EMercurySocketType::Unknown;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown socket type: %d"), SocketType);
			return EMercurySocketType::Unknown;
		}
	}
}
