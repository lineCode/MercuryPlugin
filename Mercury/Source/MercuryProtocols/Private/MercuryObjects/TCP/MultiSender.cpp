// Copyright (c) 2022 Kaya Adrian

#include "MultiSender.h"


TSharedPtr<FMultichannelTcpSender> UMercuryTcpMultiSender::CreateResource(const std::tuple<FSocket*>& Arguments)
{
	FOnMultichannelTcpOkToSend&& InOkToSendDelegate = FOnMultichannelTcpOkToSend();
	InOkToSendDelegate.BindUObject(this, &UMercuryTcpMultiSender::BindOkToSend);
	
	return MakeShareable(new FMultichannelTcpSender(std::get<0>(Arguments), InOkToSendDelegate));
}
UMercuryTcpMultiSender::UMercuryTcpMultiSender(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bOkToSendDone = false;
}

bool UMercuryTcpMultiSender::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpMultiSender::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryTcpMultiSender::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryTcpMultiSender::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryTcpMultiSender::Send(const uint8* const& Data, const int32& Count, const uint32& Channel)
{
	if (!HasResource())
		return;

	Resource->Send(Data, Count, Channel);
}

void UMercuryTcpMultiSender::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

void UMercuryTcpMultiSender::AttemptResumeSending()
{
	if (!HasResource())
		return;

	Resource->AttemptResumeSending();
}

int32 UMercuryTcpMultiSender::GetBytesSent() const
{
	return HasResource() ? Resource->GetBytesSent() : 0;
}

FSingleThreadRunnable* UMercuryTcpMultiSender::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

bool UMercuryTcpMultiSender::BindOkToSend(const int32 Count, const uint32 Channel)
{
	bOkToSendDone = false;

	bool&& bSuccess = false;
	if (!OnMercuryTcpMultichannelOkToSendDelegate.IsBound())
	{
		bOkToSendDone = true;
		return bSuccess;
	}

	bSuccess = OnMercuryTcpMultichannelOkToSendDelegate.Execute(Count, Channel);
	bOkToSendDone = true;
	return bSuccess;
}

UMercuryTcpMultiSender* UMercuryTcpMultiSender::K2_SetOkToSendEvent(
	const FMercuryTcpMultichannelOkToSendDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpMultichannelOkToSendDelegate = Event;
	return this;
}

int32 UMercuryTcpMultiSender::K2_Run()
{
	return Run();
}

void UMercuryTcpMultiSender::K2_Send(const TArray<uint8>& Data, const int32 Count, const int32 Channel)
{
	Send(Data.GetData(), Count, Channel);
}
