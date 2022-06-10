// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"
#include "MercuryTypes.h"

#include "MercuryUtilities.generated.h"


UCLASS(Abstract)
class MERCURY_API UMercuryUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static TObjectPtr<FHttpModule> HttpModule;

public:
	explicit UMercuryUtilities(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, Category = "Mercury | HTTP", meta = (
		Keywords = "Request Data HTTP Response URL JSON"
	))
	static void RequestData(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryRequestCompleteDelegate& OnMercuryRequestComplete
	);

private:
	static void OnHttpProcessRequestComplete(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully,
		FMercuryRequestCompleteDelegate OnMercuryRequestComplete
	);
};
