// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttp.h"
#include "MercuryWebTypes.h"

#include "MercuryHttpRequest.generated.h"


UCLASS(BlueprintType)
class MERCURYWEB_API UMercuryHttpRequest : public UObject, public FHttpRequestPtr, public TMercuryHttp<IHttpRequest>
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMercuryHttpResponse> MercuryHttpResponse;

	UPROPERTY(BlueprintReadWrite, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestComplete;

	UPROPERTY(BlueprintReadWrite, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgress;

	UPROPERTY(BlueprintReadWrite, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetry;

	UPROPERTY(BlueprintReadWrite, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	FMercuryHttpHeaderReceivedDelegate OnMercuryHttpHeaderReceived;

public:
	explicit UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer);

private:
	UFUNCTION(BlueprintInternalUseOnly)
	void OnProcessRequestCompleteCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		bool bConnectedSuccessfully
	);

	UFUNCTION(BlueprintInternalUseOnly)
	void OnMercuryHttpRequestProgressCallback(
		UMercuryHttpRequest* const& Request,
		const int32& BytesSent,
		const int32& BytesReceived
	);

	UFUNCTION(BlueprintInternalUseOnly)
	void OnMercuryHttpRequestWillRetryCallback(
		UMercuryHttpRequest* const& Request,
		UMercuryHttpResponse* const& Response,
		const float& SecondsToRetry
	);

	UFUNCTION(BlueprintInternalUseOnly)
	void OnMercuryHttpRequestHeaderReceivedCallback(
		UMercuryHttpRequest* const& Request,
		const FString& HeaderName,
		const FString& NewHeaderValue
	);
	
public:
	UFUNCTION(BlueprintCallable)
	FString GetURL() const;

	UFUNCTION(BlueprintCallable)
	FString GetURLParameter(const FString& ParameterName) const;

	UFUNCTION(BlueprintCallable)
	FString GetHeader(const FString& HeaderName) const;

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllHeaders() const;

	UFUNCTION(BlueprintCallable)
	FString GetContentType() const;

	UFUNCTION(BlueprintCallable)
	int32 GetContentLength() const;

	UFUNCTION(BlueprintCallable)
	const TArray<uint8>& GetContent() const;
	
	UFUNCTION(BlueprintCallable)
	FString GetVerb() const;

	UFUNCTION(BlueprintCallable)
	void SetVerb(const FString& Verb);

	UFUNCTION(BlueprintCallable)
	void SetURL(const FString& URL);

	UFUNCTION(BlueprintCallable)
	void SetContent(const TArray<uint8>& ContentPayload);
	void SetContent(TArray<uint8>&& ContentPayload);

	UFUNCTION(BlueprintCallable)
	void SetContentAsString(const FString& ContentString);

	UFUNCTION(BlueprintCallable)
	void SetContentAsStreamedFile(const FString& Filename);
	
	bool SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);

	UFUNCTION(BlueprintCallable)
	void SetHeader(const FString& HeaderName, const FString& HeaderValue);

	UFUNCTION(BlueprintCallable)
	void AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue);

	UFUNCTION(BlueprintCallable)
	void SetTimeout(float InTimeoutSecs);

	UFUNCTION(BlueprintCallable)
	void ClearTimeout();

	UFUNCTION(BlueprintCallable)
	bool ProcessRequest();

	UFUNCTION(BlueprintCallable)
	FMercuryHttpProcessRequestCompleteDelegate& OnProcessRequestComplete();

	UFUNCTION(BlueprintCallable)
	FMercuryHttpRequestProgressDelegate& OnRequestProgress();

	UFUNCTION(BlueprintCallable)
	FMercuryHttpRequestWillRetryDelegate& OnRequestWillRetry();

	UFUNCTION(BlueprintCallable)
	FMercuryHttpHeaderReceivedDelegate& OnHeaderReceived();

	UFUNCTION(BlueprintCallable)
	void CancelRequest();

	UFUNCTION(BlueprintCallable)
	EMercuryHttpRequestStatus GetStatus() const;

	UFUNCTION(BlueprintCallable)
	const UMercuryHttpResponse* GetResponse() const;

	UFUNCTION(BlueprintCallable)
	void Tick(const float DeltaSeconds);

	UFUNCTION(BlueprintCallable)
	float GetElapsedTime() const;
};
