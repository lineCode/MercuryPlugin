// Copyright (c) 2022 Kaya Adrian

#include "MercurySocketTcpListener.h"

#include "MercuryNetworkLibrary.h"
#include "MercurySocketLibrary.h"


TSharedPtr<FTcpListener> UMercurySocketTcpListener::CreateResource(
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
	TcpListener->OnConnectionAccepted().BindUObject(this, &UMercurySocketTcpListener::BindConnectionAccepted);
	return TcpListener;
}
UMercurySocketTcpListener::UMercurySocketTcpListener(
	const FObjectInitializer& ObjectInitializer
) : Super(ObjectInitializer)
{
	bConnectionAcceptedDone = false;
}

TSharedPtr<FTcpListener> UMercurySocketTcpListener::CreateResourceWithEndpoint(
	const std::tuple<FIPv4Endpoint, FTimespan, bool>& Arguments
)
{
	const TSharedPtr<FTcpListener>&& TcpListener = MakeShareable(new FTcpListener(
		std::get<0>(Arguments),
		std::get<1>(Arguments),
		std::get<2>(Arguments)
	));
	TcpListener->OnConnectionAccepted().BindUObject(this, &UMercurySocketTcpListener::BindConnectionAccepted);
	return TcpListener;
}

bool UMercurySocketTcpListener::HasResource() const
{
	return Resource != nullptr;
}

void UMercurySocketTcpListener::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercurySocketTcpListener::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercurySocketTcpListener::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

void UMercurySocketTcpListener::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

UMercurySocketObject* UMercurySocketTcpListener::GetSocket() const
{
	return HasResource() ? UMercurySocketLibrary::CreateSocketObject(Resource->GetSocket()) : nullptr;
}

bool UMercurySocketTcpListener::IsActive() const
{
	return HasResource() && Resource->IsActive();
}

UMercuryNetworkEndpoint* UMercurySocketTcpListener::GetLocalEndpoint() const
{
	return HasResource() ?
		UMercuryNetworkLibrary::CreateNetworkEndpoint(new FIPv4Endpoint(Resource->GetLocalEndpoint())) : nullptr;
}

FSingleThreadRunnable* UMercurySocketTcpListener::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

bool UMercurySocketTcpListener::BindConnectionAccepted(FSocket* const Socket, const FIPv4Endpoint& Endpoint)
{
	bConnectionAcceptedDone = false;
	if (!OnMercuryTcpListenerConnectionAcceptedDelegate.IsBound())
	{
		bConnectionAcceptedDone = true;
		return false;
	}

	OnMercuryTcpListenerConnectionAcceptedDelegate.Execute(
		UMercurySocketLibrary::CreateSocketObject(Socket),
		UMercuryNetworkLibrary::CreateNetworkEndpoint(new FIPv4Endpoint(Endpoint))
	);
	bConnectionAcceptedDone = true;
	return true;
}

UMercurySocketTcpListener* UMercurySocketTcpListener::K2_SetConnectionAcceptedEvent(
	const FMercuryTcpListenerConnectionAcceptedDelegate& Event
)
{
	if (!HasResource())
		return nullptr;

	OnMercuryTcpListenerConnectionAcceptedDelegate = Event;
	return this;
}

int32 UMercurySocketTcpListener::K2_Run()
{
	return Run();
}
