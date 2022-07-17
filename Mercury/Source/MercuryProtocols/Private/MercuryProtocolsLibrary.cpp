// Copyright (c) 2022 Kaya Adrian

#include "MercuryProtocolsLibrary.h"

#include "MercuryObjects/NetworkEndpoint.h"


UMercurySocket* UMercuryProtocolsLibrary::CreateSocket()
{
	return CreateSocket(nullptr);
}
UMercurySocket* UMercuryProtocolsLibrary::CreateSocket(FSocket* const& Resource)
{
	return CreateSocket(MakeShareable(Resource));
}
UMercurySocket* UMercuryProtocolsLibrary::CreateSocket(const TSharedPtr<FSocket>& Resource)
{
	UMercurySocket* const&& SocketObject = NewObject<UMercurySocket>();
	SocketObject->SetResource(Resource ? Resource : SocketObject->CreateResource());
	return SocketObject;
}

UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	const UMercurySocket* const& InSocket,
	const FTimespan& InSleepTime,
	const bool bInReusable
)
{
	return CreateTcpListener(nullptr, InSocket, InSleepTime, bInReusable);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	FTcpListener* const& Resource,
	const UMercurySocket* const& InSocket
)
{
	return CreateTcpListener(MakeShareable(Resource), InSocket);
}
UMercuryTcpListener* UMercuryProtocolsLibrary::CreateTcpListener(
	const TSharedPtr<FTcpListener>& Resource,
	const UMercurySocket* const& InSocket,
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

UMercuryTcpMultiReceiver* UMercuryProtocolsLibrary::CreateTcpMultiReceiver(const UMercurySocket* const& InSocket)
{
	return CreateTcpMultiReceiver(nullptr, InSocket);
}
UMercuryTcpMultiReceiver* UMercuryProtocolsLibrary::CreateTcpMultiReceiver(
	FMultichannelTcpReceiver* const& Resource,
	const UMercurySocket* const& InSocket
)
{
	return CreateTcpMultiReceiver(MakeShareable(Resource), InSocket);
}
UMercuryTcpMultiReceiver* UMercuryProtocolsLibrary::CreateTcpMultiReceiver(
	const TSharedPtr<FMultichannelTcpReceiver>& Resource,
	const UMercurySocket* const& InSocket
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;

	UMercuryTcpMultiReceiver* const&& MultiReceiver = NewObject<UMercuryTcpMultiReceiver>();
	MultiReceiver->SetResource(Resource ? Resource : MultiReceiver->CreateResource(Socket));
	return MultiReceiver;
}

UMercuryTcpMultiSender* UMercuryProtocolsLibrary::CreateTcpMultiSender(const UMercurySocket* const& InSocket)
{
	return CreateTcpMultiSender(nullptr, InSocket);
}
UMercuryTcpMultiSender* UMercuryProtocolsLibrary::CreateTcpMultiSender(
	FMultichannelTcpSender* const& Resource,
	const UMercurySocket* const& InSocket
)
{
	return CreateTcpMultiSender(MakeShareable(Resource), InSocket);
}
UMercuryTcpMultiSender* UMercuryProtocolsLibrary::CreateTcpMultiSender(
	const TSharedPtr<FMultichannelTcpSender>& Resource,
	const UMercurySocket* const& InSocket
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;

	UMercuryTcpMultiSender* const&& MultiSender = NewObject<UMercuryTcpMultiSender>();
	MultiSender->SetResource(Resource ? Resource : MultiSender->CreateResource(Socket));
	return MultiSender;
}

UMercuryTcpMultiSocket* UMercuryProtocolsLibrary::CreateTcpMultiSocket(
	const UMercurySocket* const& InSocket,
	const int32 InBandwidthLatencyProduct
)
{
	return CreateTcpMultiSocket(nullptr, InSocket, InBandwidthLatencyProduct);
}
UMercuryTcpMultiSocket* UMercuryProtocolsLibrary::CreateTcpMultiSocket(
	FMultichannelTcpSocket* const& Resource,
	const UMercurySocket* const& InSocket,
	const uint64& InBandwidthLatencyProduct
)
{
	return CreateTcpMultiSocket(MakeShareable(Resource), InSocket, InBandwidthLatencyProduct);
}
UMercuryTcpMultiSocket* UMercuryProtocolsLibrary::CreateTcpMultiSocket(
	const TSharedPtr<FMultichannelTcpSocket>& Resource,
	const UMercurySocket* const& InSocket,
	const uint64& InBandwidthLatencyProduct
)
{
	if (!InSocket)
		return nullptr;

	FSocket* const&& Socket = InSocket->GetResource().Get();
	if (!Socket)
		return nullptr;
	
	UMercuryTcpMultiSocket* const&& MultiSocket = NewObject<UMercuryTcpMultiSocket>();
	MultiSocket->SetResource(Resource ?
		Resource : MultiSocket->CreateResource({ Socket, InBandwidthLatencyProduct })
	);
	return MultiSocket;
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
	const UMercurySocket* const& InSocket,
	const FTimespan& InWaitTime,
	const FString& InThreadName
)
{
	return CreateUdpSocketReceiver(nullptr, InSocket, InWaitTime, InThreadName);
}
UMercuryUdpSocketReceiver* UMercuryProtocolsLibrary::CreateUdpSocketReceiver(
	FUdpSocketReceiver* const& Resource,
	const UMercurySocket* const& InSocket,
	const FTimespan& InWaitTime,
	const FString& InThreadName
)
{
	return CreateUdpSocketReceiver(MakeShareable(Resource), InSocket, InWaitTime, InThreadName);
}
UMercuryUdpSocketReceiver* UMercuryProtocolsLibrary::CreateUdpSocketReceiver(
	const TSharedPtr<FUdpSocketReceiver>& Resource,
	const UMercurySocket* const& InSocket,
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
