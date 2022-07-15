// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryObjects/SocketObject.h"
#include "MercuryObjects/TcpListener.h"
#include "MercuryObjects/TcpMultichannelSocket.h"
#include "MercuryObjects/TcpSocketBuilder.h"

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
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(const FString& InDescription = TEXT("TCP Socket"));
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(FTcpSocketBuilder* const& Resource);
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(
		const TSharedPtr<FTcpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("TCP Socket")
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
