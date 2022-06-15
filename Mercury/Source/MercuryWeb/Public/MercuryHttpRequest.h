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

	UPROPERTY(BlueprintReadOnly, DisplayName = "Process Request Complete Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestCompleteDelegate;
	
	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Progress Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgressDelegate;
	
	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Will Retry Event", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetryDelegate;
	
	UPROPERTY(BlueprintReadOnly, DisplayName = "Header Received Event", Category = "HTTP|Request", meta = (
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
	UMercuryHttpRequest* K2_SetProcessRequestCompleteEvent(const FMercuryHttpProcessRequestCompleteDelegate& Event);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Progress Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Progress Delegate Event"
	))
	UMercuryHttpRequest* K2_SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Event);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Request Will Retry Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Request Will Retry Delegate Event"
	))
	UMercuryHttpRequest* K2_SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Event);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Header Received Event", Category = "HTTP|Request", meta = (
		Keywords = "On Set Header Received Delegate Event"
	))
	UMercuryHttpRequest* K2_SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Event);
	
	void BindProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	void BindRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	void BindRequestWillRetry(FHttpRequestPtr Request, FHttpResponsePtr Response, float SecondsToRetry);
	void BindHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

public:
	FORCEINLINE const FHttpRequestPtr& GetReference() const { return Reference; }
	FORCEINLINE FHttpRequestPtr& GetReference() { return Reference; }

	FORCEINLINE const TObjectPtr<UMercuryHttpResponse>& GetMercuryHttpResponse() const { return MercuryHttpResponse; }
	FORCEINLINE TObjectPtr<UMercuryHttpResponse>& GetMercuryHttpResponse() { return MercuryHttpResponse; }

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
