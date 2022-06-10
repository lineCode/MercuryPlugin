// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryBase.h"
#include "MercuryTypes.h"
#include "Interfaces/IHttpRequest.h"

#include "MercuryRequest.generated.h"


UCLASS(BlueprintType)
class MERCURY_API UMercuryRequest final : public UObject, public FHttpRequestPtr, public TMercuryBase<IHttpRequest>
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetURL() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetURLParameter(const FString& ParameterName) const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetHeader(const FString& HeaderName) const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	TArray<FString> GetAllHeaders() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetContentType() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	int32 GetContentLength() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	const TArray<uint8>& GetContent() const;
	
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetVerb() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetVerb(const FString& Verb);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetURL(const FString& URL);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetContent(const TArray<uint8>& ContentPayload);
	void SetContent(TArray<uint8>&& ContentPayload);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetContentAsString(const FString& ContentString);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetContentAsStreamedFile(const FString& Filename);
	
	bool SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetHeader(const FString& HeaderName, const FString& HeaderValue);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void SetTimeout(float InTimeoutSecs);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void ClearTimeout();

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	bool ProcessRequest();
	
	FHttpRequestCompleteDelegate& OnProcessRequestComplete() const;
	
	FHttpRequestProgressDelegate& OnRequestProgress() const;
	
	FHttpRequestWillRetryDelegate& OnRequestWillRetry() const;
	
	FHttpRequestHeaderReceivedDelegate& OnHeaderReceived() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void CancelRequest();

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	EMercuryRequestStatus GetStatus() const;
	
	FHttpResponsePtr GetResponse() const;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void Tick(const float DeltaSeconds);

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	float GetElapsedTime() const;
};
