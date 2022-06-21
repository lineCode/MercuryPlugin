// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"

#include "ProcessRequestAsyncAction.generated.h"

class UMercuryHttpRequest;


UDELEGATE(BlueprintCallable, DisplayName = "Process Request Async Pin")
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProcessRequestAsyncPin);

UCLASS(Blueprintable, BlueprintType, DisplayName = "Process Request Async Action")
class MERCURYWEB_API UProcessRequestAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, DisplayName = "Process Request Complete", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FProcessRequestAsyncPin OnProcessRequestCompletePin;

	UPROPERTY(BlueprintAssignable, DisplayName = "Request Progress", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FProcessRequestAsyncPin OnRequestProgressPin;

	UPROPERTY(BlueprintAssignable, DisplayName = "Request Will Retry", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FProcessRequestAsyncPin OnRequestWillRetryPin;

	UPROPERTY(BlueprintAssignable, DisplayName = "Header Received", Category = "Output", meta = (
		AllowPrivateAccess = "true"
	))
	FProcessRequestAsyncPin OnHeaderReceivedPin;

	UPROPERTY(BlueprintReadOnly, DisplayName = "World Context", Category = "Internal|Context", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<const UObject> WorldContext;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Mercury HTTP Request", Category = "Internal|Context", meta = (
		AllowPrivateAccess = "true"
	))
	TObjectPtr<const UMercuryHttpRequest> Request;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Process Request Complete Timer", Category = "Internal|Timer", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle ProcessRequestCompleteTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Progress Timer", Category = "Internal|Timer", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle RequestProgressTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Request Will Retry Timer", Category = "Internal|Timer", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle RequestWillRetryTimer;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Header Received Timer", Category = "Internal|Timer", meta = (
		AllowPrivateAccess = "true"
	))
	FTimerHandle HeaderReceivedTimer;

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Process Request Async", Category = "HTTP|Request", meta = (
		BlueprintInternalUseOnly = "true",
		Keywords = "Mercury HTTP Process Request Async World Context Object",
		WorldContext = "WorldContextObject"
	))
	static UProcessRequestAsyncAction* ProcessRequestAsync(
		const UObject* WorldContextObject,
		const UMercuryHttpRequest* const& MercuryRequest
	);

protected:
	virtual void Activate() override;

public:
	FORCEINLINE FProcessRequestAsyncPin& OnProcessRequestComplete() { return OnProcessRequestCompletePin; }
	FORCEINLINE const FProcessRequestAsyncPin& OnProcessRequestComplete() const { return OnProcessRequestCompletePin;}

	FORCEINLINE FProcessRequestAsyncPin& OnRequestProgress() { return OnRequestProgressPin; }
	FORCEINLINE const FProcessRequestAsyncPin& OnRequestProgress() const { return OnRequestProgressPin; }

	FORCEINLINE FProcessRequestAsyncPin& OnRequestWillRetry() { return OnRequestWillRetryPin; }
	FORCEINLINE const FProcessRequestAsyncPin& OnRequestWillRetry() const { return OnRequestWillRetryPin; }
	
	FORCEINLINE FProcessRequestAsyncPin& OnHeaderReceived() { return OnHeaderReceivedPin; }
	FORCEINLINE const FProcessRequestAsyncPin& OnHeaderReceived() const { return OnHeaderReceivedPin; }
	
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
