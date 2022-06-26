﻿// Copyright (c) 2022 Kaya Adrian

#include "MercuryHttpLibrary.h"

#include "MercuryHttp.h"
#include "MercuryHttpRequest.h"


void UMercuryHttpLibrary::RequestDataWithPayload(
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

void UMercuryHttpLibrary::RequestDataWithStringContent(
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

void UMercuryHttpLibrary::RequestDataFromStream(
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

void UMercuryHttpLibrary::RequestDataWithStreamedFile(
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

void UMercuryHttpLibrary::RequestData(
	UMercuryHttpRequest* const Request,
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
	
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogMercuryHttp, Error, TEXT("Failed to request data: Could not process the request!"));
	}
}

void UMercuryHttpLibrary::K2_RequestDataWithPayload(
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

void UMercuryHttpLibrary::K2_RequestDataWithStringContent(
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

void UMercuryHttpLibrary::K2_RequestDataWithStreamedFile(
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