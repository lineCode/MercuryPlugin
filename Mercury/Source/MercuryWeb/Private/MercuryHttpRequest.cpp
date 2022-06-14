// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpRequest.h"

#include "MercuryHttpResponse.h"
#include "MercuryWeb.h"


UMercuryHttpRequest::UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Reference = nullptr;
	MercuryHttpResponse = CreateDefaultSubobject<UMercuryHttpResponse>(TEXT("Mercury HTTP Response"));
	
	OnMercuryHttpProcessRequestCompleteDelegate.BindDynamic(
		this,
		&UMercuryHttpRequest::OnProcessRequestCompleteCallback
	);
	OnMercuryHttpRequestProgressDelegate.BindDynamic(
		this,
		&UMercuryHttpRequest::OnMercuryHttpRequestProgressCallback
	);
	OnMercuryHttpRequestWillRetryDelegate.BindDynamic(
		this,
		&UMercuryHttpRequest::OnMercuryHttpRequestWillRetryCallback
	);
	OnMercuryHttpHeaderReceivedDelegate.BindDynamic(
		this,
		&UMercuryHttpRequest::OnMercuryHttpHeaderReceivedCallback
	);
}

FString UMercuryHttpRequest::GetURL() const
{
	return Reference ? Reference->GetURL() : TEXT("");
}

FString UMercuryHttpRequest::GetURLParameter(const FString& ParameterName) const
{
	return Reference ? Reference->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpRequest::GetHeader(const FString& HeaderName) const
{
	return Reference ? Reference->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpRequest::GetAllHeaders() const
{
	return Reference ? Reference->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpRequest::GetContentType() const
{
	return Reference ? Reference->GetContentType() : TEXT("");
}

int32 UMercuryHttpRequest::GetContentLength() const
{
	return Reference ? Reference->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpRequest::GetContent() const
{
	return Reference ? Reference->GetContent() : TArray<uint8>();
}

FString UMercuryHttpRequest::GetVerb() const
{
	return Reference ? Reference->GetVerb() : TEXT("");
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetVerb(const FString& Verb)
{
	if (!Reference)
		return;
	
	Reference->SetVerb(Verb);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetURL(const FString& URL)
{
	if (!Reference)
		return;
	
	Reference->SetURL(URL);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	if (!Reference)
		return;

	Reference->SetContent(ContentPayload);
}

void UMercuryHttpRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	if (!Reference)
		return;

	Reference->SetContent(ContentPayload);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetContentAsString(const FString& ContentString)
{
	if (!Reference)
		return;

	Reference->SetContentAsString(ContentString);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
bool UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename)
{
	return Reference ? Reference->SetContentAsStreamedFile(Filename) : false;
}

bool UMercuryHttpRequest::SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream)
{
	return Reference ? Reference->SetContentFromStream(Stream) : false;
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!Reference)
		return;

	Reference->SetHeader(HeaderName, HeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::AppendToHeader(const FString& HeaderName, const FString& AdditionalHeaderValue)
{
	if (!Reference)
		return;

	Reference->AppendToHeader(HeaderName, AdditionalHeaderValue);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::SetTimeout(const float InTimeoutSeconds)
{
	if (!Reference)
		return;

	Reference->SetTimeout(InTimeoutSeconds);
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::ClearTimeout()
{
	if (!Reference)
		return;

	Reference->ClearTimeout();
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
bool UMercuryHttpRequest::ProcessRequest()
{
	return Reference ? Reference->ProcessRequest() : false;
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::CancelRequest()
{
	if (!Reference)
		return;

	Reference->CancelRequest();
}

EMercuryHttpRequestStatus UMercuryHttpRequest::GetMercuryHttpStatus() const
{
	if (!Reference)
		return EMercuryHttpRequestStatus::Unknown;
	
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
		return EMercuryHttpRequestStatus::Unknown;
	}
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercuryHttpRequest::Tick(const float DeltaSeconds)
{
	if (!Reference)
		return;

	Reference->Tick(DeltaSeconds);
}

float UMercuryHttpRequest::GetElapsedTime() const
{
	return Reference ? Reference->GetElapsedTime() : 0.0f;
}

void UMercuryHttpRequest::OnProcessRequestCompleteCallback(
	UMercuryHttpRequest* const& Request,
	UMercuryHttpResponse* const& Response,
	const bool bConnectedSuccessfully
)
{
	if (!Reference)
		return;

	Reference->OnProcessRequestComplete().ExecuteIfBound(
		Request->GetReference(),
		Response->GetReference(),
		bConnectedSuccessfully
	);
}

void UMercuryHttpRequest::OnMercuryHttpRequestProgressCallback(
	UMercuryHttpRequest* const& Request,
	const int32& BytesSent,
	const int32& BytesReceived
)
{
	if (!Reference)
		return;

	Reference->OnRequestProgress().ExecuteIfBound(Request->GetReference(), BytesSent, BytesReceived);
}

void UMercuryHttpRequest::OnMercuryHttpRequestWillRetryCallback(
	UMercuryHttpRequest* const& Request,
	UMercuryHttpResponse* const& Response,
	const float& SecondsToRetry
)
{
	if (!Reference)
		return;

	Reference->OnRequestWillRetry().ExecuteIfBound(Request->GetReference(), Response->GetReference(), SecondsToRetry);
}

void UMercuryHttpRequest::OnMercuryHttpHeaderReceivedCallback(
	UMercuryHttpRequest* const& Request,
	const FString& HeaderName,
	const FString& NewHeaderValue
)
{
	if (!Reference)
		return;

	Reference->OnHeaderReceived().ExecuteIfBound(Request->GetReference(), HeaderName, NewHeaderValue);
}
