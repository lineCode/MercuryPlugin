// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpResponse.h"


FString UMercuryHttpResponse::GetURL() const
{
	return Reference->GetURL();
}

FString UMercuryHttpResponse::GetURLParameter(const FString& ParameterName) const
{
	return Reference->GetURLParameter(ParameterName);
}

FString UMercuryHttpResponse::GetHeader(const FString& HeaderName) const
{
	return Reference->GetHeader(HeaderName);
}

TArray<FString> UMercuryHttpResponse::GetAllHeaders() const
{
	return Reference->GetAllHeaders();
}

FString UMercuryHttpResponse::GetContentType() const
{
	return Reference->GetContentType();
}

int32 UMercuryHttpResponse::GetContentLength() const
{
	return Reference->GetContentLength();
}

const TArray<uint8>& UMercuryHttpResponse::GetContent() const
{
	return Reference->GetContent();
}

int32 UMercuryHttpResponse::GetResponseCode() const
{
	return Reference->GetResponseCode();
}

FString UMercuryHttpResponse::GetContentAsString() const
{
	return Reference->GetContentAsString();
}
