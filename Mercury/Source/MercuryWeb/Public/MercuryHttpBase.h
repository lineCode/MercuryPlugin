// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttpBase.generated.h"

class IHttpBase;


UCLASS(Abstract, BlueprintType, DisplayName = "Mercury HTTP Base")
class MERCURYWEB_API UMercuryHttpBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Get URL", Category = "HTTP|Base", meta = (
		Keywords = "Get URL Link Host Server"
	))
	virtual FString GetURL() const
	PURE_VIRTUAL(UMercuryHttpBase::GetURL, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get URL Parameter", Category = "HTTP|Base", meta = (
		Keywords = "Get URL Parameter Argument Link Server Name"
	))
	virtual FString GetURLParameter(const FString& ParameterName) const
	PURE_VIRTUAL(UMercuryHttpBase::GetURLParameter, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get Header", Category = "HTTP|Base", meta = (
		Keywords = "Get Header Name"
	))
	virtual FString GetHeader(const FString& HeaderName) const
	PURE_VIRTUAL(UMercuryHttpBase::GetHeader, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get All Headers", Category = "HTTP|Base", meta = (
		Keywords = "Get All Headers Names"
	))
	virtual TArray<FString> GetAllHeaders() const
	PURE_VIRTUAL(UMercuryHttpBase::GetAllHeaders, return TArray<FString>(););

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Type", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Type"
	))
	virtual FString GetContentType() const
	PURE_VIRTUAL(UMercuryHttpBase::GetContentType, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Length", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Length"
	))
	virtual int32 GetContentLength() const
	PURE_VIRTUAL(UMercuryHttpBase::GetContentLength, return 0;);

	UFUNCTION(BlueprintPure, DisplayName = "Get Content", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Payload"
	))
	virtual TArray<uint8> GetContent() const
	PURE_VIRTUAL(UMercuryHttpBase::GetContent, return TArray<uint8>(););
};
