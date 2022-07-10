﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercurySocket.h"


UENUM(BlueprintType, meta = (Keywords = "Socket Object Receive Flags None Peek Wait All"))
enum class EMercurySocketReceiveFlags : uint8
{
	None UMETA(DisplayName = "None"),
	Peek UMETA(DisplayName = "Peek"),
	WaitAll UMETA(DisplayName = "Wait All")
};

namespace MercuryEnums::SocketReceive
{
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
			UE_LOG(LogMercurySocket, Error, TEXT("Unknown receive flags: %d"), ReceiveFlags);
			return ESocketReceiveFlags::None;
		}
	}

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
			UE_LOG(LogMercurySocket, Error, TEXT("Unknown receive flags: %d"), ReceiveFlags);
			return EMercurySocketReceiveFlags::None;
		}
	}
}