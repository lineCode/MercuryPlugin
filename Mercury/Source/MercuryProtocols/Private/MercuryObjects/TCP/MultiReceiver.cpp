// Copyright (c) 2022 Kaya Adrian

#include "MultiReceiver.h"


TSharedPtr<FMultichannelTcpReceiver> UMercuryTcpMultiReceiver::CreateResource(const std::tuple<FSocket*>& Arguments)
{
	FOnMultichannelTcpReceive&& InReceiveDelegate = FOnMultichannelTcpReceive();
	InReceiveDelegate.BindUObject(this, &UMercuryTcpMultiReceiver::BindReceive);
	
	return MakeShareable(new FMultichannelTcpReceiver(std::get<0>(Arguments), InReceiveDelegate));
}

bool UMercuryTcpMultiReceiver::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpMultiReceiver::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryTcpMultiReceiver::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryTcpMultiReceiver::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryTcpMultiReceiver::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

int32 UMercuryTcpMultiReceiver::GetBytesReceived() const
{
	return HasResource() ? Resource->GetBytesReceived() : 0;
}

FSingleThreadRunnable* UMercuryTcpMultiReceiver::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

void UMercuryTcpMultiReceiver::BindReceive(
	const TArray<uint8>& Data,
	const uint32 BytesReceived,
	const bool bNeedsByteSwap
)
{
	if (OnMercuryTcpMultichannelReceiveDelegate.IsBound())
	{
		OnMercuryTcpMultichannelReceiveDelegate.Execute(Data, BytesReceived, bNeedsByteSwap);
	}
}

UMercuryTcpMultiReceiver* UMercuryTcpMultiReceiver::K2_SetReceiveEvent(
	const FMercuryTcpMultichannelReceiveDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpMultichannelReceiveDelegate = Event;
	return this;
}

int32 UMercuryTcpMultiReceiver::K2_Run()
{
	return Run();
}
