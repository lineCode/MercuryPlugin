// Copyright (c) 2022 Kaya Adrian

#include "Listener.h"

#include "MercuryNetworkLibrary.h"
#include "MercuryProtocolsLibrary.h"


TSharedPtr<FTcpListener> UMercuryTcpListener::CreateResource(
	const std::tuple<FSocket*, FTimespan, bool>& Arguments
)
{
	FSocket* Socket = std::get<0>(Arguments);
	if (!Socket)
		return nullptr;
	
	const TSharedPtr<FTcpListener>&& TcpListener = MakeShareable(new FTcpListener(
		*Socket,
		std::get<1>(Arguments),
		std::get<2>(Arguments)
	));
	TcpListener->OnConnectionAccepted().BindUObject(this, &UMercuryTcpListener::BindConnectionAccepted);
	return TcpListener;
}
UMercuryTcpListener::UMercuryTcpListener(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	bConnectionAcceptedDone = false;
}

TSharedPtr<FTcpListener> UMercuryTcpListener::CreateResourceWithEndpoint(
	const std::tuple<FIPv4Endpoint, FTimespan, bool>& Arguments
)
{
	const TSharedPtr<FTcpListener>&& TcpListener = MakeShareable(new FTcpListener(
		std::get<0>(Arguments),
		std::get<1>(Arguments),
		std::get<2>(Arguments)
	));
	TcpListener->OnConnectionAccepted().BindUObject(this, &UMercuryTcpListener::BindConnectionAccepted);
	return TcpListener;
}

bool UMercuryTcpListener::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpListener::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryTcpListener::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryTcpListener::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercuryTcpListener::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

UMercurySocket* UMercuryTcpListener::GetSocket() const
{
	return HasResource() ? UMercuryProtocolsLibrary::CreateSocket(Resource->GetSocket()) : nullptr;
}

bool UMercuryTcpListener::IsActive() const
{
	return HasResource() && Resource->IsActive();
}

UMercuryNetworkEndpoint* UMercuryTcpListener::GetLocalEndpoint() const
{
	return HasResource() ?
		UMercuryNetworkLibrary::CreateNetworkEndpoint(new FIPv4Endpoint(Resource->GetLocalEndpoint())) : nullptr;
}

FSingleThreadRunnable* UMercuryTcpListener::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

bool UMercuryTcpListener::BindConnectionAccepted(FSocket* const Socket, const FIPv4Endpoint& Endpoint)
{
	bConnectionAcceptedDone = false;

	bool&& bSuccess = false;
	if (!OnMercuryTcpListenerConnectionAcceptedDelegate.IsBound())
	{
		bConnectionAcceptedDone = true;
		return bSuccess;
	}

	bSuccess = OnMercuryTcpListenerConnectionAcceptedDelegate.Execute(
		UMercuryProtocolsLibrary::CreateSocket(Socket),
		UMercuryNetworkLibrary::CreateNetworkEndpoint(new FIPv4Endpoint(Endpoint))
	);
	bConnectionAcceptedDone = true;
	return bSuccess;
}

UMercuryTcpListener* UMercuryTcpListener::K2_SetConnectionAcceptedEvent(
	const FMercuryTcpListenerConnectionAcceptedDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpListenerConnectionAcceptedDelegate = Event;
	return this;
}

int32 UMercuryTcpListener::K2_Run()
{
	return Run();
}
