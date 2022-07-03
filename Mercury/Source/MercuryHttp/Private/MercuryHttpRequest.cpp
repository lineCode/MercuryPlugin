// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpRequest.h"

#include "Interfaces/IHttpRequest.h"
#include "MercuryHttp.h"
#include "MercuryHttpResponse.h"


UMercuryHttpRequest::UMercuryHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Resource = FMercuryHttpModule::GetHttpModule()->CreateRequest();
	MercuryHttpResponse = CreateDefaultSubobject<UMercuryHttpResponse>(TEXT("Mercury HTTP Response"));
	
	Resource->OnProcessRequestComplete().BindUObject(this, &UMercuryHttpRequest::BindProcessRequestComplete);
	Resource->OnRequestProgress().BindUObject(this, &UMercuryHttpRequest::BindRequestProgress);
	Resource->OnRequestWillRetry().BindUObject(this, &UMercuryHttpRequest::BindRequestWillRetry);
	Resource->OnHeaderReceived().BindUObject(this, &UMercuryHttpRequest::BindHeaderReceived);

	bProcessRequestCompleteDone = false;
	bRequestProgressDone = false;
	bRequestWillRetryDone = false;
	bHeaderReceivedDone = false;
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

EMercuryHttpRequestStatus UMercuryHttpRequest::GetMercuryHttpStatus() const
{
	if (!Resource)
		return EMercuryHttpRequestStatus::Unknown;
	
	switch (const EHttpRequestStatus::Type&& Status = Resource->GetStatus())
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
		UE_LOG(LogMercuryHttp, Error, TEXT("Unknown request status: %d"), Status);
		return EMercuryHttpRequestStatus::Unknown;
	}
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
	
	UMercuryHttpRequest* const&& MercuryRequest = NewObject<UMercuryHttpRequest>();
	MercuryRequest->GetResource() = Request;

	UMercuryHttpResponse* const&& MercuryResponse = NewObject<UMercuryHttpResponse>();
	MercuryResponse->GetResource() = Response;
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
	
	UMercuryHttpRequest* const&& MercuryRequest = NewObject<UMercuryHttpRequest>();
	MercuryRequest->GetResource() = Request;
	
	OnMercuryHttpRequestProgressDelegate.Execute(MercuryRequest, BytesSent, BytesReceived);
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
	
	UMercuryHttpRequest* const&& MercuryRequest = NewObject<UMercuryHttpRequest>();
	MercuryRequest->GetResource() = Request;

	UMercuryHttpResponse* const&& MercuryResponse = NewObject<UMercuryHttpResponse>();
	MercuryResponse->GetResource() = Response;
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
	
	UMercuryHttpRequest* const&& MercuryRequest = NewObject<UMercuryHttpRequest>();
	MercuryRequest->GetResource() = Request;
	
	OnMercuryHttpHeaderReceivedDelegate.Execute(MercuryRequest, HeaderName, NewHeaderValue);
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
