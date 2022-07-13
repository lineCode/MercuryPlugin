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

UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(const FString& InDescription)
{
	return CreateSocketTcpBuilder(nullptr, InDescription);
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(FTcpSocketBuilder* const& Resource)
{
	return CreateSocketTcpBuilder(MakeShareable(Resource));
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(
	const TSharedPtr<FTcpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercurySocketTcpBuilder* const&& TcpBuilder = NewObject<UMercurySocketTcpBuilder>();
	TcpBuilder->SetResource(Resource ? Resource : TcpBuilder->CreateResource(InDescription));
	return TcpBuilder;
}

UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
	UMercurySocketObject* const& InSocket,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateSocketTcpListener(nullptr, InSocket, InSleepTime, bInReusable);
}
UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
	FTcpListener* const& Resource,
	UMercurySocketObject* const& InSocket
)
{
	return CreateSocketTcpListener(MakeShareable(Resource), InSocket);
}
UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
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
	
	UMercurySocketTcpListener* const&& TcpListener = NewObject<UMercurySocketTcpListener>();
	TcpListener->SetResource(
		Resource ? Resource : TcpListener->CreateResource({ Socket, InSleepTime, bInReusable })
	);
	//InSocket->SetResource(MakeShareable(Socket));
	return TcpListener;
}
UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	return CreateSocketTcpListener(nullptr, LocalEndpoint, InSleepTime, bInReusable);
}
UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
	FTcpListener* const& Resource,
	const UMercuryNetworkEndpoint* const& LocalEndpoint
)
{
	return CreateSocketTcpListener(MakeShareable(Resource), LocalEndpoint);
}
UMercurySocketTcpListener* UMercurySocketLibrary::CreateSocketTcpListener(
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
	
	UMercurySocketTcpListener* const&& TcpListener = NewObject<UMercurySocketTcpListener>();
	TcpListener->SetResource(Resource ?
		Resource : TcpListener->CreateResourceWithEndpoint({ *Endpoint, InSleepTime, bInReusable })
	);
	return TcpListener;
}

UMercurySocketTcpListener* UMercurySocketLibrary::K2_CreateSocketTcpListenerWithEndpoint(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateSocketTcpListener(LocalEndpoint, InSleepTime, bInReusable);
}
