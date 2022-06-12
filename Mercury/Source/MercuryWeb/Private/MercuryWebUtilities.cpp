// Copyright (c) 2022 Kaya Adrian

#include "MercuryWebUtilities.h"

#include "MercuryHttpRequest.h"
#include "MercuryHttpResponse.h"

TObjectPtr<FHttpModule> UMercuryWebUtilities::HttpModule = nullptr;


UMercuryWebUtilities::UMercuryWebUtilities(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	HttpModule = &FHttpModule::Get();
}

FHttpRequestPtr UMercuryWebUtilities::CreateRequest()
{
	check(HttpModule);
	return HttpModule->CreateRequest();
}

void UMercuryWebUtilities::RequestData(
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
			&UMercuryWebUtilities::OnHttpProcessRequestComplete,
			*ProcessRequestComplete
		);
	}
	if (RequestProgress)
	{
		Request->OnRequestProgress().BindStatic(
			&UMercuryWebUtilities::OnHttpRequestProgress,
			*RequestProgress
		);
	}
	if (RequestWillRetry)
	{
		Request->OnRequestWillRetry().BindStatic(
			&UMercuryWebUtilities::OnHttpRequestWillRetry,
			*RequestWillRetry
		);
	}
	if (HeaderReceived)
	{
		Request->OnHeaderReceived().BindStatic(
			&UMercuryWebUtilities::OnHttpHeaderReceived,
			*HeaderReceived
		);
	}
	
	Request->ProcessRequest();
}

void UMercuryWebUtilities::OnHttpProcessRequestComplete(
	const FHttpRequestPtr Request,
	const FHttpResponsePtr Response,
	const bool bConnectedSuccessfully,
	const FMercuryHttpProcessRequestCompleteDelegate MercuryHttpProcessRequestComplete
)
{
	if (!MercuryHttpProcessRequestComplete.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request.Get();

	UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
	MercuryHttpResponse->GetReference() = Response.Get();
	
	MercuryHttpProcessRequestComplete.Execute(MercuryHttpRequest, MercuryHttpResponse, bConnectedSuccessfully);
}

void UMercuryWebUtilities::OnHttpRequestProgress(
	const FHttpRequestPtr Request,
	const int32 BytesSent,
	const int32 BytesReceived,
	const FMercuryHttpRequestProgressDelegate MercuryHttpRequestProgress
)
{
	if (!MercuryHttpRequestProgress.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request.Get();
	
	MercuryHttpRequestProgress.Execute(MercuryHttpRequest, BytesSent, BytesReceived);
}

void UMercuryWebUtilities::OnHttpRequestWillRetry(
	const FHttpRequestPtr Request,
	const FHttpResponsePtr Response,
	const float SecondsToRetry,
	const FMercuryHttpRequestWillRetryDelegate MercuryHttpRequestWillRetry
)
{
	if (!MercuryHttpRequestWillRetry.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request.Get();

	UMercuryHttpResponse* const& MercuryHttpResponse = NewObject<UMercuryHttpResponse>();
	MercuryHttpResponse->GetReference() = Response.Get();
	
	MercuryHttpRequestWillRetry.Execute(MercuryHttpRequest, MercuryHttpResponse, SecondsToRetry);
}

void UMercuryWebUtilities::OnHttpHeaderReceived(
	const FHttpRequestPtr Request,
	const FString& HeaderName,
	const FString& NewHeaderValue,
	const FMercuryHttpHeaderReceivedDelegate MercuryHttpHeaderReceived
)
{
	if (!MercuryHttpHeaderReceived.IsBound())
		return;
	
	UMercuryHttpRequest* const& MercuryHttpRequest = NewObject<UMercuryHttpRequest>();
	MercuryHttpRequest->GetReference() = Request.Get();
	
	MercuryHttpHeaderReceived.Execute(MercuryHttpRequest, HeaderName, NewHeaderValue);
}

void UMercuryWebUtilities::K2_RequestDataWithPayload(
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
void UMercuryWebUtilities::RequestDataWithPayload(
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
	const FHttpRequestPtr& Request = CreateRequest();
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

void UMercuryWebUtilities::K2_RequestDataWithStringContent(
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
void UMercuryWebUtilities::RequestDataWithStringContent(
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
	const FHttpRequestPtr& Request = CreateRequest();
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

void UMercuryWebUtilities::K2_RequestDataWithStreamedFile(
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
void UMercuryWebUtilities::RequestDataWithStreamedFile(
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
	const FHttpRequestPtr& Request = CreateRequest();
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
