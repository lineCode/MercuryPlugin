// Copyright (c) 2022 Kaya Adrian

#include "HttpRequest.h"

#include "HttpResponse.h"
#include "MercuryHttpLibrary.h"


TSharedPtr<IHttpRequest> UMercuryHttpRequest::CreateResource()
{
	const TSharedPtr<IHttpRequest>&& Request = FMercuryHttpModule::GetHttpModule()->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UMercuryHttpRequest::BindProcessRequestComplete);
	Request->OnRequestProgress().BindUObject(this, &UMercuryHttpRequest::BindRequestProgress);
	Request->OnRequestWillRetry().BindUObject(this, &UMercuryHttpRequest::BindRequestWillRetry);
	Request->OnHeaderReceived().BindUObject(this, &UMercuryHttpRequest::BindHeaderReceived);
	return Request;
}

bool UMercuryHttpRequest::HasResource() const
{
	return Resource != nullptr;
}

FString UMercuryHttpRequest::GetURL() const
{
	return HasResource() ? Resource->GetURL() : TEXT("");
}

FString UMercuryHttpRequest::GetURLParameter(const FString& ParameterName) const
{
	return HasResource() ? Resource->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpRequest::GetHeader(const FString& HeaderName) const
{
	return HasResource() ? Resource->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpRequest::GetAllHeaders() const
{
	return HasResource() ? Resource->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpRequest::GetContentType() const
{
	return HasResource() ? Resource->GetContentType() : TEXT("");
}

int32 UMercuryHttpRequest::GetContentLength() const
{
	return HasResource() ? Resource->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpRequest::GetContent() const
{
	return HasResource() ? Resource->GetContent() : TArray<uint8>();
}

FString UMercuryHttpRequest::GetVerb() const
{
	return HasResource() ? Resource->GetVerb() : TEXT("");
}

UMercuryHttpRequest* UMercuryHttpRequest::SetVerb(const FString& Verb)
{
	if (!HasResource())
		return nullptr;

	Resource->SetVerb(Verb);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetURL(const FString& URL)
{
	if (!HasResource())
		return nullptr;

	Resource->SetURL(URL);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	if (!HasResource())
		return nullptr;

	Resource->SetContent(ContentPayload);
	return this;
}
UMercuryHttpRequest* UMercuryHttpRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	if (!HasResource())
		return nullptr;

	Resource->SetContent(ContentPayload);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentAsString(const FString& ContentString)
{
	if (!HasResource())
		return nullptr;

	Resource->SetContentAsString(ContentString);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename, bool& bRequestStreamed)
{
	bRequestStreamed = SetContentAsStreamedFile(Filename);
	return bRequestStreamed ? this : nullptr;
}
bool UMercuryHttpRequest::SetContentAsStreamedFile(const FString& Filename)
{
	return HasResource() && Resource->SetContentAsStreamedFile(Filename);
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
	return HasResource() && Resource->SetContentFromStream(Stream);
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!HasResource())
		return nullptr;

	Resource->SetHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeaders(const TMap<FString, FString>& Headers)
{
	if (!HasResource())
		return nullptr;
	
	for (const TTuple<FString, FString>& Header : Headers)
	{
		SetHeader(Header.Key, Header.Value);
	}
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::AppendToHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!HasResource())
		return nullptr;

	Resource->AppendToHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetTimeout(const float InTimeoutSeconds)
{
	if (!HasResource())
		return nullptr;

	Resource->SetTimeout(InTimeoutSeconds);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::ClearTimeout()
{
	if (!HasResource())
		return nullptr;

	Resource->ClearTimeout();
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::ProcessRequest(bool& bSuccessfullyStarted)
{
	bSuccessfullyStarted = ProcessRequest();
	return bSuccessfullyStarted ? this : nullptr;
}
bool UMercuryHttpRequest::ProcessRequest() const
{
	return HasResource() && Resource->ProcessRequest();
}

UMercuryHttpRequest* UMercuryHttpRequest::CancelRequest()
{
	if (!HasResource())
		return nullptr;

	Resource->CancelRequest();
	return this;
}

UMercuryHttpResponse* UMercuryHttpRequest::GetResponse() const
{
	return Resource ? UMercuryHttpLibrary::CreateHttpResponse(Resource->GetResponse()) : nullptr;
}

EMercuryHttpRequestStatus UMercuryHttpRequest::GetStatus() const
{
	return MercuryEnums::HttpRequest::Convert(
		HasResource() ? Resource->GetStatus() : EHttpRequestStatus::Failed_ConnectionError
	);
}

float UMercuryHttpRequest::GetTimeout() const
{
	const float& DefaultTimeout = FMercuryHttpModule::GetHttpModule()->GetHttpTimeout();
	return Resource ? Resource->GetTimeout().Get(DefaultTimeout) : DefaultTimeout;
}

UMercuryHttpRequest* UMercuryHttpRequest::Tick(const float DeltaSeconds)
{
	if (!HasResource())
		return nullptr;

	Resource->Tick(DeltaSeconds);
	return this;
}

float UMercuryHttpRequest::GetElapsedTime() const
{
	return HasResource() ? Resource->GetElapsedTime() : 0.0f;
}

void UMercuryHttpRequest::BindProcessRequestComplete(
	const TSharedPtr<IHttpRequest> Request,
	const TSharedPtr<IHttpResponse> Response,
	const bool bConnectedSuccessfully
)
{
	if (OnMercuryHttpProcessRequestCompleteDelegate.IsBound())
	{
		OnMercuryHttpProcessRequestCompleteDelegate.Execute(
			UMercuryHttpLibrary::CreateHttpRequest(Request),
			UMercuryHttpLibrary::CreateHttpResponse(Response),
			bConnectedSuccessfully
		);
	}
}

void UMercuryHttpRequest::BindRequestProgress(
	const TSharedPtr<IHttpRequest> Request,
	const int32 BytesSent,
	const int32 BytesReceived
)
{
	if (OnMercuryHttpRequestProgressDelegate.IsBound())
	{
		OnMercuryHttpRequestProgressDelegate.Execute(
			UMercuryHttpLibrary::CreateHttpRequest(Request),
			BytesSent,
			BytesReceived
		);
	}
}

void UMercuryHttpRequest::BindRequestWillRetry(
	const TSharedPtr<IHttpRequest> Request,
	const TSharedPtr<IHttpResponse> Response,
	const float SecondsToRetry
)
{
	if (OnMercuryHttpRequestWillRetryDelegate.IsBound())
	{
		OnMercuryHttpRequestWillRetryDelegate.Execute(
			UMercuryHttpLibrary::CreateHttpRequest(Request),
			UMercuryHttpLibrary::CreateHttpResponse(Response),
			SecondsToRetry
		);
	}
}

void UMercuryHttpRequest::BindHeaderReceived(
	const TSharedPtr<IHttpRequest> Request,
	const FString& HeaderName,
	const FString& NewHeaderValue
)
{
	if (OnMercuryHttpHeaderReceivedDelegate.IsBound())
	{
		OnMercuryHttpHeaderReceivedDelegate.Execute(
			UMercuryHttpLibrary::CreateHttpRequest(Request),
			HeaderName,
			NewHeaderValue
		);
	}
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetProcessRequestCompleteEvent(
	const FMercuryHttpProcessRequestCompleteDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryHttpProcessRequestCompleteDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Event)
{
	if (!HasResource())
		return nullptr;

	OnMercuryHttpRequestProgressDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Event)
{
	if (!HasResource())
		return nullptr;
	
	OnMercuryHttpRequestWillRetryDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Event)
{
	if (!HasResource())
		return nullptr;

	OnMercuryHttpHeaderReceivedDelegate = Event;
	return this;
}
