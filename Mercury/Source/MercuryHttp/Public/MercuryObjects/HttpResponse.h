// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IHttpResponse.h"
#include "MercuryResourceOwner.h"

#include "HttpResponse.generated.h"

class IHttpResponse;


/** Object encapsulating an HTTP response */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Response")
class MERCURYHTTP_API UMercuryHttpResponse : public UObject, public TResourceOwner<IHttpResponse>
{
	GENERATED_BODY()

public:
	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "HTTP|Response", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the URL at which the request was sent. */
	UFUNCTION(BlueprintPure, DisplayName = "Get URL", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "URL",
		Keywords = "Get URL Link Host Server"
	))
	virtual FString GetURL() const;

	/**
	 * Obtains the value of a URL parameter.
	 *
	 * @param ParameterName Name of the URL parameter
	 * @return The value of the selected parameter
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get URL Parameter", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "URL Parameter",
		Keywords = "Get URL Parameter Argument Link Server Name"
	))
	virtual FString GetURLParameter(const FString& ParameterName) const;

	/**
	 * Obtains the value of a header.
	 *
	 * @param HeaderName Name of the header
	 * @return The value of the selected header
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Header", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Header",
		Keywords = "Get Header Name"
	))
	virtual FString GetHeader(const FString& HeaderName) const;

	/** Obtains an array of all request headers with their names and values. */
	UFUNCTION(BlueprintPure, DisplayName = "Get All Headers", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "All Headers",
		Keywords = "Get All Headers Names"
	))
	virtual TArray<FString> GetAllHeaders() const;

	/** Obtains the Content-Type header value. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content Type", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Content Type",
		Keywords = "Get Content Type"
	))
	virtual FString GetContentType() const;

	/** Obtains the Content-Length header value. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content Length", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Content Length",
		Keywords = "Get Content Length"
	))
	virtual int32 GetContentLength() const;

	/** Obtains the content payload response. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Content",
		Keywords = "Get Content Payload"
	))
	virtual TArray<uint8> GetContent() const;

	/** Obtains the response code or -1 if the resource is NULL. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Response Code", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Response Code",
		Keywords = "Get Response Code Status"
	))
	virtual int32 GetResponseCode() const;

	/** Obtains the content payload as a UTF-8 string. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Content As String", Category = "HTTP|Response", meta = (
		CompactNodeTitle = "Content",
		Keywords = "Get Content As String"
	))
	virtual FString GetContentAsString() const;
};
