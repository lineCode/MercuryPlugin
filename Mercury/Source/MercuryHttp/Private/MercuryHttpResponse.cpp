// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpResponse.h"

#include "Interfaces/IHttpResponse.h"


UMercuryHttpResponse::UMercuryHttpResponse(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Reference = nullptr;
}

FString UMercuryHttpResponse::GetURL() const
{
	return Reference ? Reference->GetURL() : TEXT("");
}

FString UMercuryHttpResponse::GetURLParameter(const FString& ParameterName) const
{
	return Reference ? Reference->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpResponse::GetHeader(const FString& HeaderName) const
{
	return Reference ? Reference->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpResponse::GetAllHeaders() const
{
	return Reference ? Reference->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpResponse::GetContentType() const
{
	return Reference ? Reference->GetContentType() : TEXT("");
}

int32 UMercuryHttpResponse::GetContentLength() const
{
	return Reference ? Reference->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpResponse::GetContent() const
{
	return Reference ? Reference->GetContent() : TArray<uint8>();
}

int32 UMercuryHttpResponse::GetResponseCode() const
{
	return Reference ? Reference->GetResponseCode() : -1;
}

FString UMercuryHttpResponse::GetContentAsString() const
{
	return Reference ? Reference->GetContentAsString() : TEXT("");
}
