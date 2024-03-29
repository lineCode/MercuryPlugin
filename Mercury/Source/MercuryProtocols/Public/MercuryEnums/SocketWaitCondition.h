﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryProtocols.h"
#include "SocketTypes.h"
#include "UObject/ObjectMacros.h"


/**
 * Mercury implementation of ESocketWaitConditions to allow Blueprints integration
 *
 * @see ESocketWaitConditions
 */
UENUM(BlueprintType, meta = (Keywords = "Socket Object Wait Condition For Read Or Write"))
enum class EMercurySocketWaitCondition : uint8
{
	WaitForRead UMETA(DisplayName = "Wait For Read"),
	WaitForWrite UMETA(DisplayName = "Wait For Write"),
	WaitForReadOrWrite UMETA(DisplayName = "Wait For Read Or Write")
};

namespace MercuryEnums::SocketWait
{
	/** Converts UE enum values to the equivalent Mercury ones. */
	constexpr EMercurySocketWaitCondition Convert(const ESocketWaitConditions::Type& WaitCondition)
	{
		switch (WaitCondition)
		{
		case ESocketWaitConditions::WaitForRead:
			return EMercurySocketWaitCondition::WaitForRead;

		case ESocketWaitConditions::WaitForWrite:
			return EMercurySocketWaitCondition::WaitForWrite;

		case ESocketWaitConditions::WaitForReadOrWrite:
			return EMercurySocketWaitCondition::WaitForReadOrWrite;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown wait condition: %d"), WaitCondition);
			return EMercurySocketWaitCondition::WaitForRead;
		}
	}

	/** Converts Mercury enum values to the equivalent UE ones. */
	constexpr ESocketWaitConditions::Type Convert(const EMercurySocketWaitCondition& WaitCondition)
	{
		switch (WaitCondition)
		{
		case EMercurySocketWaitCondition::WaitForRead:
			return ESocketWaitConditions::WaitForRead;

		case EMercurySocketWaitCondition::WaitForWrite:
			return ESocketWaitConditions::WaitForWrite;

		case EMercurySocketWaitCondition::WaitForReadOrWrite:
			return ESocketWaitConditions::WaitForReadOrWrite;

		default:
			UE_LOG(LogMercuryProtocols, Error, TEXT("Unknown wait condition: %d"), WaitCondition);
			return ESocketWaitConditions::WaitForRead;
		}
	}
}
