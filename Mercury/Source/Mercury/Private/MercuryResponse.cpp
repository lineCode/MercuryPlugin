// Copyright (c) 2022 Kaya Adrian

#include "MercuryResponse.h"


FString UMercuryResponse::GetURL() const
{
	return Reference->GetURL();
}

FString UMercuryResponse::GetURLParameter(const FString& ParameterName) const
{
	return Reference->GetURLParameter(ParameterName);
}

FString UMercuryResponse::GetHeader(const FString& HeaderName) const
{
	return Reference->GetHeader(HeaderName);
}

TArray<FString> UMercuryResponse::GetAllHeaders() const
{
	return Reference->GetAllHeaders();
}

FString UMercuryResponse::GetContentType() const
{
	return Reference->GetContentType();
}

int32 UMercuryResponse::GetContentLength() const
{
	return Reference->GetContentLength();
}

const TArray<uint8>& UMercuryResponse::GetContent() const
{
	return Reference->GetContent();
}

int32 UMercuryResponse::GetResponseCode() const
{
	return Reference->GetResponseCode();
}

FString UMercuryResponse::GetContentAsString() const
{
	return Reference->GetContentAsString();
}
