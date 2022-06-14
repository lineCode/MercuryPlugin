// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryWebTypes.generated.h"


class UMercuryHttpRequest;
class UMercuryHttpResponse;

UENUM(BlueprintType, meta = (
	Keywords = "HTTP Request Status Not Started Processing Failed Connection Error Succeeded Unknown"
))
enum class EMercuryHttpRequestStatus : uint8
{
	NotStarted UMETA(DisplayName = "Not Started"),
	Processing UMETA(DisplayName = "Processing"),
	Failed UMETA(DisplayName = "Failed"),
	Failed_ConnectionError UMETA(DisplayName = "Connection Error"),
	Succeeded UMETA(DisplayName = "Succeeded"),
	Unknown UMETA(DisplayName = "Unknown")
};

UDELEGATE(BlueprintCallable, DisplayName = "Process Request Complete Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpProcessRequestCompleteDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	bool, bConnectedSuccessfully
);

UDELEGATE(BlueprintCallable, DisplayName = "Request Progress Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestProgressDelegate,
	UMercuryHttpRequest* const&, Request,
	const int32&, BytesSent,
	const int32&, BytesReceived
);

UDELEGATE(BlueprintCallable, DisplayName = "Request Will Retry Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestWillRetryDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	const float&, SecondsToRetry
);
	
UDELEGATE(BlueprintCallable, DisplayName = "Header Received Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpHeaderReceivedDelegate,
	UMercuryHttpRequest* const&, Request,
	const FString&, HeaderName,
	const FString&, NewHeaderValue
);
