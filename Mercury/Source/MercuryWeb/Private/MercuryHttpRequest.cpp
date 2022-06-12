// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpRequest.h"

#include "MercuryHttpResponse.h"
#include "MercuryWeb.h"


UMercuryHttpRequest::UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MercuryHttpResponse = CreateDefaultSubobject<UMercuryHttpResponse>(TEXT("Mercury HTTP Response"));
	OnMercuryHttpProcessRequestComplete.BindDynamic(this, &UMercuryHttpRequest::OnProcessRequestCompleteCallback);
	OnMercuryHttpRequestProgress.BindDynamic(this, &UMercuryHttpRequest::OnMercuryHttpRequestProgressCallback);
	OnMercuryHttpRequestWillRetry.BindDynamic(this, &UMercuryHttpRequest::OnMercuryHttpRequestWillRetryCallback);
	OnMercuryHttpHeaderReceived.BindDynamic(this, &UMercuryHttpRequest::OnMercuryHttpRequestHeaderReceivedCallback);
}

void UMercuryHttpRequest::OnProcessRequestCompleteCallback(
	UMercuryHttpRequest* const& Request,
	UMercuryHttpResponse* const& Response,
	const bool bConnectedSuccessfully
)
{
	GetReference()->OnProcessRequestComplete().ExecuteIfBound(
		static_cast<FHttpRequestPtr>(Request->GetReference()),
		static_cast<FHttpResponsePtr>(Response->GetReference()),
		bConnectedSuccessfully
	);
}

void UMercuryHttpRequest::OnMercuryHttpRequestProgressCallback(
	UMercuryHttpRequest* const& Request,
	const int32& BytesSent,
	const int32& BytesReceived
)
{
	GetReference()->OnRequestProgress().ExecuteIfBound(
		static_cast<FHttpRequestPtr>(Request->GetReference()),
		BytesSent,
		BytesReceived
	);
}

void UMercuryHttpRequest::OnMercuryHttpRequestWillRetryCallback(
	UMercuryHttpRequest* const& Request,
	UMercuryHttpResponse* const& Response,
	const float& SecondsToRetry
)
{
	GetReference()->OnRequestWillRetry().ExecuteIfBound(
		static_cast<FHttpRequestPtr>(Request->GetReference()),
		static_cast<FHttpResponsePtr>(Response->GetReference()),
		SecondsToRetry
	);
}

void UMercuryHttpRequest::OnMercuryHttpRequestHeaderReceivedCallback(
	UMercuryHttpRequest* const& Request,
	const FString& HeaderName,
	const FString& NewHeaderValue
)
{
	GetReference()->OnHeaderReceived().ExecuteIfBound(
		static_cast<FHttpRequestPtr>(Request->GetReference()),
		HeaderName,
		NewHeaderValue
	);
}

FString UMercuryHttpRequest::GetURL() const
{
	return Reference->GetURL();
}

FString UMercuryHttpRequest::GetURLParameter(const FString& ParameterName) const
{
	return Reference->GetURLParameter(ParameterName);
}

FString UMercuryHttpRequest::GetHeader(const FString& HeaderName) const
{
	return Reference->GetHeader(HeaderName);
}

TArray<FString> UMercuryHttpRequest::GetAllHeaders() const
{
	return Reference->GetAllHeaders();
}

FString UMercuryHttpRequest::GetContentType() const
{
	return Reference->GetContentType();
}

int32 UMercuryHttpRequest::GetContentLength() const
{
	return Reference->GetContentLength();
}

const TArray<uint8>& UMercuryHttpRequest::GetContent() const
{
	return Reference->GetContent();
}

FString UMercuryHttpRequest::GetVerb() const
{
	return Reference->GetVerb();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetVerb(const FString& Verb)
{
	Reference->SetVerb(Verb);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetURL(const FString& URL)
{
	Reference->SetURL(URL);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	Reference->SetContent(ContentPayload);
}

void UMercuryHttpRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	Reference->SetContent(ContentPayload);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetContentAsString(const FString& ContentString)
{
	Reference->SetContentAsString(ContentString);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename)
{
	Reference->SetContentAsStreamedFile(Filename);
}

bool UMercuryHttpRequest::SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream)
{
	return Reference->SetContentFromStream(Stream);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	Reference->SetHeader(HeaderName, HeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue)
{
	Reference->AppendToHeader(HeaderName, AdditionalHeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetTimeout(const float InTimeoutSecs)
{
	Reference->SetTimeout(InTimeoutSecs);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::ClearTimeout()
{
	Reference->ClearTimeout();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
bool UMercuryHttpRequest::ProcessRequest()
{
	return Reference->ProcessRequest();
}

FMercuryHttpProcessRequestCompleteDelegate& UMercuryHttpRequest::OnProcessRequestComplete()
{
	return OnMercuryHttpProcessRequestComplete;
}

FMercuryHttpRequestProgressDelegate& UMercuryHttpRequest::OnRequestProgress()
{
	return OnMercuryHttpRequestProgress;
}

FMercuryHttpRequestWillRetryDelegate& UMercuryHttpRequest::OnRequestWillRetry()
{
	return OnMercuryHttpRequestWillRetry;
}

FMercuryHttpHeaderReceivedDelegate& UMercuryHttpRequest::OnHeaderReceived()
{
	return OnMercuryHttpHeaderReceived;
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::CancelRequest()
{
	Reference->CancelRequest();
}

EMercuryHttpRequestStatus UMercuryHttpRequest::GetStatus() const
{
	switch (const EHttpRequestStatus::Type& Status = Reference->GetStatus())
	{
	case EHttpRequestStatus::NotStarted:
		return EMercuryHttpRequestStatus::NotStarted;

	case EHttpRequestStatus::Processing:
		return EMercuryHttpRequestStatus::Processing;

	case EHttpRequestStatus::Failed:
		return EMercuryHttpRequestStatus::Failed;

	case EHttpRequestStatus::Failed_ConnectionError:
		return EMercuryHttpRequestStatus::Failed_ConnectionError;

	case EHttpRequestStatus::Succeeded:
		return EMercuryHttpRequestStatus::Succeeded;

	default:
		UE_LOG(LogMercuryWeb, Error, TEXT("Unknown request status: %d"), Status);
	}

	return EMercuryHttpRequestStatus::Unknown;
}

const UMercuryHttpResponse* UMercuryHttpRequest::GetResponse() const
{
	MercuryHttpResponse->GetReference() = Reference->GetResponse().Get();
	return MercuryHttpResponse.Get();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::Tick(const float DeltaSeconds)
{
	Reference->Tick(DeltaSeconds);
}

float UMercuryHttpRequest::GetElapsedTime() const
{
	return Reference->GetElapsedTime();
}
