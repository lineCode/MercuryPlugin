// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "HttpProcessRequestAsyncAction.generated.h"

class UMercuryHttpRequest;


UDELEGATE(BlueprintCallable, DisplayName = "Process Request Async Pin")
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMercuryHttpProcessRequestAsyncPin);

UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury HTTP Process Request Async Action")
class MERCURYHTTP_API UMercuryHttpProcessRequestAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, DisplayName = "On Process Request Complete", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestAsyncPin OnProcessRequestCompletePin;

	UPROPERTY(BlueprintAssignable, DisplayName = "On Request Progress", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestAsyncPin OnRequestProgressPin;

	UPROPERTY(BlueprintAssignable, DisplayName = "On Request Will Retry", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestAsyncPin OnRequestWillRetryPin;

	UPROPERTY(BlueprintAssignable, DisplayName = "On Header Received", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryHttpProcessRequestAsyncPin OnHeaderReceivedPin;

	UPROPERTY(BlueprintReadOnly, DisplayName = "World Context", Category = "Internal|Context", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<const UObject> WorldContext;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Mercury HTTP Request", Category = "Internal|Context", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<const UMercuryHttpRequest> Request;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Process Request Complete Timer", Category = "Internal|Timers", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle ProcessRequestCompleteTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Progress Timer", Category = "Internal|Timers", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle RequestProgressTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Will Retry Timer", Category = "Internal|Timers", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle RequestWillRetryTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Header Received Timer", Category = "Internal|Timers", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle HeaderReceivedTimer;

public:
	explicit UMercuryHttpProcessRequestAsyncAction(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, DisplayName = "HTTP Process Request Async", Category = "HTTP|Request", meta = (
		BlueprintInternalUseOnly = "true",
		Keywords = "Mercury HTTP Process Request Async World Context Object",
		WorldContext = "WorldContextObject"
	))
	static UMercuryHttpProcessRequestAsyncAction* HttpProcessRequestAsync(
		const UObject* WorldContextObject,
		const UMercuryHttpRequest* const& MercuryRequest
	);

protected:
	virtual void Activate() override;

public:
	FORCEINLINE FMercuryHttpProcessRequestAsyncPin& OnProcessRequestComplete() { return OnProcessRequestCompletePin; }
	FORCEINLINE const FMercuryHttpProcessRequestAsyncPin& OnProcessRequestComplete() const
	{
		return OnProcessRequestCompletePin;
	}

	FORCEINLINE FMercuryHttpProcessRequestAsyncPin& OnRequestProgress() { return OnRequestProgressPin; }
	FORCEINLINE const FMercuryHttpProcessRequestAsyncPin& OnRequestProgress() const { return OnRequestProgressPin; }

	FORCEINLINE FMercuryHttpProcessRequestAsyncPin& OnRequestWillRetry() { return OnRequestWillRetryPin; }
	FORCEINLINE const FMercuryHttpProcessRequestAsyncPin& OnRequestWillRetry() const { return OnRequestWillRetryPin; }
	
	FORCEINLINE FMercuryHttpProcessRequestAsyncPin& OnHeaderReceived() { return OnHeaderReceivedPin; }
	FORCEINLINE const FMercuryHttpProcessRequestAsyncPin& OnHeaderReceived() const { return OnHeaderReceivedPin; }
	
	FORCEINLINE TObjectPtr<const UObject>& GetWorldContext() { return WorldContext; }
	FORCEINLINE const TObjectPtr<const UObject>& GetWorldContext() const { return WorldContext; }

	FORCEINLINE TObjectPtr<const UMercuryHttpRequest>& GetRequest() { return Request; }
	FORCEINLINE const TObjectPtr<const UMercuryHttpRequest>& GetRequest() const { return Request; }

	FORCEINLINE FTimerHandle& GetProcessRequestCompleteTimer() { return ProcessRequestCompleteTimer; }
	FORCEINLINE const FTimerHandle& GetProcessRequestCompleteTimer() const { return ProcessRequestCompleteTimer; }

	FORCEINLINE FTimerHandle& GetRequestProgressTimer() { return RequestProgressTimer; }
	FORCEINLINE const FTimerHandle& GetRequestProgressTimer() const { return RequestProgressTimer; }

	FORCEINLINE FTimerHandle& GetRequestWillRetryTimer() { return RequestWillRetryTimer; }
	FORCEINLINE const FTimerHandle& GetRequestWillRetryTimer() const { return RequestWillRetryTimer; }

	FORCEINLINE FTimerHandle& GetHeaderReceivedTimer() { return HeaderReceivedTimer; }
	FORCEINLINE const FTimerHandle& GetHeaderReceivedTimer() const { return HeaderReceivedTimer; }
};
