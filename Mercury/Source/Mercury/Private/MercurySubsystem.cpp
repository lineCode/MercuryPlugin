// Copyright (c) 2022 Kaya Adrian

#include "MercurySubsystem.h"

#include "Mercury.h"


TObjectPtr<FHttpModule> UMercurySubsystem::HttpModule;

void UMercurySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	HttpModule = &FHttpModule::Get();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void UMercurySubsystem::OnHttpProcessRequestComplete(
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
		
	UE_LOG(LogMercury, Display, TEXT("Mercury request complete! Executing event..."));
	OnMercuryRequestComplete.Execute(MercuryRequest, MercuryResponse, bConnectedSuccessfully);
	UE_LOG(LogMercury, Display, TEXT("Event finished executing!"));
}

// ReSharper disable once CppUE4BlueprintCallableFunctionMayBeConst
void UMercurySubsystem::RequestHttpData(
	const FString& URL,
	const FString& Verb,
	const TMap<FString, FString>& Headers,
	const FString& Content,
	const FMercuryRequestCompleteDelegate& OnMercuryRequestComplete
)
{
	const FHttpRequestPtr& Request = HttpModule->CreateRequest();
	
	Request->SetURL(URL);
	Request->SetVerb(Verb);
	Request->SetContentAsString(Content);
	for (const TTuple<FString, FString>& Header : Headers)
	{
		Request->SetHeader(Header.Key, Header.Value);
	}

	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UMercurySubsystem::OnHttpProcessRequestComplete,
		OnMercuryRequestComplete
	);
	Request->ProcessRequest();
}
