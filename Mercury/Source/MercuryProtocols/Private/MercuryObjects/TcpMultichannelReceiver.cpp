// Copyright (c) 2022 Kaya Adrian

#include "TcpMultichannelReceiver.h"


TSharedPtr<FMultichannelTcpReceiver> UMercuryTcpMultichannelReceiver::CreateResource(
	const std::tuple<FSocket*>& Arguments
)
{
	FOnMultichannelTcpReceive&& InReceiveDelegate = FOnMultichannelTcpReceive();
	InReceiveDelegate.BindUObject(this, &UMercuryTcpMultichannelReceiver::BindReceive);
	
	return MakeShareable(new FMultichannelTcpReceiver(std::get<0>(Arguments), InReceiveDelegate));
}

bool UMercuryTcpMultichannelReceiver::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpMultichannelReceiver::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryTcpMultichannelReceiver::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryTcpMultichannelReceiver::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryTcpMultichannelReceiver::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

int32 UMercuryTcpMultichannelReceiver::GetBytesReceived() const
{
	return HasResource() ? Resource->GetBytesReceived() : 0;
}

FSingleThreadRunnable* UMercuryTcpMultichannelReceiver::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

void UMercuryTcpMultichannelReceiver::BindReceive(
	const TArray<uint8>& Data,
	const uint32 BytesReceived,
	const bool bNeedsByteSwap
)
{
	bReceiveDone = false;
	if (!OnMercuryTcpMultichannelReceiverReceiveDelegate.IsBound())
	{
		bReceiveDone = true;
		return;
	}

	OnMercuryTcpMultichannelReceiverReceiveDelegate.Execute(Data, BytesReceived, bNeedsByteSwap);
	bReceiveDone = true;
}

UMercuryTcpMultichannelReceiver* UMercuryTcpMultichannelReceiver::K2_SetReceiveEvent(
	const FMercuryTcpMultichannelReceiverReceiveDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpMultichannelReceiverReceiveDelegate = Event;
	return this;
}

int32 UMercuryTcpMultichannelReceiver::K2_Run()
{
	return Run();
}
