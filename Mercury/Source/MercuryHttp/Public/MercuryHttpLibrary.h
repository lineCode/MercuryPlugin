// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MercuryObjects/HttpRequest.h"
#include "MercuryObjects/HttpResponse.h"

#include "MercuryHttpLibrary.generated.h"


/** Library for creating Mercury HTTP structures and requesting data */
UCLASS(Abstract, DisplayName = "Mercury HTTP Blueprint Function Library")
class MERCURYHTTP_API UMercuryHttpLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Creates a HTTP Request with a default resource.
	 *
	 * @return The resulting UMercuryHttpRequest object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create HTTP Request", Category = "Mercury|HTTP", meta = (
		Keywords = "Create HTTP Request"
	))
	static UMercuryHttpRequest* CreateHttpRequest();

	/**
	 * Creates a HTTP Request using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryHttpRequest object or NULL if failed
	 */
	static UMercuryHttpRequest* CreateHttpRequest(IHttpRequest* const& Resource);

	/**
	 * Creates a HTTP Request using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryHttpRequest object or NULL if failed
	 */
	static UMercuryHttpRequest* CreateHttpRequest(const TSharedPtr<IHttpRequest>& Resource);

	/**
	 * Creates a HTTP Response with a default resource.
	 *
	 * @return The resulting UMercuryHttpResponse object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create HTTP Response", Category = "Mercury|HTTP", meta = (
		Keywords = "Create HTTP Response"
	))
	static UMercuryHttpResponse* CreateHttpResponse();

	/**
	 * Creates a HTTP Response using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryHttpResponse object or NULL if failed
	 */
	static UMercuryHttpResponse* CreateHttpResponse(IHttpResponse* const& Resource);

	/**
	 * Creates a HTTP Response using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryHttpResponse object or NULL if failed
	 */
	static UMercuryHttpResponse* CreateHttpResponse(const TSharedPtr<IHttpResponse>& Resource);

	/**
	 * Processes an HTTP request containing a content payload.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param ContentPayload Data to attach to the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 */
	static UPARAM(DisplayName = "Success") bool
	RequestDataWithPayload(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TArray<uint8>& ContentPayload = TArray<uint8>(),
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

	/**
	 * Processes an HTTP request containing a string.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param Content String to attach to the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 */
	static UPARAM(DisplayName = "Success") bool
	RequestDataWithStringContent(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

	/**
	 * Processes an HTTP request containing stream data.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param Stream Archive data to attach to the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 */
	static UPARAM(DisplayName = "Success") bool
	RequestDataFromStream(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

	/**
	 * Processes an HTTP request containing a file's data.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param Filename Name of file to get data from for the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 */
	static UPARAM(DisplayName = "Success") bool
	RequestDataWithStreamedFile(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Filename,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete = nullptr,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress = nullptr,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry = nullptr,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived = nullptr
	);

protected:
	/**
	 * Processes an HTTP request in a generic way.
	 *
	 * @param Request Object with which to process
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 *
	 * @note This is a helper function for the other similar methods to avoid code duplication.
	 */
	static UPARAM(DisplayName = "Success") bool
	RequestData(
		UMercuryHttpRequest* const& Request,
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
	);

	/**
	 * Processes an HTTP request containing a content payload.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param ContentPayload Data to attach to the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Payload)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ContentPayload, ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON Byte Array Payload"
	))
	static UPARAM(DisplayName = "Success") bool
	K2_RequestDataWithPayload(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const TArray<uint8>& ContentPayload,
		const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
	);

	/**
	 * Processes an HTTP request containing a string.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param Content String to attach to the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (String Content)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON String Content"
	))
	static UPARAM(DisplayName = "Success") bool
	K2_RequestDataWithStringContent(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
		const FMercuryHttpRequestProgressDelegate& RequestProgress,
		const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
		const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
	);

	/**
	 * Processes an HTTP request containing a file's data.
	 *
	 * @param URL Request URL
	 * @param Verb Request type
	 * @param Headers Request header names and values
	 * @param Filename Name of file to get data from for the request
	 * @param ProcessRequestComplete Function to call when the process is complete
	 * @param RequestProgress Function to call while the process is progressing
	 * @param RequestWillRetry Function to call when the process will retry
	 * @param HeaderReceived Function to call when the process receives headers
	 * @return Did the request process successfully start?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Request Data (Streamed File)", Category = "Mercury|HTTP", meta = (
		AdvancedDisplay = "4",
		AutoCreateRefTerm = "ProcessRequestComplete, RequestProgress, RequestWillRetry, HeaderReceived",
		Keywords = "Request Data HTTP Response URL JSON Streamed File"
	))
	static UPARAM(DisplayName = "Success") bool
	K2_RequestDataWithStreamedFile(
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
