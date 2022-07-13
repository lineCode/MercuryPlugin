// Copyright (c) 2022 Kaya Adrian

#include "MercurySocketLibrary.h"

#include "MercuryNetworkEndpoint.h"


UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject()
{
	return CreateSocketObject(nullptr);
}
UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject(FSocket* const& Resource)
{
	return CreateSocketObject(MakeShareable(Resource));
}
UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject(const TSharedPtr<FSocket>& Resource)
{
	UMercurySocketObject* const&& SocketObject = NewObject<UMercurySocketObject>();
	SocketObject->SetResource(Resource ? Resource : SocketObject->CreateResource());
	return SocketObject;
}

UMercuryTcpSocketBuilder* UMercurySocketLibrary::CreateTcpSocketBuilder(const FString& InDescription)
{
	return CreateTcpSocketBuilder(nullptr, InDescription);
}
UMercuryTcpSocketBuilder* UMercurySocketLibrary::CreateTcpSocketBuilder(FTcpSocketBuilder* const& Resource)
{
	return CreateTcpSocketBuilder(MakeShareable(Resource));
}
UMercuryTcpSocketBuilder* UMercurySocketLibrary::CreateTcpSocketBuilder(
	const TSharedPtr<FTcpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercuryTcpSocketBuilder* const&& TcpBuilder = NewObject<UMercuryTcpSocketBuilder>();
	TcpBuilder->SetResource(Resource ? Resource : TcpBuilder->CreateResource(InDescription));
	return TcpBuilder;
}

UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	UMercurySocketObject* const& InSocket,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateTcpListener(nullptr, InSocket, InSleepTime, bInReusable);
}
UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	FTcpListener* const& Resource,
	UMercurySocketObject* const& InSocket
)
{
	return CreateTcpListener(MakeShareable(Resource), InSocket);
}
UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	const TSharedPtr<FTcpListener>& Resource,
	UMercurySocketObject* const& InSocket,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	if (!InSocket)
		return nullptr;

	FSocket*&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;
	
	UMercuryTcpListener* const&& TcpListener = NewObject<UMercuryTcpListener>();
	TcpListener->SetResource(
		Resource ? Resource : TcpListener->CreateResource({ Socket, InSleepTime, bInReusable })
	);
	return TcpListener;
}
UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	return CreateTcpListener(nullptr, LocalEndpoint, InSleepTime, bInReusable);
}
UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	FTcpListener* const& Resource,
	const UMercuryNetworkEndpoint* const& LocalEndpoint
)
{
	return CreateTcpListener(MakeShareable(Resource), LocalEndpoint);
}
UMercuryTcpListener* UMercurySocketLibrary::CreateTcpListener(
	const TSharedPtr<FTcpListener>& Resource,
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	if (!LocalEndpoint)
		return nullptr;

	const TSharedPtr<FIPv4Endpoint>& Endpoint = LocalEndpoint->GetResource();
	if (!Endpoint)
		return nullptr;
	
	UMercuryTcpListener* const&& TcpListener = NewObject<UMercuryTcpListener>();
	TcpListener->SetResource(Resource ?
		Resource : TcpListener->CreateResourceWithEndpoint({ *Endpoint, InSleepTime, bInReusable })
	);
	return TcpListener;
}

UMercuryTcpListener* UMercurySocketLibrary::K2_CreateTcpListenerWithEndpoint(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateTcpListener(LocalEndpoint, InSleepTime, bInReusable);
}
