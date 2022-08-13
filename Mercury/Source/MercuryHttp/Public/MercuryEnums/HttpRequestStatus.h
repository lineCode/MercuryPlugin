// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttp.h"
#include "UObject/ObjectMacros.h"


UENUM(BlueprintType, meta = (
	Keywords = "HTTP Request Status Not Started Processing Failed Connection Error Succeeded Unknown"
))
enum class EMercuryHttpRequestStatus : uint8
{
	NotStarted UMETA(DisplayName = "Not Started"),
	Processing UMETA(DisplayName = "Processing"),
	Failed UMETA(DisplayName = "Failed"),
	ConnectionError UMETA(DisplayName = "Connection Error"),
	Succeeded UMETA(DisplayName = "Succeeded")
};

namespace MercuryEnums::HttpRequest
{
	constexpr EMercuryHttpRequestStatus Convert(const EHttpRequestStatus::Type& RequestStatus)
	{
		switch (RequestStatus)
		{
		case EHttpRequestStatus::NotStarted:
			return EMercuryHttpRequestStatus::NotStarted;

		case EHttpRequestStatus::Processing:
			return EMercuryHttpRequestStatus::Processing;

		case EHttpRequestStatus::Failed:
			return EMercuryHttpRequestStatus::Failed;

		case EHttpRequestStatus::Failed_ConnectionError:
			return EMercuryHttpRequestStatus::ConnectionError;

		case EHttpRequestStatus::Succeeded:
			return EMercuryHttpRequestStatus::Succeeded;

		default:
			UE_LOG(LogMercuryHttp, Error, TEXT("Unknown request status: %d"), RequestStatus);
			return EMercuryHttpRequestStatus::ConnectionError;
		}
	}

	constexpr EHttpRequestStatus::Type Convert(const EMercuryHttpRequestStatus& RequestStatus)
	{
		switch (RequestStatus)
		{
		case EMercuryHttpRequestStatus::NotStarted:
			return EHttpRequestStatus::NotStarted;

		case EMercuryHttpRequestStatus::Processing:
			return EHttpRequestStatus::Processing;

		case EMercuryHttpRequestStatus::Failed:
			return EHttpRequestStatus::Failed;

		case EMercuryHttpRequestStatus::ConnectionError:
			return EHttpRequestStatus::Failed_ConnectionError;

		case EMercuryHttpRequestStatus::Succeeded:
			return EHttpRequestStatus::Succeeded;

		default:
			UE_LOG(LogMercuryHttp, Error, TEXT("Unknown request status: %d"), RequestStatus);
			return EHttpRequestStatus::Failed_ConnectionError;
		}
	}
}
