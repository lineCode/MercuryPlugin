// Copyright (c) 2022 Kaya Adrian

#include "MercuryRequest.h"

#include "Mercury.h"


FString UMercuryRequest::GetURL() const
{
	return Reference->GetURL();
}

FString UMercuryRequest::GetURLParameter(const FString& ParameterName) const
{
	return Reference->GetURLParameter(ParameterName);
}

FString UMercuryRequest::GetHeader(const FString& HeaderName) const
{
	return Reference->GetHeader(HeaderName);
}

TArray<FString> UMercuryRequest::GetAllHeaders() const
{
	return Reference->GetAllHeaders();
}

FString UMercuryRequest::GetContentType() const
{
	return Reference->GetContentType();
}

int32 UMercuryRequest::GetContentLength() const
{
	return Reference->GetContentLength();
}

const TArray<uint8>& UMercuryRequest::GetContent() const
{
	return Reference->GetContent();
}

FString UMercuryRequest::GetVerb() const
{
	return Reference->GetVerb();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetVerb(const FString& Verb)
{
	Reference->SetVerb(Verb);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetURL(const FString& URL)
{
	Reference->SetURL(URL);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	Reference->SetContent(ContentPayload);
}

void UMercuryRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	Reference->SetContent(ContentPayload);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetContentAsString(const FString& ContentString)
{
	Reference->SetContentAsString(ContentString);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetContentAsStreamedFile(const FString& Filename)
{
	Reference->SetContentAsStreamedFile(Filename);
}

bool UMercuryRequest::SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream)
{
	return Reference->SetContentFromStream(Stream);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	Reference->SetHeader(HeaderName, HeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue)
{
	Reference->AppendToHeader(HeaderName, AdditionalHeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::SetTimeout(const float InTimeoutSecs)
{
	Reference->SetTimeout(InTimeoutSecs);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::ClearTimeout()
{
	Reference->ClearTimeout();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
bool UMercuryRequest::ProcessRequest()
{
	return Reference->ProcessRequest();
}

FHttpRequestCompleteDelegate& UMercuryRequest::OnProcessRequestComplete() const
{
	return Reference->OnProcessRequestComplete();
}

FHttpRequestProgressDelegate& UMercuryRequest::OnRequestProgress() const
{
	return Reference->OnRequestProgress();
}

FHttpRequestWillRetryDelegate& UMercuryRequest::OnRequestWillRetry() const
{
	return Reference->OnRequestWillRetry();
}

FHttpRequestHeaderReceivedDelegate& UMercuryRequest::OnHeaderReceived() const
{
	return Reference->OnHeaderReceived();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::CancelRequest()
{
	Reference->CancelRequest();
}

EMercuryRequestStatus UMercuryRequest::GetStatus() const
{
	switch (const EHttpRequestStatus::Type& Status = Reference->GetStatus())
	{
	case EHttpRequestStatus::NotStarted:
		return EMercuryRequestStatus::NotStarted;

	case EHttpRequestStatus::Processing:
		return EMercuryRequestStatus::Processing;

	case EHttpRequestStatus::Failed:
		return EMercuryRequestStatus::Failed;

	case EHttpRequestStatus::Failed_ConnectionError:
		return EMercuryRequestStatus::Failed_ConnectionError;

	case EHttpRequestStatus::Succeeded:
		return EMercuryRequestStatus::Succeeded;

	default:
		UE_LOG(LogMercury, Error, TEXT("Unknown request status: %d"), Status);
	}

	return EMercuryRequestStatus::Failed;
}

FHttpResponsePtr UMercuryRequest::GetResponse() const
{
	return Reference->GetResponse();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryRequest::Tick(const float DeltaSeconds)
{
	Reference->Tick(DeltaSeconds);
}

float UMercuryRequest::GetElapsedTime() const
{
	return Reference->GetElapsedTime();
}
