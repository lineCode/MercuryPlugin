// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryObjects/Socket.h"
#include "MercuryObjects/TCP/Listener.h"
#include "MercuryObjects/TCP/MultiReceiver.h"
#include "MercuryObjects/TCP/MultiSender.h"
#include "MercuryObjects/TCP/MultiSocket.h"
#include "MercuryObjects/TCP/StreamSocketBuilder.h"
#include "MercuryObjects/UDP/DatagramSocketBuilder.h"
#include "MercuryObjects/UDP/SocketReceiver.h"

#include "MercuryProtocolsLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Protocols Blueprint Function Library")
class MERCURYPROTOCOLS_API UMercuryProtocolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Create Socket", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object"
	))
	static UMercurySocket* CreateSocket();
	static UMercurySocket* CreateSocket(FSocket* const& Resource);
	static UMercurySocket* CreateSocket(const TSharedPtr<FSocket>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Listener", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Listener In Socket Sleep Time Reusable"
	))
	static UMercuryTcpListener* CreateTcpListener(
		const UMercurySocket* const& InSocket,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
	static UMercuryTcpListener* CreateTcpListener(
		FTcpListener* const& Resource,
		const UMercurySocket* const& InSocket
	);
	static UMercuryTcpListener* CreateTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);
	static UMercuryTcpListener* CreateTcpListener(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		const bool& bInReusable = true
	);
	static UMercuryTcpListener* CreateTcpListener(
		FTcpListener* const& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint
	);
	static UMercuryTcpListener* CreateTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Receiver", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Receiver In Socket"
	))
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(const UMercurySocket* const& InSocket);
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(
		FMultichannelTcpReceiver* const& Resource,
		const UMercurySocket* const& InSocket
	);
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(
		const TSharedPtr<FMultichannelTcpReceiver>& Resource,
		const UMercurySocket* const& InSocket
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Sender", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Sender In Socket"
	))
	static UMercuryTcpMultiSender* CreateTcpMultiSender(const UMercurySocket* const& InSocket);
	static UMercuryTcpMultiSender* CreateTcpMultiSender(
		FMultichannelTcpSender* const& Resource,
		const UMercurySocket* const& InSocket
	);
	static UMercuryTcpMultiSender* CreateTcpMultiSender(
		const TSharedPtr<FMultichannelTcpSender>& Resource,
		const UMercurySocket* const& InSocket
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Socket", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Socket In Bandwidth Latency Product"
	))
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		const UMercurySocket* const& InSocket,
		int32 InBandwidthLatencyProduct
	);
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		FMultichannelTcpSocket* const& Resource,
		const UMercurySocket* const& InSocket,
		const uint64& InBandwidthLatencyProduct
	);
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		const TSharedPtr<FMultichannelTcpSocket>& Resource,
		const UMercurySocket* const& InSocket,
		const uint64& InBandwidthLatencyProduct
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Socket Builder", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Socket Builder In Description"
	))
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(const FString& InDescription = TEXT("TCP_Socket"));
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(FTcpSocketBuilder* const& Resource);
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(
		const TSharedPtr<FTcpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("TCP_Socket")
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create UDP Socket Builder", Category = "Mercury|UDP", meta = (
		Keywords = "Create UDP Socket Builder In Description"
	))
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(const FString& InDescription = TEXT("UDP_Socket"));
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(FUdpSocketBuilder* const& Resource);
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(
		const TSharedPtr<FUdpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("UDP_Socket")
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create UDP Socket Receiver", Category = "Mercury|UDP", meta = (
		Keywords = "Create UDP Socket Receiver In Socket Wait Time Thread Name"
	))
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		FUdpSocketReceiver* const& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		const TSharedPtr<FUdpSocketReceiver>& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Listener (Endpoint)", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Listener Local Endpoint In Sleep Time Reusable"
	))
	static UMercuryTcpListener* K2_CreateTcpListenerWithEndpoint(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
};
