// Copyright (c) 2022 Kaya Adrian

#include "SocketReceiver.h"

#include "MercuryNetworkLibrary.h"


TSharedPtr<FUdpSocketReceiver> UMercuryUdpSocketReceiver::CreateResource(
	const std::tuple<FSocket*, FTimespan, const TCHAR*>& Arguments
)
{
	const TSharedPtr<FUdpSocketReceiver>&& UdpReceiver = MakeShareable(new FUdpSocketReceiver(
		std::get<0>(Arguments),
		std::get<1>(Arguments),
		std::get<2>(Arguments)
	));
	UdpReceiver->OnDataReceived().BindUObject(this, &UMercuryUdpSocketReceiver::BindDataReceived);
	return UdpReceiver;
}

bool UMercuryUdpSocketReceiver::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryUdpSocketReceiver::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryUdpSocketReceiver::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryUdpSocketReceiver::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryUdpSocketReceiver::Start()
{
	if (!HasResource())
		return;

	Resource->Start();
}

void UMercuryUdpSocketReceiver::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

FSingleThreadRunnable* UMercuryUdpSocketReceiver::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

void UMercuryUdpSocketReceiver::SetMaxReadBufferSize(const uint32& InMaxReadBufferSize)
{
	if (!HasResource())
		return;

	Resource->SetMaxReadBufferSize(InMaxReadBufferSize);
}

void UMercuryUdpSocketReceiver::BindDataReceived(const FArrayReaderPtr& Data, const FIPv4Endpoint& Endpoint)
{
	if (OnMercuryUdpSocketDataReceivedDelegate.IsBound())
	{
		OnMercuryUdpSocketDataReceivedDelegate.Execute(
			*Data,
			UMercuryNetworkLibrary::CreateNetworkEndpoint(new FIPv4Endpoint(Endpoint))
		);
	}
}

UMercuryUdpSocketReceiver* UMercuryUdpSocketReceiver::K2_SetDataReceivedEvent(
	const FMercuryUdpSocketDataReceivedDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryUdpSocketDataReceivedDelegate = Event;
	return this;
}

int32 UMercuryUdpSocketReceiver::K2_Run()
{
	return Run();
}

void UMercuryUdpSocketReceiver::K2_SetMaxReadBufferSize(const int32 InMaxReadBufferSize)
{
	return SetMaxReadBufferSize(InMaxReadBufferSize);
}
