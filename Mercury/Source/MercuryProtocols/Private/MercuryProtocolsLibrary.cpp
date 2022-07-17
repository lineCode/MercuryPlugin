// Copyright (c) 2022 Kaya Adrian

#include "MercuryProtocolsLibrary.h"

#include "MercuryObjects/NetworkEndpoint.h"


UMercurySocketObject* UMercuryProtocolsLibrary::CreateSocketObject()
{
	return CreateSocketObject(nullptr);
}
UMercurySocketObject* UMercuryProtocolsLibrary::CreateSocketObject(FSocket* const& Resource)
{
	return CreateSocketObject(MakeShareable(Resource));
}
UMercurySocketObject* UMercuryProtocolsLibrary::CreateSocketObject(const TSharedPtr<FSocket>& Resource)
{
	UMercurySocketObject* const&& SocketObject = NewObject<UMercurySocketObject>();
	SocketObject->SetResource(Resource ? Resource : SocketObject->CreateResource());
	return SocketObject;
}

UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	const UMercurySocketObject* const& InSocket,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateTcpListener(nullptr, InSocket, InSleepTime, bInReusable);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	FTcpListener* const& Resource,
	const UMercurySocketObject* const& InSocket
)
{
	return CreateTcpListener(MakeShareable(Resource), InSocket);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	const TSharedPtr<FTcpListener>& Resource,
	const UMercurySocketObject* const& InSocket,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;
	
	UMercuryTcpListener* const&& TcpListener = NewObject<UMercuryTcpListener>();
	TcpListener->SetResource(
		Resource ? Resource : TcpListener->CreateResource({ Socket, InSleepTime, bInReusable })
	);
	return TcpListener;
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool& bInReusable
)
{
	return CreateTcpListener(nullptr, LocalEndpoint, InSleepTime, bInReusable);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	FTcpListener* const& Resource,
	const UMercuryNetworkEndpoint* const& LocalEndpoint
)
{
	return CreateTcpListener(MakeShareable(Resource), LocalEndpoint);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
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

UMercuryTcpMultichannelReceiver* UMercuryProtocolsLibrary::CreateTcpMultichannelReceiver(
	const UMercurySocketObject* const& InSocket
)
{
	return CreateTcpMultichannelReceiver(nullptr, InSocket);
}
UMercuryTcpMultichannelReceiver* UMercuryProtocolsLibrary::CreateTcpMultichannelReceiver(
	FMultichannelTcpReceiver* const& Resource,
	const UMercurySocketObject* const& InSocket
)
{
	return CreateTcpMultichannelReceiver(MakeShareable(Resource), InSocket);
}
UMercuryTcpMultichannelReceiver* UMercuryProtocolsLibrary::CreateTcpMultichannelReceiver(
	const TSharedPtr<FMultichannelTcpReceiver>& Resource,
	const UMercurySocketObject* const& InSocket
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;

	UMercuryTcpMultichannelReceiver* const&& MultichannelReceiver = NewObject<UMercuryTcpMultichannelReceiver>();
	MultichannelReceiver->SetResource(Resource ? Resource : MultichannelReceiver->CreateResource(Socket));
	return MultichannelReceiver;
}

UMercuryTcpMultichannelSender* UMercuryProtocolsLibrary::CreateTcpMultichannelSender(
	const UMercurySocketObject* const& InSocket
)
{
	return CreateTcpMultichannelSender(nullptr, InSocket);
}
UMercuryTcpMultichannelSender* UMercuryProtocolsLibrary::CreateTcpMultichannelSender(
	FMultichannelTcpSender* const& Resource,
	const UMercurySocketObject* const& InSocket
)
{
	return CreateTcpMultichannelSender(MakeShareable(Resource), InSocket);
}
UMercuryTcpMultichannelSender* UMercuryProtocolsLibrary::CreateTcpMultichannelSender(
	const TSharedPtr<FMultichannelTcpSender>& Resource,
	const UMercurySocketObject* const& InSocket
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;

	UMercuryTcpMultichannelSender* const&& MultichannelSender = NewObject<UMercuryTcpMultichannelSender>();
	MultichannelSender->SetResource(Resource ? Resource : MultichannelSender->CreateResource(Socket));
	return MultichannelSender;
}

UMercuryTcpMultichannelSocket* UMercuryProtocolsLibrary::CreateTcpMultichannelSocket(
	const UMercurySocketObject* const& InSocket,
	const int32 InBandwidthLatencyProduct
)
{
	return CreateTcpMultichannelSocket(nullptr, InSocket, InBandwidthLatencyProduct);
}
UMercuryTcpMultichannelSocket* UMercuryProtocolsLibrary::CreateTcpMultichannelSocket(
	FMultichannelTcpSocket* const& Resource,
	const UMercurySocketObject* const& InSocket,
	const uint64& InBandwidthLatencyProduct
)
{
	return CreateTcpMultichannelSocket(MakeShareable(Resource), InSocket, InBandwidthLatencyProduct);
}
UMercuryTcpMultichannelSocket* UMercuryProtocolsLibrary::CreateTcpMultichannelSocket(
	const TSharedPtr<FMultichannelTcpSocket>& Resource,
	const UMercurySocketObject* const& InSocket,
	const uint64& InBandwidthLatencyProduct
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;
	
	UMercuryTcpMultichannelSocket* const&& MultichannelSocket = NewObject<UMercuryTcpMultichannelSocket>();
	MultichannelSocket->SetResource(Resource ?
		Resource : MultichannelSocket->CreateResource({ Socket, InBandwidthLatencyProduct })
	);
	return MultichannelSocket;
}

UMercuryTcpSocketBuilder* UMercuryProtocolsLibrary::CreateTcpSocketBuilder(const FString& InDescription)
{
	return CreateTcpSocketBuilder(nullptr, InDescription);
}
UMercuryTcpSocketBuilder* UMercuryProtocolsLibrary::CreateTcpSocketBuilder(FTcpSocketBuilder* const& Resource)
{
	return CreateTcpSocketBuilder(MakeShareable(Resource));
}
UMercuryTcpSocketBuilder* UMercuryProtocolsLibrary::CreateTcpSocketBuilder(
	const TSharedPtr<FTcpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercuryTcpSocketBuilder* const&& TcpBuilder = NewObject<UMercuryTcpSocketBuilder>();
	TcpBuilder->SetResource(Resource ? Resource : TcpBuilder->CreateResource(InDescription));
	return TcpBuilder;
}

UMercuryUdpSocketBuilder* UMercuryProtocolsLibrary::CreateUdpSocketBuilder(const FString& InDescription)
{
	return CreateUdpSocketBuilder(nullptr, InDescription);
}
UMercuryUdpSocketBuilder* UMercuryProtocolsLibrary::CreateUdpSocketBuilder(FUdpSocketBuilder* const& Resource)
{
	return CreateUdpSocketBuilder(MakeShareable(Resource));
}
UMercuryUdpSocketBuilder* UMercuryProtocolsLibrary::CreateUdpSocketBuilder(
	const TSharedPtr<FUdpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercuryUdpSocketBuilder* const&& UdpBuilder = NewObject<UMercuryUdpSocketBuilder>();
	UdpBuilder->SetResource(Resource ? Resource : UdpBuilder->CreateResource(InDescription));
	return UdpBuilder;
}

UMercuryUdpSocketReceiver* UMercuryProtocolsLibrary::CreateUdpSocketReceiver(
	const UMercurySocketObject* const& InSocket,
	const FTimespan& InWaitTime,
	const FString& InThreadName
)
{
	return CreateUdpSocketReceiver(nullptr, InSocket, InWaitTime, InThreadName);
}
UMercuryUdpSocketReceiver* UMercuryProtocolsLibrary::CreateUdpSocketReceiver(
	FUdpSocketReceiver* const& Resource,
	const UMercurySocketObject* const& InSocket,
	const FTimespan& InWaitTime,
	const FString& InThreadName
)
{
	return CreateUdpSocketReceiver(MakeShareable(Resource), InSocket, InWaitTime, InThreadName);
}
UMercuryUdpSocketReceiver* UMercuryProtocolsLibrary::CreateUdpSocketReceiver(
	const TSharedPtr<FUdpSocketReceiver>& Resource,
	const UMercurySocketObject* const& InSocket,
	const FTimespan& InWaitTime,
	const FString& InThreadName
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;
	
	UMercuryUdpSocketReceiver* const&& UdpReceiver = NewObject<UMercuryUdpSocketReceiver>();
	UdpReceiver->SetResource(
		Resource ? Resource : UdpReceiver->CreateResource({ Socket, InWaitTime, *InThreadName })
	);
	return UdpReceiver;
}

UMercuryTcpListener* UMercuryProtocolsLibrary::K2_CreateTcpListenerWithEndpoint(
	const UMercuryNetworkEndpoint* const& LocalEndpoint,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateTcpListener(LocalEndpoint, InSleepTime, bInReusable);
}
