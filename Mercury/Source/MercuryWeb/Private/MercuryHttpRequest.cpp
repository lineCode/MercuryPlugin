﻿// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpRequest.h"

#include "HttpModule.h"
#include "MercuryHttpResponse.h"
#include "MercuryWeb.h"

FHttpModule* UMercuryHttpRequest::HttpModule = &FHttpModule::Get();


UMercuryHttpRequest::UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	check(HttpModule);
	Reference = HttpModule->CreateRequest();
	MercuryHttpResponse = CreateDefaultSubobject<UMercuryHttpResponse>(TEXT("Mercury HTTP Response"));
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

UMercuryHttpRequest* UMercuryHttpRequest::SetVerb(const FString& Verb)
{
	if (!Reference)
		return nullptr;

	Reference->SetVerb(Verb);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetURL(const FString& URL)
{
	if (!Reference)
		return nullptr;

	Reference->SetURL(URL);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	if (!Reference)
		return nullptr;

	Reference->SetContent(ContentPayload);
	return this;
}
UMercuryHttpRequest* UMercuryHttpRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	if (!Reference)
		return nullptr;

	Reference->SetContent(ContentPayload);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentAsString(const FString& ContentString)
{
	if (!Reference)
		return nullptr;

	Reference->SetContentAsString(ContentString);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename, bool& bRequestStreamed)
{
	bRequestStreamed = SetContentAsStreamedFile(Filename);
	return bRequestStreamed ? this : nullptr;
}
bool UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename)
{
	return Reference ? Reference->SetContentAsStreamedFile(Filename) : false;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentFromStream(
	const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
	bool& bRequestStreamed
)
{
	bRequestStreamed = SetContentFromStream(Stream);
	return bRequestStreamed ? this : nullptr;
}
bool UMercuryHttpRequest::SetContentFromStream(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream)
{
	return Reference ? Reference->SetContentFromStream(Stream) : false;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!Reference)
		return nullptr;

	Reference->SetHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeaders(const TMap<FString, FString>& Headers)
{
	if (!Reference)
		return nullptr;
	
	for (const TTuple<FString, FString>& Header : Headers)
	{
		SetHeader(Header.Key, Header.Value);
	}
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::AppendToHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!Reference)
		return nullptr;

	Reference->AppendToHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetTimeout(const float InTimeoutSeconds)
{
	if (!Reference)
		return nullptr;

	Reference->SetTimeout(InTimeoutSeconds);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::ClearTimeout()
{
	if (!Reference)
		return nullptr;

	Reference->ClearTimeout();
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::ProcessRequest(bool& bSuccessfullyStarted)
{
	bSuccessfullyStarted = ProcessRequest();
	return bSuccessfullyStarted ? this : nullptr;
}
bool UMercuryHttpRequest::ProcessRequest()
{
	return Reference ? Reference->ProcessRequest() : false;
}

UMercuryHttpRequest* UMercuryHttpRequest::CancelRequest()
{
	if (!Reference)
		return nullptr;

	Reference->CancelRequest();
	return this;
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

UMercuryHttpRequest* UMercuryHttpRequest::Tick(const float DeltaSeconds)
{
	if (!Reference)
		return nullptr;

	Reference->Tick(DeltaSeconds);
	return this;
}

float UMercuryHttpRequest::GetElapsedTime() const
{
	return Reference ? Reference->GetElapsedTime() : 0.0f;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetProcessRequestCompleteEvent(
	const FMercuryHttpProcessRequestCompleteDelegate& Value
)
{
	if (!Reference)
		return nullptr;

	OnMercuryHttpProcessRequestCompleteDelegate = Value;
	BindProcessRequestCompleteDelegate();
	return this;
}

void UMercuryHttpRequest::BindProcessRequestCompleteDelegate()
{
	if (!Reference)
		return;
	
	Reference->OnProcessRequestComplete().BindLambda([this](
		const FHttpRequestPtr Request,
		const FHttpResponsePtr Response,
		const bool bConnectedSuccessfully
	)
	{
		if (!OnMercuryHttpProcessRequestCompleteDelegate.IsBound())
			return;
	
		UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
		MercuryHttpRequest->GetReference() = Request;

		UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
		MercuryHttpResponse->GetReference() = Response;
		MercuryHttpRequest->GetMercuryHttpResponse() = MercuryHttpResponse;
	
		OnMercuryHttpProcessRequestCompleteDelegate.Execute(
			MercuryHttpRequest,
			MercuryHttpResponse,
			bConnectedSuccessfully
		);
	});
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Value)
{
	if (!Reference)
		return nullptr;

	OnMercuryHttpRequestProgressDelegate = Value;
	BindRequestProgressDelegate();
	return this;
}

void UMercuryHttpRequest::BindRequestProgressDelegate()
{
	if (!Reference)
		return;
	
	Reference->OnRequestProgress().BindLambda([this](
		const FHttpRequestPtr Request,
		const int32 BytesSent,
		const int32 BytesReceived
	)
	{
		if (!OnMercuryHttpRequestProgressDelegate.IsBound())
			return;
	
		UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
		MercuryHttpRequest->GetReference() = Request;
	
		OnMercuryHttpRequestProgressDelegate.Execute(MercuryHttpRequest, BytesSent, BytesReceived);
	});
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Value)
{
	if (!Reference)
		return nullptr;

	OnMercuryHttpRequestWillRetryDelegate = Value;
	BindRequestWillRetryDelegate();
	return this;
}

void UMercuryHttpRequest::BindRequestWillRetryDelegate()
{
	if (!Reference)
		return;
	
	Reference->OnRequestWillRetry().BindLambda([this](
		const FHttpRequestPtr Request,
		const FHttpResponsePtr Response,
		const float SecondsToRetry
	)
	{
		if (!OnMercuryHttpRequestWillRetryDelegate.IsBound())
			return;
	
		UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
		MercuryHttpRequest->GetReference() = Request;

		UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
		MercuryHttpResponse->GetReference() = Response;
		MercuryHttpRequest->GetMercuryHttpResponse() = MercuryHttpResponse;
	
		OnMercuryHttpRequestWillRetryDelegate.Execute(MercuryHttpRequest, MercuryHttpResponse, SecondsToRetry);
	});
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Value)
{
	if (!Reference)
		return nullptr;

	OnMercuryHttpHeaderReceivedDelegate = Value;
	BindHeaderReceivedDelegate();
	return this;
}

void UMercuryHttpRequest::BindHeaderReceivedDelegate()
{
	if (!Reference)
		return;
	
	Reference->OnHeaderReceived().BindLambda([this](
		const FHttpRequestPtr Request,
		const FString& HeaderName,
		const FString& NewHeaderValue
	)
	{
		if (!OnMercuryHttpHeaderReceivedDelegate.IsBound())
			return;
	
		UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
		MercuryHttpRequest->GetReference() = Request;
	
		OnMercuryHttpHeaderReceivedDelegate.Execute(MercuryHttpRequest, HeaderName, NewHeaderValue);
	});
}
