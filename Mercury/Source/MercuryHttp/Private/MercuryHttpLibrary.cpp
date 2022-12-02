// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpLibrary.h"


UMercuryHttpRequest* UMercuryHttpLibrary::CreateHttpRequest()
{
	return CreateHttpRequest(nullptr);
}
UMercuryHttpRequest* UMercuryHttpLibrary::CreateHttpRequest(IHttpRequest* const& Resource)
{
	return CreateHttpRequest(MakeShareable(Resource));
}
UMercuryHttpRequest* UMercuryHttpLibrary::CreateHttpRequest(const TSharedPtr<IHttpRequest>& Resource)
{
	UMercuryHttpRequest* const&& HttpRequest = NewObject<UMercuryHttpRequest>();
	HttpRequest->SetResource(Resource ? Resource : HttpRequest->CreateResource());
	return HttpRequest;
}

UMercuryHttpResponse* UMercuryHttpLibrary::CreateHttpResponse()
{
	return CreateHttpResponse(nullptr);
}
UMercuryHttpResponse* UMercuryHttpLibrary::CreateHttpResponse(IHttpResponse* const& Resource)
{
	return CreateHttpResponse(MakeShareable(Resource));
}
UMercuryHttpResponse* UMercuryHttpLibrary::CreateHttpResponse(const TSharedPtr<IHttpResponse>& Resource)
{
	UMercuryHttpResponse* const&& HttpResponse = NewObject<UMercuryHttpResponse>();
	HttpResponse->SetResource(Resource ? Resource : HttpResponse->CreateResource());
	return HttpResponse;
}

bool UMercuryHttpLibrary::RequestDataWithPayload(
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
	UMercuryHttpRequest* const&& Request = CreateHttpRequest();
	Request->SetContent(ContentPayload);
	return RequestData(
		Request,
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

bool UMercuryHttpLibrary::RequestDataWithStringContent(
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
	UMercuryHttpRequest* const&& Request = CreateHttpRequest();
	Request->SetContentAsString(Content);
	return RequestData(
		Request,
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

bool UMercuryHttpLibrary::RequestDataFromStream(
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
	UMercuryHttpRequest* const&& Request = CreateHttpRequest();
	Request->SetContentFromStream(Stream);
	return RequestData(
		Request,
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

bool UMercuryHttpLibrary::RequestDataWithStreamedFile(
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
	UMercuryHttpRequest* const&& Request = CreateHttpRequest();
	Request->SetContentAsStreamedFile(Filename);
	return RequestData(
		Request,
		URL,
		Verb,
		Headers,
		ProcessRequestComplete,
		RequestProgress,
		RequestWillRetry,
		HeaderReceived
	);
}

bool UMercuryHttpLibrary::RequestData(
	UMercuryHttpRequest* const& Request,
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
		Request->OnProcessRequestComplete() = *ProcessRequestComplete;
	}
	if (RequestProgress)
	{
		Request->OnRequestProgress() = *RequestProgress;
	}
	if (RequestWillRetry)
	{
		Request->OnRequestWillRetry() = *RequestWillRetry;
	}
	if (HeaderReceived)
	{
		Request->OnHeaderReceived() = *HeaderReceived;
	}
	
	return Request->ProcessRequest();
}

bool UMercuryHttpLibrary::K2_RequestDataWithPayload(
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
	return RequestDataWithPayload(
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

bool UMercuryHttpLibrary::K2_RequestDataWithStringContent(
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
	return RequestDataWithStringContent(
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

bool UMercuryHttpLibrary::K2_RequestDataWithStreamedFile(
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
	return RequestDataWithStreamedFile(
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
