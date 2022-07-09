// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpResponse.h"


FString UMercuryHttpResponse::GetURL() const
{
	return Resource ? Resource->GetURL() : TEXT("");
}

FString UMercuryHttpResponse::GetURLParameter(const FString& ParameterName) const
{
	return Resource ? Resource->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpResponse::GetHeader(const FString& HeaderName) const
{
	return Resource ? Resource->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpResponse::GetAllHeaders() const
{
	return Resource ? Resource->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpResponse::GetContentType() const
{
	return Resource ? Resource->GetContentType() : TEXT("");
}

int32 UMercuryHttpResponse::GetContentLength() const
{
	return Resource ? Resource->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpResponse::GetContent() const
{
	return Resource ? Resource->GetContent() : TArray<uint8>();
}

int32 UMercuryHttpResponse::GetResponseCode() const
{
	return Resource ? Resource->GetResponseCode() : -1;
}

FString UMercuryHttpResponse::GetContentAsString() const
{
	return Resource ? Resource->GetContentAsString() : TEXT("");
}
