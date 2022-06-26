// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttpTypes.h"

#include "MercuryHttpLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury HTTP Blueprint Function Library")
class MERCURYHTTP_API UMercuryHttpLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void RequestDataWithPayload(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TArray<uint8>& ContentPayload = TArray<uint8>(),
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);
	
	static void RequestDataWithStringContent(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

	static void RequestDataFromStream(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);
	
	static void RequestDataWithStreamedFile(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Filename,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

private:
	static void RequestData(
		UMercuryHttpRequest* const Request,
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Payload)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ContentPayload, ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON Byte Array Payload"
	))
	static void K2_RequestDataWithPayload(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TArray<uint8>& ContentPayload,
		const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (String Content)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON String Content"
	))
	static void K2_RequestDataWithStringContent(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Streamed File)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON Streamed File"
	))
	static void K2_RequestDataWithStreamedFile(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Filename,
		const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
	);
};
