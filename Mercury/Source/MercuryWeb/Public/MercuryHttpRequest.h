// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttpBase.h"
#include "MercuryWebTypes.h"

#include "MercuryHttpRequest.generated.h"

class FHttpModule;


UCLASS(BlueprintType, DisplayName = "Mercury HTTP Request")
class MERCURYWEB_API UMercuryHttpRequest : public UMercuryHttpBase
{
	GENERATED_BODY()

	static FHttpModule* HttpModule;
	FHttpRequestPtr Reference;
	
	UPROPERTY(BlueprintReadOnly, DisplayName = "HTTP Response", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<UMercuryHttpResponse> MercuryHttpResponse;

	UPROPERTY(BlueprintReadWrite, DisplayName = "Process Request Complete Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestCompleteDelegate;
	
	UPROPERTY(BlueprintReadWrite, DisplayName = "Request Progress Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgressDelegate;
	
	UPROPERTY(BlueprintReadWrite, DisplayName = "Request Will Retry Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetryDelegate;
	
	UPROPERTY(BlueprintReadWrite, DisplayName = "Header Received Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpHeaderReceivedDelegate OnMercuryHttpHeaderReceivedDelegate;

public:
	explicit UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer);

	virtual FString GetURL() const override;
	virtual FString GetURLParameter(const FString& ParameterName) const override;
	virtual FString GetHeader(const FString& HeaderName) const override;
	virtual TArray<FString> GetAllHeaders() const override;
	virtual FString GetContentType() const override;
	virtual int32 GetContentLength() const override;
	virtual TArray<uint8> GetContent() const override;
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Verb", Category = "HTTP|Request", meta = (
		Keywords = "Get Verb"
	))
	FString GetVerb() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set Verb", Category = "HTTP|Request", meta = (
		Keywords = "Set Verb"
	))
	UMercuryHttpRequest* SetVerb(const FString& Verb);

	UFUNCTION(BlueprintCallable, DisplayName = "Set URL", Category = "HTTP|Request", meta = (
		Keywords = "Set URL Link Host Server"
	))
	UMercuryHttpRequest* SetURL(const FString& URL);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content", Category = "HTTP|Request", meta = (
		AutoCreateRefTerm = "ContentPayload",
		Keywords = "Set Content Payload"
	))
	UMercuryHttpRequest* SetContent(const TArray<uint8>& ContentPayload);
	UMercuryHttpRequest* SetContent(TArray<uint8>&& ContentPayload);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As String", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As String"
	))
	UMercuryHttpRequest* SetContentAsString(const FString& ContentString);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As Streamed File", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As Streamed File"
	))
	UMercuryHttpRequest* SetContentAsStreamedFile(const FString& Filename, bool& bRequestStreamed);
	bool SetContentAsStreamedFile(const FString& Filename);
	
	UMercuryHttpRequest* SetContentFromStream(
		const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
		bool& bRequestStreamed
	);
	bool SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Header", Category = "HTTP|Request", meta = (
		Keywords = "Set Header Name Value"
	))
	UMercuryHttpRequest* SetHeader(const FString& HeaderName, const FString& HeaderValue);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Headers", Category = "HTTP|Request", meta = (
		AutoCreateRefTerm = "Headers",
		Keywords = "Set Headers Names Values Map"
	))
	UMercuryHttpRequest* SetHeaders(const TMap<FString, FString>& Headers);

	UFUNCTION(BlueprintCallable, DisplayName = "Append To Header", Category = "HTTP|Request", meta = (
		Keywords = "Append Add Insert To In Header Name Value"
	))
	UMercuryHttpRequest* AppendToHeader(const FString& HeaderName, const FString& HeaderValue);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Set Timeout Limit"
	))
	UMercuryHttpRequest* SetTimeout(float InTimeoutSeconds);

	UFUNCTION(BlueprintCallable, DisplayName = "Clear Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Clear Timeout Limit Reset"
	))
	UMercuryHttpRequest* ClearTimeout();

	UFUNCTION(BlueprintCallable, DisplayName = "Process Request", Category = "HTTP|Request", meta = (
		Keywords = "Process Request Execute Fetch"
	))
	UMercuryHttpRequest* ProcessRequest(bool& bSuccessfullyStarted);
	bool ProcessRequest();

	UFUNCTION(BlueprintCallable, DisplayName = "Cancel Request", Category = "HTTP|Request", meta = (
		Keywords = "Cancel Request Stop Halt Interrupt"
	))
	UMercuryHttpRequest* CancelRequest();

	UFUNCTION(BlueprintPure, DisplayName = "Get HTTP Status", Category = "HTTP|Request", meta = (
		Keywords = "Get HTTP Status"
	))
	EMercuryHttpRequestStatus GetMercuryHttpStatus() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Tick", Category = "HTTP|Request", meta = (
		Keywords = "Tick Update"
	))
	UMercuryHttpRequest* Tick(float DeltaSeconds);

	UFUNCTION(BlueprintPure, DisplayName = "Get Elapsed Time", Category = "HTTP|Request", meta = (
		Keywords = "Get Elapsed Time Count"
	))
	float GetElapsedTime() const;

