// Copyright (c) 2022 Kaya Adrian

#include "ProcessRequestAsyncAction.h"

#include "MercuryHttpRequest.h"


UProcessRequestAsyncAction::UProcessRequestAsyncAction(
	const FObjectInitializer& ObjectInitializer
) : Super(ObjectInitializer)
{
	OnProcessRequestCompletePin = FProcessRequestAsyncPin();
	OnRequestProgressPin = FProcessRequestAsyncPin();
	OnRequestWillRetryPin = FProcessRequestAsyncPin();
	OnHeaderReceivedPin = FProcessRequestAsyncPin();

	WorldContext = nullptr;
	Request = nullptr;
}

UProcessRequestAsyncAction* UProcessRequestAsyncAction::ProcessRequestAsync(
	const UObject* WorldContextObject,
	const UMercuryHttpRequest* const& MercuryRequest
)
{
	UProcessRequestAsyncAction* const& AsyncAction = NewObject<UProcessRequestAsyncAction>();
	AsyncAction->GetWorldContext() = WorldContextObject;
	AsyncAction->GetRequest() = MercuryRequest;
	return AsyncAction;
}

void UProcessRequestAsyncAction::Activate()
{
	if (!WorldContext)
	{
		FFrame::KismetExecutionMessage(
			TEXT("Unable to execute HTTP request: Invalid WorldContextObject"),
			ELogVerbosity::Error
		);
		return;
	}

	if (!Request)
	{
		FFrame::KismetExecutionMessage(
			TEXT("Unable to execute HTTP request: Invalid MercuryRequest"),
			ELogVerbosity::Error
		);
		return;
	}

	if (!Request->ProcessRequest())
	{
		FFrame::KismetExecutionMessage(TEXT("Unable to execute HTTP request: Request failed"), ELogVerbosity::Warning);
		return;
	}
	
	FTimerManager& TimerManager = WorldContext->GetWorld()->GetTimerManager();
	
	TimerManager.SetTimer(
		ProcessRequestCompleteTimer,
		[this, &TimerManager]
		{
			if (!Request->IsProcessRequestCompleteDone())
				return;

			TimerManager.ClearTimer(ProcessRequestCompleteTimer);
			OnProcessRequestCompletePin.Broadcast();
		},
		0.01f,
		true
	);
	
	TimerManager.SetTimer(
		RequestProgressTimer,
		[this, &TimerManager]
		{
			if (!Request->IsRequestProgressDone())
				return;

			TimerManager.ClearTimer(RequestProgressTimer);
			OnRequestProgressPin.Broadcast();
		},
		0.01f,
		true
	);
	
	TimerManager.SetTimer(
		RequestWillRetryTimer,
		[this, &TimerManager]
		{
			if (!Request->IsRequestWillRetryDone())
				return;

			TimerManager.ClearTimer(RequestWillRetryTimer);
			OnRequestWillRetryPin.Broadcast();
		},
		0.01f,
		true
	);
	
	TimerManager.SetTimer(
		HeaderReceivedTimer,
		[this, &TimerManager]
		{
			if (!Request->IsHeaderReceivedDone())
				return;

			TimerManager.ClearTimer(HeaderReceivedTimer);
			OnHeaderReceivedPin.Broadcast();
		},
		0.01f,
		true
	);
}
