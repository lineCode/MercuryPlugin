// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpRequest.h"

#include "MercuryHttpLibrary.h"
#include "MercuryHttpResponse.h"


TSharedPtr<IHttpRequest> UMercuryHttpRequest::CreateResource()
{
	const TSharedPtr<IHttpRequest>&& Request = FMercuryHttpModule::GetHttpModule()->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UMercuryHttpRequest::BindProcessRequestComplete);
	Request->OnRequestProgress().BindUObject(this, &UMercuryHttpRequest::BindRequestProgress);
	Request->OnRequestWillRetry().BindUObject(this, &UMercuryHttpRequest::BindRequestWillRetry);
	Request->OnHeaderReceived().BindUObject(this, &UMercuryHttpRequest::BindHeaderReceived);
	return Request;
}
UMercuryHttpRequest::UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MercuryHttpResponse = UMercuryHttpLibrary::CreateHttpResponse();

	bProcessRequestCompleteDone = false;
	bRequestProgressDone = false;
	bRequestWillRetryDone = false;
	bHeaderReceivedDone = false;
}

bool UMercuryHttpRequest::HasResource() const
{
	return Resource != nullptr;
}

FString UMercuryHttpRequest::GetURL() const
{
	return Resource ? Resource->GetURL() : TEXT("");
}

FString UMercuryHttpRequest::GetURLParameter(const FString& ParameterName) const
{
	return Resource ? Resource->GetURLParameter(ParameterName) : TEXT("");
}

FString UMercuryHttpRequest::GetHeader(const FString& HeaderName) const
{
	return Resource ? Resource->GetHeader(HeaderName) : TEXT("");
}

TArray<FString> UMercuryHttpRequest::GetAllHeaders() const
{
	return Resource ? Resource->GetAllHeaders() : TArray<FString>();
}

FString UMercuryHttpRequest::GetContentType() const
{
	return Resource ? Resource->GetContentType() : TEXT("");
}

int32 UMercuryHttpRequest::GetContentLength() const
{
	return Resource ? Resource->GetContentLength() : 0;
}

TArray<uint8> UMercuryHttpRequest::GetContent() const
{
	return Resource ? Resource->GetContent() : TArray<uint8>();
}

FString UMercuryHttpRequest::GetVerb() const
{
	return Resource ? Resource->GetVerb() : TEXT("");
}

