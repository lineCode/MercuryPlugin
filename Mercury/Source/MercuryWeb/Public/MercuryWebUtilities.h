// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"
#include "MercuryWebTypes.h"

#include "MercuryWebUtilities.generated.h"


UCLASS(Abstract)
class MERCURYWEB_API UMercuryWebUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static TObjectPtr<FHttpModule> HttpModule;

public:
	explicit UMercuryWebUtilities(const FObjectInitializer& ObjectInitializer);

private:
	static FHttpRequestPtr CreateRequest();
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
	
	static void OnHttpProcessRequestComplete(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully,
		FMercuryHttpProcessRequestCompleteDelegate MercuryHttpProcessRequestComplete
	);

	static void OnHttpRequestProgress(
		FHttpRequestPtr Request,
		int32 BytesSent,
		int32 BytesReceived,
		FMercuryHttpRequestProgressDelegate MercuryHttpRequestProgress
	);

	static void OnHttpRequestWillRetry(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		float SecondsToRetry,
		FMercuryHttpRequestWillRetryDelegate MercuryHttpRequestWillRetry
	);

	static void OnHttpHeaderReceived(
		FHttpRequestPtr Request,
		const FString& HeaderName,
		const FString& NewHeaderValue,
		FMercuryHttpHeaderReceivedDelegate MercuryHttpHeaderReceived
	);

public:
	UFUNCTION(BlueprintCallable, Category = "Mercury|HTTP", DisplayName = "Request Data (Payload)", meta = (
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
		const TArray<uint8>& ContentPayload,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);
	
	UFUNCTION(BlueprintCallable, Category = "Mercury|HTTP", DisplayName = "Request Data (String Content)", meta = (
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

	UFUNCTION(BlueprintCallable, Category = "Mercury|HTTP", DisplayName = "Request Data (Streamed File)", meta = (
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
};
