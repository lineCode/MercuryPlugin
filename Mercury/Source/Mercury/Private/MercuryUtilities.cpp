// Copyright (c) 2022 Kaya Adrian

#include "MercuryUtilities.h"

#include "MercuryRequest.h"
#include "MercuryResponse.h"

TObjectPtr<FHttpModule> UMercuryUtilities::HttpModule = nullptr;


UMercuryUtilities::UMercuryUtilities(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	HttpModule = &FHttpModule::Get();
}

void UMercuryUtilities::RequestData(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Content,
	const FMercuryRequestCompleteDelegate& OnMercuryRequestComplete
)
{
	check(HttpModule);
	const FHttpRequestPtr& Request = HttpModule->CreateRequest();
	
	Request->SetURL(URL);
	Request->SetVerb(Verb);
	Request->SetContentAsString(Content);
	for (const TTuple<FString, FString>& Header : Headers)
	{
		Request->SetHeader(Header.Key, Header.Value);
	}
	
	Request->OnProcessRequestComplete().BindStatic(
		&UMercuryUtilities::OnHttpProcessRequestComplete,
		OnMercuryRequestComplete
	);
	Request->ProcessRequest();
}

void UMercuryUtilities::OnHttpProcessRequestComplete(
	const FHttpRequestPtr Request,
	const FHttpResponsePtr Response,
	const bool bConnectedSuccessfully,
	const FMercuryRequestCompleteDelegate OnMercuryRequestComplete
)
{
	UMercuryRequest* const& MercuryRequest = NewObject<UMercuryRequest>();
	MercuryRequest->GetReference() = Request.Get();

	UMercuryResponse* const& MercuryResponse = NewObject<UMercuryResponse>();
	MercuryResponse->GetReference() = Response.Get();
	
	OnMercuryRequestComplete.ExecuteIfBound(MercuryRequest, MercuryResponse, bConnectedSuccessfully);
}
