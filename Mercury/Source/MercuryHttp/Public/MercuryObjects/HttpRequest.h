// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/HttpHeaderReceived.h"
#include "MercuryDelegates/HttpProcessRequestComplete.h"
#include "MercuryDelegates/HttpRequestProgress.h"
#include "MercuryDelegates/HttpRequestWillRetry.h"
#include "MercuryEnums/HttpRequestStatus.h"
#include "MercuryResourceOwner.h"

#include "HttpRequest.generated.h"


/** Object encapsulating an HTTP request */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Request")
class MERCURYHTTP_API UMercuryHttpRequest : public UObject, public TResourceOwner<IHttpRequest>
{
	GENERATED_BODY()
	
	/** Invoked when the request process is complete */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Process Request Complete Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestCompleteDelegate;

	/** Invoked while the request process is progressing */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Progress Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgressDelegate;

	/** Invoked when the request process will retry */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Will Retry Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetryDelegate;

	/** Invoked when the request process receives headers */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Header Received Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpHeaderReceivedDelegate OnMercuryHttpHeaderReceivedDelegate;

public:
	/**
	 * Creates an HTTP request resource.
	 *
	 * @return The IHttpRequest object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateHttpRequest
	 */
	virtual TSharedPtr<IHttpRequest> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "HTTP|Request", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the URL at which the request is sent. */
	UFUNCTION(BlueprintPure, DisplayName = "Get URL", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "URL",
		Keywords = "Get URL Link Host Server"
	))
	virtual FString GetURL() const;

	/**
	 * Obtains the value of a URL parameter.
	 *
	 * @param ParameterName Name of the URL parameter
	 * @return The value of the selected parameter
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get URL Parameter", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "URL Parameter",
		Keywords = "Get URL Parameter Argument Link Server Name"
	))
	virtual FString GetURLParameter(const FString& ParameterName) const;

	/**
	 * Obtains the value of a header.
	 *
	 * @param HeaderName Name of the header
	 * @return The value of the selected header
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Header", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Header",
		Keywords = "Get Header Name"
	))
	virtual FString GetHeader(const FString& HeaderName) const;

	/** Obtains an array of all request headers with their names and values. */
	UFUNCTION(BlueprintPure, DisplayName = "Get All Headers", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "All Headers",
		Keywords = "Get All Headers Names"
	))
	virtual TArray<FString> GetAllHeaders() const;

	/** Obtains the Content-Type header value. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content Type", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Content Type",
		Keywords = "Get Content Type"
	))
	virtual FString GetContentType() const;

	/** Obtains the Content-Length header value. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content Length", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Content Length",
		Keywords = "Get Content Length"
	))
	virtual int32 GetContentLength() const;

	/** Obtains the content payload request. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Content",
		Keywords = "Get Content Payload"
	))
	virtual TArray<uint8> GetContent() const;

	/** Obtains the request verb, most commonly GET and POST. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Verb", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Verb",
		Keywords = "Get Verb"
	))
	virtual FString GetVerb() const;

	/**
	 * Sets the HTTP request verb.
	 *
	 * @param Verb New request verb
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Verb", Category = "HTTP|Request", meta = (
		Keywords = "Set Verb"
	))
	virtual UMercuryHttpRequest* SetVerb(const FString& Verb);

	/**
	 * Sets the HTTP request URL.
	 *
	 * @param URL New request URL
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set URL", Category = "HTTP|Request", meta = (
		Keywords = "Set URL Link Host Server"
	))
	virtual UMercuryHttpRequest* SetURL(const FString& URL);

	/**
	 * Sets the HTTP request content payload.
	 *
	 * @param ContentPayload Data to attach to the request
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Content", Category = "HTTP|Request", meta = (
		Keywords = "Set Content Payload"
	))
	virtual UMercuryHttpRequest* SetContent(const TArray<uint8>& ContentPayload);

	/**
	 * Sets the HTTP request content payload.
	 *
	 * @param ContentPayload Data to attach to the request
	 * @return The same object for method chaining
	 */
	virtual UMercuryHttpRequest* SetContent(TArray<uint8>&& ContentPayload);

	/**
	 * Sets the HTTP request content in string format.
	 *
	 * @param ContentString String to attach to the request
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As String", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As String"
	))
	virtual UMercuryHttpRequest* SetContentAsString(const FString& ContentString);

	/**
	 * Sets the HTTP request content using a file's data.
	 *
	 * @param Filename Name of file to get data from for the request
	 * @param bRequestStreamed Could the file be used to stream the request?
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As Streamed File", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As Streamed File"
	))
	virtual UMercuryHttpRequest* SetContentAsStreamedFile(const FString& Filename, bool& bRequestStreamed);

	/**
	 * Sets the HTTP request content using a file's data.
	 *
	 * @param Filename Name of file to get data from for the request
	 * @return Could the file be used to stream the request?
	 */
	virtual bool SetContentAsStreamedFile(const FString& Filename);

	/**
	 * Sets the HTTP request content using a stream.
	 *
	 * @param Stream Archive to get data from for the request
	 * @param bRequestStreamed Could the archive be used to stream the request?
	 * @return The same object for method chaining
	 */
	virtual UMercuryHttpRequest* SetContentFromStream(
		const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
		bool& bRequestStreamed
	);

	/**
	 * Sets the HTTP request content using a stream.
	 *
	 * @param Stream Archive to get data from for the request
	 * @return Could the archive be used to stream the request?
	 */
	virtual bool SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);

	/**
	 * Sets an HTTP request header.
	 *
	 * @param HeaderName Name of header to add or modify
	 * @param HeaderValue New value for the header
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Header", Category = "HTTP|Request", meta = (
		Keywords = "Set Header Name Value"
	))
	virtual UMercuryHttpRequest* SetHeader(const FString& HeaderName, const FString& HeaderValue);

	/**
	 * Sets all HTTP request headers.
	 *
	 * @param Headers Dictionary of header names and values to use
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Headers", Category = "HTTP|Request", meta = (
		Keywords = "Set Headers Names Values Map"
	))
	virtual UMercuryHttpRequest* SetHeaders(const TMap<FString, FString>& Headers);

	/**
	 * Add a new value to an HTTP request header.
	 *
	 * @param HeaderName Name of header to add or modify
	 * @param HeaderValue New value to be added to the header
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Append To Header", Category = "HTTP|Request", meta = (
		Keywords = "Append Add Insert To In Header Name Value"
	))
	virtual UMercuryHttpRequest* AppendToHeader(const FString& HeaderName, const FString& HeaderValue);

	/**
	 * Sets the amount of time the request has to complete.
	 *
	 * @param InTimeoutSeconds Amount of seconds before timing out
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Set Timeout Limit"
	))
	virtual UMercuryHttpRequest* SetTimeout(float InTimeoutSeconds);

	/**
	 * Clears the request timeout.
	 *
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Clear Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Clear Timeout Limit Reset"
	))
	virtual UMercuryHttpRequest* ClearTimeout();

	/**
	 * Begins processing the request.
	 *
	 * @param bSuccessfullyStarted Was the request successfully started?
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Process Request", Category = "HTTP|Request", meta = (
		Keywords = "Process Request Execute Fetch"
	))
	virtual UMercuryHttpRequest* ProcessRequest(bool& bSuccessfullyStarted);

	/**
	 * Begins processing the request.
	 *
	 * @return Was the request successfully started?
	 */
	virtual bool ProcessRequest() const;

	/**
	 * Stops processing the request early.
	 *
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Cancel Request", Category = "HTTP|Request", meta = (
		Keywords = "Cancel Request Stop Halt Interrupt"
	))
	virtual UMercuryHttpRequest* CancelRequest();

	/** Obtains the associated HTTP response of this request. */
	UFUNCTION(BlueprintPure, DisplayName = "Get HTTP Response", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "HTTP Response",
		Keywords = "Get HTTP Response"
	))
	virtual UMercuryHttpResponse* GetResponse() const;

	/** Obtains the current status of the request as it's being processed. */
	UFUNCTION(BlueprintPure, DisplayName = "Get HTTP Status", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "HTTP Status",
		Keywords = "Get HTTP Status"
	))
	virtual EMercuryHttpRequestStatus GetStatus() const;

	/** Obtains the amount of seconds the request can be processed for before timing out. */
	UFUNCTION(BlueprintPure, DisplayName = "Get HTTP Timeout", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "HTTP Timeout",
		Keywords = "Get HTTP Timeout"
	))
	virtual float GetTimeout() const; 

	/**
	 * Ticks the process.
	 *
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Tick", Category = "HTTP|Request", meta = (
		Keywords = "Tick Update"
	))
	virtual UMercuryHttpRequest* Tick(float DeltaSeconds);

	/** Obtains the amount of time it took to get a response. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Elapsed Time", Category = "HTTP|Request", meta = (
		CompactNodeTitle = "Elapsed Time",
		Keywords = "Get Elapsed Time Count"
	))
	virtual float GetElapsedTime() const;

protected:
	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryHttpProcessRequestCompleteDelegate
	 */
	virtual void BindProcessRequestComplete(
		TSharedPtr<IHttpRequest> Request,
		TSharedPtr<IHttpResponse> Response,
		bool bConnectedSuccessfully
	);

	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryHttpRequestProgressDelegate
	 */
	virtual void BindRequestProgress(
		TSharedPtr<IHttpRequest> Request,
		int32 BytesSent,
		int32 BytesReceived
	);

	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryHttpRequestWillRetryDelegate
	 */
	virtual void BindRequestWillRetry(
		TSharedPtr<IHttpRequest> Request,
		TSharedPtr<IHttpResponse> Response,
		float SecondsToRetry
	);

	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryHttpHeaderReceivedDelegate
	 */
	virtual void BindHeaderReceived(
		TSharedPtr<IHttpRequest> Request,
		const FString& HeaderName,
		const FString& NewHeaderValue
	);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Process Request Complete Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Process Request Complete Delegate Event"
	))
	virtual UMercuryHttpRequest* K2_SetProcessRequestCompleteEvent(
		const FMercuryHttpProcessRequestCompleteDelegate& Event
	);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Progress Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Progress Delegate Event"
	))
	virtual UMercuryHttpRequest* K2_SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Event);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Will Retry Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Will Retry Delegate Event"
	))
	virtual UMercuryHttpRequest* K2_SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Event);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Header Received Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Header Received Delegate Event"
	))
	virtual UMercuryHttpRequest* K2_SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Event);