UMercuryHttpRequest* UMercuryHttpRequest::SetVerb(const FString& Verb)
{
	if (!Resource)
		return nullptr;

	Resource->SetVerb(Verb);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetURL(const FString& URL)
{
	if (!Resource)
		return nullptr;

	Resource->SetURL(URL);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContent(const TArray<uint8>& ContentPayload)
{
	if (!Resource)
		return nullptr;

	Resource->SetContent(ContentPayload);
	return this;
}
UMercuryHttpRequest* UMercuryHttpRequest::SetContent(TArray<uint8>&& ContentPayload)
{
	if (!Resource)
		return nullptr;

	Resource->SetContent(ContentPayload);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetContentAsString(const FString& ContentString)
{
	if (!Resource)
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
	return Resource && Resource->SetContentAsStreamedFile(Filename);
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
	return Resource && Resource->SetContentFromStream(Stream);
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!Resource)
		return nullptr;

	Resource->SetHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetHeaders(const TMap<FString, FString>& Headers)
{
	if (!Resource)
		return nullptr;
	
	for (const TTuple<FString, FString>& Header : Headers)
	{
		SetHeader(Header.Key, Header.Value);
	}
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::AppendToHeader(const FString& HeaderName, const FString& HeaderValue)
{
	if (!Resource)
		return nullptr;

	Resource->AppendToHeader(HeaderName, HeaderValue);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::SetTimeout(const float InTimeoutSeconds)
{
	if (!Resource)
		return nullptr;

	Resource->SetTimeout(InTimeoutSeconds);
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::ClearTimeout()
{
	if (!Resource)
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
	return Resource && Resource->ProcessRequest();
}

UMercuryHttpRequest* UMercuryHttpRequest::CancelRequest()
{
	if (!Resource)
		return nullptr;

	Resource->CancelRequest();
	return this;
}

EMercuryHttpRequestStatus UMercuryHttpRequest::GetStatus() const
{
	return MercuryEnums::HttpRequest::Convert(
		Resource ? Resource->GetStatus() : EHttpRequestStatus::Failed_ConnectionError
	);
}

UMercuryHttpRequest* UMercuryHttpRequest::Tick(const float DeltaSeconds)
{
	if (!Resource)
		return nullptr;

	Resource->Tick(DeltaSeconds);
	return this;
}

float UMercuryHttpRequest::GetElapsedTime() const
{
	return Resource ? Resource->GetElapsedTime() : 0.0f;
}

void UMercuryHttpRequest::BindProcessRequestComplete(
	const TSharedPtr<IHttpRequest> Request,
	const TSharedPtr<IHttpResponse> Response,
	const bool bConnectedSuccessfully
)
{
	bProcessRequestCompleteDone = false;
	if (!OnMercuryHttpProcessRequestCompleteDelegate.IsBound())
	{
		bProcessRequestCompleteDone = true;
		return;
	}
	
	UMercuryHttpRequest* const&& MercuryRequest = UMercuryHttpLibrary::CreateHttpRequest(Request);
	UMercuryHttpResponse* const&& MercuryResponse = UMercuryHttpLibrary::CreateHttpResponse(Response);
	MercuryRequest->GetMercuryHttpResponse() = MercuryResponse;
	
	OnMercuryHttpProcessRequestCompleteDelegate.Execute(MercuryRequest, MercuryResponse, bConnectedSuccessfully);
	bProcessRequestCompleteDone = true;
}

void UMercuryHttpRequest::BindRequestProgress(
	const TSharedPtr<IHttpRequest> Request,
	const int32 BytesSent,
	const int32 BytesReceived
)
{
	bRequestProgressDone = false;
	if (!OnMercuryHttpRequestProgressDelegate.IsBound())
	{
		bRequestProgressDone = true;
		return;
	}
	
	OnMercuryHttpRequestProgressDelegate.Execute(
		UMercuryHttpLibrary::CreateHttpRequest(Request),
		BytesSent,
		BytesReceived
	);
	bRequestProgressDone = true;
}

void UMercuryHttpRequest::BindRequestWillRetry(
	const TSharedPtr<IHttpRequest> Request,
	const TSharedPtr<IHttpResponse> Response,
	const float SecondsToRetry
)
{
	bRequestWillRetryDone = false;
	if (!OnMercuryHttpRequestWillRetryDelegate.IsBound())
	{
		bRequestWillRetryDone = true;
		return;
	}
	
	UMercuryHttpRequest* const&& MercuryRequest = UMercuryHttpLibrary::CreateHttpRequest(Request);
	UMercuryHttpResponse* const&& MercuryResponse = UMercuryHttpLibrary::CreateHttpResponse(Response);
	MercuryRequest->GetMercuryHttpResponse() = MercuryResponse;
	
	OnMercuryHttpRequestWillRetryDelegate.Execute(MercuryRequest, MercuryResponse, SecondsToRetry);
	bRequestWillRetryDone = true;
}

void UMercuryHttpRequest::BindHeaderReceived(
	const TSharedPtr<IHttpRequest> Request,
	const FString& HeaderName,
	const FString& NewHeaderValue
)
{
	bHeaderReceivedDone = false;
	if (!OnMercuryHttpHeaderReceivedDelegate.IsBound())
	{
		bHeaderReceivedDone = true;
		return;
	}
	
	OnMercuryHttpHeaderReceivedDelegate.Execute(
		UMercuryHttpLibrary::CreateHttpRequest(Request),
		HeaderName,
		NewHeaderValue
	);
	bHeaderReceivedDone = true;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetProcessRequestCompleteEvent(
	const FMercuryHttpProcessRequestCompleteDelegate& Event
)
{
	if (!Resource)
		return nullptr;

	OnMercuryHttpProcessRequestCompleteDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestProgressEvent(const FMercuryHttpRequestProgressDelegate& Event)
{
	if (!Resource)
		return nullptr;

	OnMercuryHttpRequestProgressDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetRequestWillRetryEvent(const FMercuryHttpRequestWillRetryDelegate& Event)
{
	if (!Resource)
		return nullptr;

	OnMercuryHttpRequestWillRetryDelegate = Event;
	return this;
}

UMercuryHttpRequest* UMercuryHttpRequest::K2_SetHeaderReceivedEvent(const FMercuryHttpHeaderReceivedDelegate& Event)
{
	if (!Resource)
		return nullptr;

	OnMercuryHttpHeaderReceivedDelegate = Event;
	return this;
}
