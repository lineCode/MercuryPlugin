// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttpBaseObject.h"

#include "MercuryHttpResponse.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Response")
class MERCURYHTTP_API UMercuryHttpResponse : public UMercuryHttpBaseObject
{
	GENERATED_BODY()

	FHttpResponsePtr Reference;

public:
	explicit UMercuryHttpResponse(const FObjectInitializer& ObjectInitializer);
	
	virtual FString GetURL() const override;
	virtual FString GetURLParameter(const FString& ParameterName) const override;
	virtual FString GetHeader(const FString& HeaderName) const override;
	virtual TArray<FString> GetAllHeaders() const override;
	virtual FString GetContentType() const override;
	virtual int32 GetContentLength() const override;
	virtual TArray<uint8> GetContent() const override;
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Response Code", Category = "HTTP|Response", meta = (
		Keywords = "Get Response Code Status"
	))
	virtual int32 GetResponseCode() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Content As String", Category = "HTTP|Response", meta = (
		Keywords = "Get Content As String"
	))
	virtual FString GetContentAsString() const;
	
	FORCEINLINE const FHttpResponsePtr& GetReference() const { return Reference; }
	FORCEINLINE FHttpResponsePtr& GetReference() { return Reference; }
};