public:
	FORCEINLINE const FMercuryHttpProcessRequestCompleteDelegate& OnProcessRequestComplete() const
	{
		return OnMercuryHttpProcessRequestCompleteDelegate;
	}
	FORCEINLINE FMercuryHttpProcessRequestCompleteDelegate& OnProcessRequestComplete()
	{
		return OnMercuryHttpProcessRequestCompleteDelegate;
	}

	FORCEINLINE const FMercuryHttpRequestProgressDelegate& OnRequestProgress() const
	{
		return OnMercuryHttpRequestProgressDelegate;
	}
	FORCEINLINE FMercuryHttpRequestProgressDelegate& OnRequestProgress()
	{
		return OnMercuryHttpRequestProgressDelegate;
	}

	FORCEINLINE const FMercuryHttpRequestWillRetryDelegate& OnRequestWillRetry() const
	{
		return OnMercuryHttpRequestWillRetryDelegate;
	}
	FORCEINLINE FMercuryHttpRequestWillRetryDelegate& OnRequestWillRetry()
	{
		return OnMercuryHttpRequestWillRetryDelegate;
	}

	FORCEINLINE const FMercuryHttpHeaderReceivedDelegate& OnHeaderReceived() const
	{
		return OnMercuryHttpHeaderReceivedDelegate;
	}
	FORCEINLINE FMercuryHttpHeaderReceivedDelegate& OnHeaderReceived()
	{
		return OnMercuryHttpHeaderReceivedDelegate;
	}
};