private:
	UFUNCTION(BlueprintCallable, DisplayName = "Set Process Request Complete Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Process Request Complete Delegate Event"
	))
	UMercuryHttpRequest* SetProcessRequestCompleteEvent(const FMercuryHttpProcessRequestCompleteDelegate& Value)
	{
		OnProcessRequestComplete() = Value;
		return this;
	}
	UFUNCTION(BlueprintInternalUseOnly, DisplayName = "On Process Request Complete", Category = "HTTP|Request", meta = (
		Keywords = "On Process Request Complete Callback Delegate Event"
	))
	void OnProcessRequestCompleteCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		bool bConnectedSuccessfully
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Progress Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Progress Delegate Event"
	))
	UMercuryHttpRequest* SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Value)
	{
		OnRequestProgress() = Value;
		return this;
	}
	UFUNCTION(BlueprintInternalUseOnly, DisplayName = "On Request Progress", Category = "HTTP|Request", meta = (
		Keywords = "On Request Progress Callback Delegate Event"
	))
	void OnMercuryHttpRequestProgressCallback(
		UMercuryHttpRequest* const& Request,
		const int32& BytesSent,
		const int32& BytesReceived
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Will Retry Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Will Retry Delegate Event"
	))
	UMercuryHttpRequest* SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Value)
	{
		OnRequestWillRetry() = Value;
		return this;
	}
	UFUNCTION(BlueprintInternalUseOnly, DisplayName = "On Request Will Retry", Category = "HTTP|Request", meta = (
		Keywords = "On Request Will Retry Callback Delegate Event"
	))
	void OnMercuryHttpRequestWillRetryCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		const float& SecondsToRetry
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Header Received Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Header Received Delegate Event"
	))
	UMercuryHttpRequest* SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Value)
	{
		OnHeaderReceived() = Value;
		return this;
	}
	UFUNCTION(BlueprintInternalUseOnly, DisplayName = "On Header Received", Category = "HTTP|Request", meta = (
		Keywords = "On Header Received Callback Delegate Event"
	))
	void OnMercuryHttpHeaderReceivedCallback(
		UMercuryHttpRequest* const& Request,
		const FString& HeaderName,
		const FString& NewHeaderValue
	);
	
public:
	FORCEINLINE const FHttpRequestPtr& GetReference() const { return Reference; }
	FORCEINLINE FHttpRequestPtr& GetReference() { return Reference; }

	FORCEINLINE const TObjectPtr<UMercuryHttpResponse>& GetMercuryHttpResponse() const { return MercuryHttpResponse; }
	FORCEINLINE TObjectPtr<UMercuryHttpResponse>& GetMercuryHttpResponse() { return MercuryHttpResponse; }
	
	FORCEINLINE FMercuryHttpProcessRequestCompleteDelegate& OnProcessRequestComplete()
	{
		return OnMercuryHttpProcessRequestCompleteDelegate;
	}
	FORCEINLINE FMercuryHttpRequestProgressDelegate& OnRequestProgress()
	{
		return OnMercuryHttpRequestProgressDelegate;
	}
	FORCEINLINE FMercuryHttpRequestWillRetryDelegate& OnRequestWillRetry()
	{
		return OnMercuryHttpRequestWillRetryDelegate;
	}
	FORCEINLINE FMercuryHttpHeaderReceivedDelegate& OnHeaderReceived()
	{
		return OnMercuryHttpHeaderReceivedDelegate;
	}
};
