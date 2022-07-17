// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryObjects/SocketObject.h"
#include "MercuryObjects/TcpListener.h"
#include "MercuryObjects/TcpMultichannelReceiver.h"
#include "MercuryObjects/TcpMultichannelSender.h"
#include "MercuryObjects/TcpMultichannelSocket.h"
#include "MercuryObjects/TcpSocketBuilder.h"
#include "MercuryObjects/UdpSocketBuilder.h"
#include "MercuryObjects/UdpSocketReceiver.h"

#include "MercuryProtocolsLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Protocols Blueprint Function Library")
class MERCURYPROTOCOLS_API UMercuryProtocolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Create Socket Object", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object"
	))
	static UMercurySocketObject* CreateSocketObject();
	static UMercurySocketObject* CreateSocketObject(FSocket* const& Resource);
	static UMercurySocketObject* CreateSocketObject(const TSharedPtr<FSocket>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Listener", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Listener In Socket Sleep Time Reusable"
	))
	static UMercuryTcpListener* CreateTcpListener(
		const UMercurySocketObject* const& InSocket,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
	static UMercuryTcpListener* CreateTcpListener(
		FTcpListener* const& Resource,
		const UMercurySocketObject* const& InSocket
	);
	static UMercuryTcpListener* CreateTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercurySocketObject* const& InSocket,
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

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multichannel Receiver", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multichannel Receiver In Socket"
	))
	static UMercuryTcpMultichannelReceiver* CreateTcpMultichannelReceiver(
		const UMercurySocketObject* const& InSocket
	);
	static UMercuryTcpMultichannelReceiver* CreateTcpMultichannelReceiver(
		FMultichannelTcpReceiver* const& Resource,
		const UMercurySocketObject* const& InSocket
	);
	static UMercuryTcpMultichannelReceiver* CreateTcpMultichannelReceiver(
		const TSharedPtr<FMultichannelTcpReceiver>& Resource,
		const UMercurySocketObject* const& InSocket
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multichannel Sender", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multichannel Sender In Socket"
	))
	static UMercuryTcpMultichannelSender* CreateTcpMultichannelSender(
		const UMercurySocketObject* const& InSocket
	);
	static UMercuryTcpMultichannelSender* CreateTcpMultichannelSender(
		FMultichannelTcpSender* const& Resource,
		const UMercurySocketObject* const& InSocket
	);
	static UMercuryTcpMultichannelSender* CreateTcpMultichannelSender(
		const TSharedPtr<FMultichannelTcpSender>& Resource,
		const UMercurySocketObject* const& InSocket
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multichannel Socket", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multichannel Socket In Bandwidth Latency Product"
	))
	static UMercuryTcpMultichannelSocket* CreateTcpMultichannelSocket(
		const UMercurySocketObject* const& InSocket,
		int32 InBandwidthLatencyProduct
	);
	static UMercuryTcpMultichannelSocket* CreateTcpMultichannelSocket(
		FMultichannelTcpSocket* const& Resource,
		const UMercurySocketObject* const& InSocket,
		const uint64& InBandwidthLatencyProduct
	);
	static UMercuryTcpMultichannelSocket* CreateTcpMultichannelSocket(
		const TSharedPtr<FMultichannelTcpSocket>& Resource,
		const UMercurySocketObject* const& InSocket,
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
		const UMercurySocketObject* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		FUdpSocketReceiver* const& Resource,
		const UMercurySocketObject* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		const TSharedPtr<FUdpSocketReceiver>& Resource,
		const UMercurySocketObject* const& InSocket,
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
