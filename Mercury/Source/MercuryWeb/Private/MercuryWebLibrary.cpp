// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebLibrary.h"

#include "HttpModule.h"
#include "MercuryHttpRequest.h"
#include "MercuryHttpResponse.h"


void UMercuryWebLibrary::RequestDataWithPayload(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const TArray<uint8>& ContentPayload,
	const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
)
{
	UMercuryHttpRequest* const& Request = NewObject<UMercuryHttpRequest>();
	Request->SetContent(ContentPayload);
	RequestData(
		Request->GetReference(),
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

void UMercuryWebLibrary::RequestDataWithStringContent(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Content,
	const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
)
{
	UMercuryHttpRequest* const& Request = NewObject<UMercuryHttpRequest>();
	Request->SetContentAsString(Content);
	RequestData(
		Request->GetReference(),
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

void UMercuryWebLibrary::RequestDataFromStream(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const TSharedRef<FArchive, ESPMode::ThreadSafe>& Stream,
	const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
)
{
	UMercuryHttpRequest* const& Request = NewObject<UMercuryHttpRequest>();
	Request->SetContentFromStream(Stream);
	RequestData(
		Request->GetReference(),
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

void UMercuryWebLibrary::RequestDataWithStreamedFile(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Filename,
	const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
)
{
	UMercuryHttpRequest* const& Request = NewObject<UMercuryHttpRequest>();
	Request->SetContentAsStreamedFile(Filename);
	RequestData(
		Request->GetReference(),
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

void UMercuryWebLibrary::RequestData(
	const FHttpRequestPtr& Request,
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FMercuryHttpProcessRequestCompleteDelegate* const& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate* const& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate* const& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate* const& HeaderReceived
)
{
	Request->SetURL(URL);
	Request->SetVerb(Verb);
	for (const TTuple<FString, FString>& Header : Headers)
	{
		Request->SetHeader(Header.Key, Header.Value);
	}

	if (ProcessRequestComplete)
	{
		Request->OnProcessRequestComplete().BindStatic(
			&UMercuryWebLibrary::OnMercuryHttpProcessRequestComplete,
			*ProcessRequestComplete
		);
	}
	if (RequestProgress)
	{
		Request->OnRequestProgress().BindStatic(
			&UMercuryWebLibrary::OnMercuryHttpRequestProgress,
			*RequestProgress
		);
	}
	if (RequestWillRetry)
	{
		Request->OnRequestWillRetry().BindStatic(
			&UMercuryWebLibrary::OnMercuryHttpRequestWillRetry,
			*RequestWillRetry
		);
	}
	if (HeaderReceived)
	{
		Request->OnHeaderReceived().BindStatic(
			&UMercuryWebLibrary::OnMercuryHttpHeaderReceived,
			*HeaderReceived
		);
	}
	
	Request->ProcessRequest();
}

void UMercuryWebLibrary::OnMercuryHttpProcessRequestComplete(
	const FHttpRequestPtr Request,
	const FHttpResponsePtr Response,
	const bool bConnectedSuccessfully,
	const FMercuryHttpProcessRequestCompleteDelegate OnMercuryHttpProcessRequestComplete
)
{
	if (!OnMercuryHttpProcessRequestComplete.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request;

	UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
	MercuryHttpResponse->GetReference() = Response;
	MercuryHttpRequest->GetMercuryHttpResponse() = MercuryHttpResponse;
	
	OnMercuryHttpProcessRequestComplete.Execute(MercuryHttpRequest, MercuryHttpResponse, bConnectedSuccessfully);
}

void UMercuryWebLibrary::OnMercuryHttpRequestProgress(
	const FHttpRequestPtr Request,
	const int32 BytesSent,
	const int32 BytesReceived,
	const FMercuryHttpRequestProgressDelegate OnMercuryHttpRequestProgress
)
{
	if (!OnMercuryHttpRequestProgress.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request;
	
	OnMercuryHttpRequestProgress.Execute(MercuryHttpRequest, BytesSent, BytesReceived);
}

void UMercuryWebLibrary::OnMercuryHttpRequestWillRetry(
	const FHttpRequestPtr Request,
	const FHttpResponsePtr Response,
	const float SecondsToRetry,
	const FMercuryHttpRequestWillRetryDelegate OnMercuryHttpRequestWillRetry
)
{
	if (!OnMercuryHttpRequestWillRetry.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request;

	UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
	MercuryHttpResponse->GetReference() = Response;
	MercuryHttpRequest->GetMercuryHttpResponse() = MercuryHttpResponse;
	
	OnMercuryHttpRequestWillRetry.Execute(MercuryHttpRequest, MercuryHttpResponse, SecondsToRetry);
}

void UMercuryWebLibrary::OnMercuryHttpHeaderReceived(
	const FHttpRequestPtr Request,
	const FString& HeaderName,
	const FString& NewHeaderValue,
	const FMercuryHttpHeaderReceivedDelegate OnMercuryHttpHeaderReceived
)
{
	if (!OnMercuryHttpHeaderReceived.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request;
	
	OnMercuryHttpHeaderReceived.Execute(MercuryHttpRequest, HeaderName, NewHeaderValue);
}

void UMercuryWebLibrary::K2_RequestDataWithPayload(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const TArray<uint8>& ContentPayload,
	const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
)
{
	RequestDataWithPayload(
		URL,
		Verb,
		Headers,
		ContentPayload,
		&ProcessRequestComplete,
		&RequestProgress,
		&RequestWillRetry,
		&HeaderReceived
	);
}

void UMercuryWebLibrary::K2_RequestDataWithStringContent(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Content,
	const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
)
{
	RequestDataWithStringContent(
		URL,
		Verb,
		Headers,
		Content,
		&ProcessRequestComplete,
		&RequestProgress,
		&RequestWillRetry,
		&HeaderReceived
	);
}

void UMercuryWebLibrary::K2_RequestDataWithStreamedFile(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Filename,
	const FMercuryHttpProcessRequestCompleteDelegate& ProcessRequestComplete,
	const FMercuryHttpRequestProgressDelegate& RequestProgress,
	const FMercuryHttpRequestWillRetryDelegate& RequestWillRetry,
	const FMercuryHttpHeaderReceivedDelegate& HeaderReceived
)
{
	RequestDataWithStreamedFile(
		URL,
		Verb,
		Headers,
		Filename,
		&ProcessRequestComplete,
		&RequestProgress,
		&RequestWillRetry,
		&HeaderReceived
	);
}
