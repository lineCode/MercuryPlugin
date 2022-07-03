// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "ResourceOwner.h"

#include "MercuryHttpResponse.generated.h"

class IHttpResponse;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Response")
class MERCURYHTTP_API UMercuryHttpResponse : public UObject, public TResourceOwner<IHttpResponse>
{
	GENERATED_BODY()

public:
	explicit UMercuryHttpResponse(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintPure, DisplayName = "Get URL", Category = "HTTP|Response", meta = (
		Keywords = "Get URL Link Host Server"
	))
	virtual FString GetURL() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get URL Parameter", Category = "HTTP|Response", meta = (
		Keywords = "Get URL Parameter Argument Link Server Name"
	))
	virtual FString GetURLParameter(const FString& ParameterName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Header", Category = "HTTP|Response", meta = (
		Keywords = "Get Header Name"
	))
	virtual FString GetHeader(const FString& HeaderName) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get All Headers", Category = "HTTP|Response", meta = (
		Keywords = "Get All Headers Names"
	))
	virtual TArray<FString> GetAllHeaders() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Type", Category = "HTTP|Response", meta = (
		Keywords = "Get Content Type"
	))
	virtual FString GetContentType() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Length", Category = "HTTP|Response", meta = (
		Keywords = "Get Content Length"
	))
	virtual int32 GetContentLength() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Content", Category = "HTTP|Response", meta = (
		Keywords = "Get Content Payload"
	))
	virtual TArray<uint8> GetContent() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Response Code", Category = "HTTP|Response", meta = (
		Keywords = "Get Response Code Status"
	))
	virtual int32 GetResponseCode() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Content As String", Category = "HTTP|Response", meta = (
		Keywords = "Get Content As String"
	))
	virtual FString GetContentAsString() const;
};
