// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpModule.h"
#include "MercuryResponse.h"
#include "MercuryRequest.h"

#include "MercurySubsystem.generated.h"


DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryRequestCompleteDelegate,
	UMercuryRequest* const&, Request,
	UMercuryResponse* const&, Response,
	bool, bConnectedSuccessfully
);

UCLASS()
class MERCURY_API UMercurySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	static TObjectPtr<FHttpModule> HttpModule;

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	void OnHttpProcessRequestComplete(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bConnectedSuccessfully,
		FMercuryRequestCompleteDelegate OnMercuryRequestComplete
	);

public:
	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
	void RequestHttpData(
		const FString& URL,
		const FString& Verb,
		const TMap<FString, FString>& Headers,
		const FString& Content,
		const FMercuryRequestCompleteDelegate& OnMercuryRequestComplete
	);
};
