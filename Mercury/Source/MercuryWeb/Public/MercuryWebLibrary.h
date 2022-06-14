// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryWebTypes.h"
#include "Interfaces/IHttpRequest.h"

#include "MercuryWebLibrary.generated.h"

class FHttpModule;


UCLASS(Abstract, DisplayName = "Mercury Web Blueprint Function Library")
class MERCURYWEB_API UMercuryWebLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	static FHttpModule* HttpModule;

public:
	static FHttpRequestPtr CreateHttpRequest();
	
	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Payload)", Category = "Mercury|HTTP", meta = (
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
	
	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (String Content)", Category = "Mercury|HTTP", meta = (
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

	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Streamed File)", Category = "Mercury|HTTP", meta = (
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
		const FHttpRequestPtr& Request,
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
	);

	static void OnMercuryHttpProcessRequestComplete(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully,
		FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestComplete
	);

	static void OnMercuryHttpRequestProgress(
		FHttpRequestPtr Request,
		int32 BytesSent,
		int32 BytesReceived,
		FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgress
	);

	static void OnMercuryHttpRequestWillRetry(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		float SecondsToRetry,
		FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetry
	);

	static void OnMercuryHttpHeaderReceived(
		FHttpRequestPtr Request,
		const FString& HeaderName,
		const FString& NewHeaderValue,
		FMercuryHttpHeaderReceivedDelegate OnMercuryHttpHeaderReceived
	);
};
