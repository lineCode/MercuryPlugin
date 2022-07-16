// Copyright (c) 2022 Kaya Adrian

#include "TcpMultichannelSender.h"


TSharedPtr<FMultichannelTcpSender> UMercuryTcpMultichannelSender::CreateResource(
	const std::tuple<FSocket*>& Arguments
)
{
	FOnMultichannelTcpOkToSend&& InOkToSendDelegate = FOnMultichannelTcpOkToSend();
	InOkToSendDelegate.BindUObject(this, &UMercuryTcpMultichannelSender::BindOkToSend);
	
	return MakeShareable(new FMultichannelTcpSender(std::get<0>(Arguments), InOkToSendDelegate));
}
UMercuryTcpMultichannelSender::UMercuryTcpMultichannelSender(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	bOkToSendDone = false;
}

bool UMercuryTcpMultichannelSender::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpMultichannelSender::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryTcpMultichannelSender::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryTcpMultichannelSender::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryTcpMultichannelSender::Send(const uint8* const& Data, const int32& Count, const uint32& Channel)
{
	if (!HasResource())
		return;

	Resource->Send(Data, Count, Channel);
}

void UMercuryTcpMultichannelSender::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

void UMercuryTcpMultichannelSender::AttemptResumeSending()
{
	if (!HasResource())
		return;

	Resource->AttemptResumeSending();
}

int32 UMercuryTcpMultichannelSender::GetBytesSent() const
{
	return HasResource() ? Resource->GetBytesSent() : 0;
}

FSingleThreadRunnable* UMercuryTcpMultichannelSender::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

bool UMercuryTcpMultichannelSender::BindOkToSend(const int32 Count, const uint32 Channel)
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

UMercuryTcpMultichannelSender* UMercuryTcpMultichannelSender::K2_SetOkToSendEvent(
	const FMercuryTcpMultichannelOkToSendDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpMultichannelOkToSendDelegate = Event;
	return this;
}

int32 UMercuryTcpMultichannelSender::K2_Run()
{
	return Run();
}

void UMercuryTcpMultichannelSender::K2_Send(const TArray<uint8>& Data, const int32 Count, const int32 Channel)
{
	Send(Data.GetData(), Count, Channel);
}
