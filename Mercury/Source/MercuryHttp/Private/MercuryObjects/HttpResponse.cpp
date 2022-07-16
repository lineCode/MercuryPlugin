// Copyright (c) 2022 Kaya Adrian

#include "HttpResponse.h"


bool UMercuryHttpResponse::HasResource() const
{
	return Resource != nullptr;
}

FString UMercuryHttpResponse::GetURL() const
{
	return HasResource() ? Resource->GetURL() : TEXT("");
}

FString UMercuryHttpResponse::GetURLParameter(const FString& ParameterName) const
{
	return HasResource() ? Resource->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpResponse::GetHeader(const FString& HeaderName) const
{
	return HasResource() ? Resource->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpResponse::GetAllHeaders() const
{
	return HasResource() ? Resource->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpResponse::GetContentType() const
{
	return HasResource() ? Resource->GetContentType() : TEXT("");
}

int32 UMercuryHttpResponse::GetContentLength() const
{
	return HasResource() ? Resource->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpResponse::GetContent() const
{
	return HasResource() ? Resource->GetContent() : TArray<uint8>();
}

int32 UMercuryHttpResponse::GetResponseCode() const
{
	return HasResource() ? Resource->GetResponseCode() : -1;
}

FString UMercuryHttpResponse::GetContentAsString() const
{
	return HasResource() ? Resource->GetContentAsString() : TEXT("");
}
