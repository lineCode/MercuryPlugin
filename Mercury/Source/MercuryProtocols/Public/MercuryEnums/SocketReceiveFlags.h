// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"
#include "SocketTypes.h"
#include "UObject/ObjectMacros.h"


/**
 * Mercury implementation of ESocketReceiveFlags to allow Blueprints integration
 *
 * @see ESocketReceiveFlags
 */
UENUM(BlueprintType, meta = (Keywords = "Socket Object Receive Flags None Peek Wait All"))
enum class EMercurySocketReceiveFlags : uint8
{
	None UMETA(DisplayName = "None"),
	Peek UMETA(DisplayName = "Peek"),
	WaitAll UMETA(DisplayName = "Wait All")
};

namespace MercuryEnums::SocketReceive
{
	/** Converts UE enum values to the equivalent Mercury ones. */
	constexpr EMercurySocketReceiveFlags Convert(const ESocketReceiveFlags::Type& ReceiveFlags)
	{
		switch (ReceiveFlags)
		{
		case ESocketReceiveFlags::None:
			return EMercurySocketReceiveFlags::None;

		case ESocketReceiveFlags::Peek:
			return EMercurySocketReceiveFlags::Peek;

		case ESocketReceiveFlags::WaitAll:
			return EMercurySocketReceiveFlags::WaitAll;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown receive flags: %d"), ReceiveFlags);
			return EMercurySocketReceiveFlags::None;
		}
	}

	/** Converts Mercury enum values to the equivalent UE ones. */
	constexpr ESocketReceiveFlags::Type Convert(const EMercurySocketReceiveFlags& ReceiveFlags)
	{
		switch (ReceiveFlags)
		{
		case EMercurySocketReceiveFlags::None:
			return ESocketReceiveFlags::None;

		case EMercurySocketReceiveFlags::Peek:
			return ESocketReceiveFlags::Peek;

		case EMercurySocketReceiveFlags::WaitAll:
			return ESocketReceiveFlags::WaitAll;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown receive flags: %d"), ReceiveFlags);
			return ESocketReceiveFlags::None;
		}
	}
}
