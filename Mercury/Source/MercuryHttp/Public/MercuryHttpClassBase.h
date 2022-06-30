// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttpClassBase.generated.h"

class FHttpModule;
class IHttpBase;


UCLASS(Abstract, Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Class Base")
class MERCURYHTTP_API UMercuryHttpClassBase : public UObject
{
	GENERATED_BODY()

protected:
	static FHttpModule* const HttpModule;

public:
	explicit UMercuryHttpClassBase(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintPure, DisplayName = "Get URL", Category = "HTTP|Base", meta = (
		Keywords = "Get URL Link Host Server"
	))
	virtual FString GetURL() const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetURL, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get URL Parameter", Category = "HTTP|Base", meta = (
		Keywords = "Get URL Parameter Argument Link Server Name"
	))
	virtual FString GetURLParameter(const FString& ParameterName) const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetURLParameter, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get Header", Category = "HTTP|Base", meta = (
		Keywords = "Get Header Name"
	))
	virtual FString GetHeader(const FString& HeaderName) const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetHeader, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get All Headers", Category = "HTTP|Base", meta = (
		Keywords = "Get All Headers Names"
	))
	virtual TArray<FString> GetAllHeaders() const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetAllHeaders, return TArray<FString>(););

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Type", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Type"
	))
	virtual FString GetContentType() const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetContentType, return TEXT(""););

	UFUNCTION(BlueprintPure, DisplayName = "Get Content Length", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Length"
	))
	virtual int32 GetContentLength() const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetContentLength, return 0;);

	UFUNCTION(BlueprintPure, DisplayName = "Get Content", Category = "HTTP|Base", meta = (
		Keywords = "Get Content Payload"
	))
	virtual TArray<uint8> GetContent() const
	PURE_VIRTUAL(UMercuryHttpClassBase::GetContent, return TArray<uint8>(););
};
