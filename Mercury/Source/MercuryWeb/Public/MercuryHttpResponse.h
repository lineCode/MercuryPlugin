// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttp.h"
#include "Interfaces/IHttpResponse.h"
#include "Interfaces/IHttpRequest.h"

#include "MercuryHttpResponse.generated.h"


UCLASS(BlueprintType)
class MERCURYWEB_API UMercuryHttpResponse : public UObject, public FHttpResponsePtr, public TMercuryHttp<IHttpResponse>
{
	GENERATED_BODY()

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
	int32 GetResponseCode() const;
	
	UFUNCTION(BlueprintCallable)
	FString GetContentAsString() const;
};
