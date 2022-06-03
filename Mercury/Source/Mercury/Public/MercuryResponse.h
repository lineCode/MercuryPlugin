// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryBase.h"
#include "Interfaces/IHttpResponse.h"
#include "Interfaces/IHttpRequest.h"

#include "MercuryResponse.generated.h"


UCLASS(BlueprintType)
class MERCURY_API UMercuryResponse final : public UObject, public FHttpResponsePtr, public TMercuryBase<IHttpResponse>
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
	int32 GetResponseCode() const;
	
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	FString GetContentAsString() const;
};
