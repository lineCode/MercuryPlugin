// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttpBase.h"
#include "MercuryWebTypes.h"

#include "MercuryHttpRequest.generated.h"


UCLASS(BlueprintType, DisplayName = "Mercury HTTP Request")
class MERCURYWEB_API UMercuryHttpRequest : public UMercuryHttpBase
{
	GENERATED_BODY()

	FHttpRequestPtr Reference;
	
	UPROPERTY(BlueprintReadWrite, DisplayName = "HTTP Response", Category = "HTTP|Request", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<UMercuryHttpResponse> MercuryHttpResponse;

	UPROPERTY(
		BlueprintReadWrite,
		BlueprintGetter = "OnProcessRequestComplete",
		DisplayName = "Process Request Complete Event",
		Category = "HTTP|Request",
		meta = (AllowPrivateAccess = "true")
	)
	FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestCompleteDelegate;
	
	UPROPERTY(
		BlueprintReadWrite,
		BlueprintGetter = "OnRequestProgress",
		DisplayName = "Request Progress Event",
		Category = "HTTP|Request",
		meta = (AllowPrivateAccess = "true")
	)
	FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgressDelegate;
	
	UPROPERTY(
		BlueprintReadWrite,
		BlueprintGetter = "OnRequestWillRetry",
		DisplayName = "Request Will Retry Event",
		Category = "HTTP|Request",
		meta = (AllowPrivateAccess = "true")
	)
	FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetryDelegate;
	
	UPROPERTY(
		BlueprintReadWrite,
		BlueprintGetter = "OnHeaderReceived",
		DisplayName = "Header Received Event",
		Category = "HTTP|Request",
		meta = (AllowPrivateAccess = "true")
	)
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
	void SetVerb(const FString& Verb);

	UFUNCTION(BlueprintCallable, DisplayName = "Set URL", Category = "HTTP|Request", meta = (
		Keywords = "Set URL Link Host Server"
	))
	void SetURL(const FString& URL);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content", Category = "HTTP|Request", meta = (
		Keywords = "Set Content Payload"
	))
	void SetContent(const TArray<uint8>& ContentPayload);
	void SetContent(TArray<uint8>&& ContentPayload);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As String", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As String"
	))
	void SetContentAsString(const FString& ContentString);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Content As Streamed File", Category = "HTTP|Request", meta = (
		Keywords = "Set Content As Streamed File"
	))
	bool SetContentAsStreamedFile(const FString& Filename);
	
	bool SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Header", Category = "HTTP|Request", meta = (
		Keywords = "Set Header Name"
	))
	void SetHeader(const FString& HeaderName, const FString& HeaderValue);

	UFUNCTION(BlueprintCallable, DisplayName = "Append To Header", Category = "HTTP|Request", meta = (
		Keywords = "Append Add Insert To In Header Name Value"
	))
	void AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Set Timeout Limit"
	))
	void SetTimeout(float InTimeoutSeconds);

	UFUNCTION(BlueprintCallable, DisplayName = "Clear Timeout", Category = "HTTP|Request", meta = (
		Keywords = "Clear Timeout Limit Reset"
	))
	void ClearTimeout();

	UFUNCTION(BlueprintCallable, DisplayName = "Process Request", Category = "HTTP|Request", meta = (
		Keywords = "Process Request Execute Fetch"
	))
	bool ProcessRequest();

	UFUNCTION(BlueprintCallable, DisplayName = "Cancel Request", Category = "HTTP|Request", meta = (
		Keywords = "Cancel Request Stop Halt Interrupt"
	))
	void CancelRequest();

	UFUNCTION(BlueprintPure, DisplayName = "Get HTTP Status", Category = "HTTP|Request", meta = (
		Keywords = "Get HTTP Status"
	))
	EMercuryHttpRequestStatus GetMercuryHttpStatus() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Tick", Category = "HTTP|Request", meta = (
		Keywords = "Tick Update"
	))
	void Tick(float DeltaSeconds);

	UFUNCTION(BlueprintPure, DisplayName = "Get Elapsed Time", Category = "HTTP|Request", meta = (
		Keywords = "Get Elapsed Time Count"
	))
	float GetElapsedTime() const;

private:
	UFUNCTION(
		BlueprintInternalUseOnly,
		DisplayName = "Process Request Complete Callback",
		Category = "HTTP|Request",
		meta = (Keywords = "Process Request Complete Callback Delegate Event")
	)
	void OnProcessRequestCompleteCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		bool bConnectedSuccessfully
	);

	UFUNCTION(
		BlueprintInternalUseOnly,
		DisplayName = "Request Progress Callback",
		Category = "HTTP|Request",
		meta = (Keywords = "Request Progress Callback Delegate Event")
	)
	void OnMercuryHttpRequestProgressCallback(
		UMercuryHttpRequest* const& Request,
		const int32& BytesSent,
		const int32& BytesReceived
	);

	UFUNCTION(
		BlueprintInternalUseOnly,
		DisplayName = "Request Will Retry Callback",
		Category = "HTTP|Request",
		meta = (Keywords = "Request Will Retry Callback Delegate Event")
	)
	void OnMercuryHttpRequestWillRetryCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		const float& SecondsToRetry
	);

	UFUNCTION(
		BlueprintInternalUseOnly,
		DisplayName = "Header Received Callback",
		Category = "HTTP|Request",
		meta = (Keywords = "Header Received Callback Delegate Event")
	)
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

	UFUNCTION(BlueprintPure, DisplayName = "On Process Request Complete", Category = "HTTP|Request", meta = (
		Keywords = "On Process Request Complete Delegate Event"
	))
	FORCEINLINE FMercuryHttpProcessRequestCompleteDelegate& OnProcessRequestComplete()
	{
		return OnMercuryHttpProcessRequestCompleteDelegate;
	}

	UFUNCTION(BlueprintPure, DisplayName = "On Request Progress", Category = "HTTP|Request", meta = (
		Keywords = "On Request Progress Delegate Event"
	))
	FORCEINLINE FMercuryHttpRequestProgressDelegate& OnRequestProgress()
	{
		return OnMercuryHttpRequestProgressDelegate;
	}

	UFUNCTION(BlueprintPure, DisplayName = "On Request Will Retry", Category = "HTTP|Request", meta = (
		Keywords = "On Request Will Retry Delegate Event"
	))
	FORCEINLINE FMercuryHttpRequestWillRetryDelegate& OnRequestWillRetry()
	{
		return OnMercuryHttpRequestWillRetryDelegate;
	}

	UFUNCTION(BlueprintPure, DisplayName = "On Header Received", Category = "HTTP|Request", meta = (
		Keywords = "On Header Received Delegate Event"
	))
	FORCEINLINE FMercuryHttpHeaderReceivedDelegate& OnHeaderReceived()
	{
		return OnMercuryHttpHeaderReceivedDelegate;
	}
};
