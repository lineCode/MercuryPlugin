// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MercuryObjects/Socket.h"
#include "MercuryObjects/TCP/Listener.h"
#include "MercuryObjects/TCP/MultiReceiver.h"
#include "MercuryObjects/TCP/MultiSender.h"
#include "MercuryObjects/TCP/MultiSocket.h"
#include "MercuryObjects/TCP/StreamSocketBuilder.h"
#include "MercuryObjects/UDP/DatagramSocketBuilder.h"
#include "MercuryObjects/UDP/SocketReceiver.h"
#include "MercuryObjects/UDP/SocketSender.h"

#include "MercuryProtocolsLibrary.generated.h"


/** Library for creating Mercury Sockets, TCP and UDP objects */
UCLASS(Abstract, DisplayName = "Mercury Protocols Blueprint Function Library")
class MERCURYPROTOCOLS_API UMercuryProtocolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Creates a socket with a default resource.
	 *
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param bForceUDP Should the protocol be overriden with UDP?
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Socket", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object Type Description Force UDP"
	))
	static UMercurySocket* CreateSocket(
		const FName& SocketType,
		const FString& SocketDescription,
		bool bForceUDP = false
	);

	/**
	 * Creates a socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param bForceUDP Should the protocol be overriden with UDP?
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	static UMercurySocket* CreateSocket(
		FSocket* const& Resource,
		const FName& SocketType,
		const FString& SocketDescription,
		bool bForceUDP = false
	);

	/**
	 * Creates a socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param bForceUDP Should the protocol be overriden with UDP?
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	static UMercurySocket* CreateSocket(
		const TSharedPtr<FSocket>& Resource,
		const FName& SocketType,
		const FString& SocketDescription,
		bool bForceUDP = false
	);

	/**
	 * Creates a socket with a default resource.
	 *
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param ProtocolName Protocol name to use
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	static UMercurySocket* CreateSocket(
		const FName& SocketType,
		const FString& SocketDescription,
		const FName& ProtocolName
	);

	/**
	 * Creates a socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param ProtocolName Protocol name to use
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	static UMercurySocket* CreateSocket(
		FSocket* const& Resource,
		const FName& SocketType,
		const FString& SocketDescription,
		const FName& ProtocolName
	);

	/**
	 * Creates a socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param ProtocolName Protocol name to use
	 * @return The resulting UMercurySocket object or NULL if failed
	 */
	static UMercurySocket* CreateSocket(
		const TSharedPtr<FSocket>& Resource,
		const FName& SocketType,
		const FString& SocketDescription,
		const FName& ProtocolName
	);

	/**
	 * Creates a TCP listener with a default resource.
	 *
	 * @param InSocket MercurySocket object
	 * @param InSleepTime Maximum wait time for a pending connection
	 * @param bInReusable Can the socket be reused?
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Listener", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Listener In Socket Sleep Time Reusable"
	))
	static UMercuryTcpListener* CreateTcpListener(
		const UMercurySocket* const& InSocket,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);

	/**
	 * Creates a TCP listener using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket MercurySocket object
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	static UMercuryTcpListener* CreateTcpListener(
		FTcpListener* const& Resource,
		const UMercurySocket* const& InSocket
	);

	/**
	 * Creates a TCP listener using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket MercurySocket object
	 * @param InSleepTime Maximum wait time for a pending connection
	 * @param bInReusable Can the socket be reused?
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	static UMercuryTcpListener* CreateTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);

	/**
	 * Creates a TCP listener with a default resource.
	 *
	 * @param LocalEndpoint Local IP endpoint to listen from
	 * @param InSleepTime Maximum wait time for a pending connection
	 * @param bInReusable Can the socket be reused?
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	static UMercuryTcpListener* CreateTcpListener(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		const bool& bInReusable = true
	);

	/**
	 * Creates a TCP listener using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param LocalEndpoint Local IP endpoint to listen from
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	static UMercuryTcpListener* CreateTcpListener(
		FTcpListener* const& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint
	);

	/**
	 * Creates a TCP listener using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param LocalEndpoint Local IP endpoint to listen from
	 * @param InSleepTime Maximum wait time for a pending connection
	 * @param bInReusable Can the socket be reused?
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 */
	static UMercuryTcpListener* CreateTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);

	/**
	 * Creates a TCP multichannel receiver with a default resource.
	 *
	 * @param InSocket Socket from which to receive
	 * @return The resulting UMercuryTcpMultiReceiver object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Receiver", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Receiver In Socket"
	))
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(const UMercurySocket* const& InSocket);

	/**
	 * Creates a TCP multichannel receiver using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket from which to receive
	 * @return The resulting UMercuryTcpMultiReceiver object or NULL if failed
	 */
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(
		FMultichannelTcpReceiver* const& Resource,
		const UMercurySocket* const& InSocket
	);

	/**
	 * Creates a TCP multichannel receiver using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket from which to receive
	 * @return The resulting UMercuryTcpMultiReceiver object or NULL if failed
	 */
	static UMercuryTcpMultiReceiver* CreateTcpMultiReceiver(
		const TSharedPtr<FMultichannelTcpReceiver>& Resource,
		const UMercurySocket* const& InSocket
	);

	/**
	 * Creates a TCP multichannel sender with a default resource.
	 *
	 * @param InSocket Socket from which to send
	 * @return The resulting UMercuryTcpMultiSender object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Sender", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Sender In Socket"
	))
	static UMercuryTcpMultiSender* CreateTcpMultiSender(const UMercurySocket* const& InSocket);

	/**
	 * Creates a TCP multichannel sender using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket from which to send
	 * @return The resulting UMercuryTcpMultiSender object or NULL if failed
	 */
	static UMercuryTcpMultiSender* CreateTcpMultiSender(
		FMultichannelTcpSender* const& Resource,
		const UMercurySocket* const& InSocket
	);

	/**
	 * Creates a TCP multichannel sender using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket from which to send
	 * @return The resulting UMercuryTcpMultiSender object or NULL if failed
	 */
	static UMercuryTcpMultiSender* CreateTcpMultiSender(
		const TSharedPtr<FMultichannelTcpSender>& Resource,
		const UMercurySocket* const& InSocket
	);

	/**
	 * Creates a TCP multichannel socket with a default resource.
	 *
	 * @param InSocket UMercurySocket object to use
	 * @param InBandwidthLatencyProduct Maximum amount of unacknowledged data to send
	 * @return The resulting UMercuryTcpMultiSocket object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Multi Socket", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Multi Multichannel Socket In Bandwidth Latency Product"
	))
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		const UMercurySocket* const& InSocket,
		int32 InBandwidthLatencyProduct
	);

	/**
	 * Creates a TCP multichannel socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket UMercurySocket object to use
	 * @param InBandwidthLatencyProduct Maximum amount of unacknowledged data to send
	 * @return The resulting UMercuryTcpMultiSocket object or NULL if failed
	 */
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		FMultichannelTcpSocket* const& Resource,
		const UMercurySocket* const& InSocket,
		const uint64& InBandwidthLatencyProduct
	);

	/**
	 * Creates a TCP multichannel socket using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket UMercurySocket object to use
	 * @param InBandwidthLatencyProduct Maximum amount of unacknowledged data to send
	 * @return The resulting UMercuryTcpMultiSocket object or NULL if failed
	 */
	static UMercuryTcpMultiSocket* CreateTcpMultiSocket(
		const TSharedPtr<FMultichannelTcpSocket>& Resource,
		const UMercurySocket* const& InSocket,
		const uint64& InBandwidthLatencyProduct
	);

	/**
	 * Creates a TCP socket builder with a default resource.
	 *
	 * @param InDescription Builder description for debugging purposes
	 * @return The resulting UMercuryTcpSocketBuilder object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Socket Builder", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Socket Builder In Description"
	))
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(const FString& InDescription = TEXT("TCP_Socket"));

	/**
	 * Creates a TCP socket builder using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryTcpSocketBuilder object or NULL if failed
	 */
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(FTcpSocketBuilder* const& Resource);

	/**
	 * Creates a TCP socket builder using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InDescription Builder description for debugging purposes
	 * @return The resulting UMercuryTcpSocketBuilder object or NULL if failed
	 */
	static UMercuryTcpSocketBuilder* CreateTcpSocketBuilder(
		const TSharedPtr<FTcpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("TCP_Socket")
	);

	/**
	 * Creates a UDP socket builder with a default resource.
	 *
	 * @param InDescription Builder description for debugging purposes
	 * @return The resulting UMercuryUdpSocketBuilder object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create UDP Socket Builder", Category = "Mercury|UDP", meta = (
		Keywords = "Create UDP Socket Builder In Description"
	))
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(const FString& InDescription = TEXT("UDP_Socket"));

	/**
	 * Creates a UDP socket builder using an existing resource.
	 *
	 * @param Resource Given resource
	 * @return The resulting UMercuryUdpSocketBuilder object or NULL if failed
	 */
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(FUdpSocketBuilder* const& Resource);

	/**
	 * Creates a UDP socket builder using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InDescription Builder description for debugging purposes
	 * @return The resulting UMercuryUdpSocketBuilder object or NULL if failed
	 */
	static UMercuryUdpSocketBuilder* CreateUdpSocketBuilder(
		const TSharedPtr<FUdpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("UDP_Socket")
	);

	/**
	 * Creates a UDP socket receiver with a default resource.
	 *
	 * @param InSocket Socket to receive data from
	 * @param InWaitTime Amount of time to wait before reading socket data
	 * @param InThreadName Receiver thread name for debugging purposes
	 * @return The resulting UMercuryUdpSocketReceiver object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create UDP Socket Receiver", Category = "Mercury|UDP", meta = (
		Keywords = "Create UDP Socket Receiver In Socket Wait Time Thread Name"
	))
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);

	/**
	 * Creates a UDP socket receiver using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket to receive data from
	 * @param InWaitTime Amount of time to wait before reading socket data
	 * @param InThreadName Receiver thread name for debugging purposes
	 * @return The resulting UMercuryUdpSocketReceiver object or NULL if failed
	 */
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		FUdpSocketReceiver* const& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);

	/**
	 * Creates a UDP socket receiver using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket to receive data from
	 * @param InWaitTime Amount of time to wait before reading socket data
	 * @param InThreadName Receiver thread name for debugging purposes
	 * @return The resulting UMercuryUdpSocketReceiver object or NULL if failed
	 */
	static UMercuryUdpSocketReceiver* CreateUdpSocketReceiver(
		const TSharedPtr<FUdpSocketReceiver>& Resource,
		const UMercurySocket* const& InSocket,
		const FTimespan& InWaitTime,
		const FString& InThreadName
	);

	/**
	 * Creates a UDP socket sender with a default resource.
	 *
	 * @param InSocket Socket to send data to
	 * @param ThreadDescription Description for the thread for debugging purposes
	 * @return The resulting UMercuryUdpSocketSender object or NULL if failed
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create UDP Socket Sender", Category = "Mercury|UDP", meta = (
		Keywords = "Create UDP Socket Sender In Socket Thread Description"
	))
	static UMercuryUdpSocketSender* CreateUdpSocketSender(
		const UMercurySocket* const& InSocket,
		const FString& ThreadDescription
	);

	/**
	 * Creates a UDP socket sender using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket to send data to
	 * @param ThreadDescription Description for the thread for debugging purposes
	 * @return The resulting UMercuryUdpSocketSender object or NULL if failed
	 */
	static UMercuryUdpSocketSender* CreateUdpSocketSender(
		FUdpSocketSender* const& Resource,
		const UMercurySocket* const& InSocket,
		const FString& ThreadDescription
	);

	/**
	 * Creates a UDP socket sender using an existing resource.
	 *
	 * @param Resource Given resource
	 * @param InSocket Socket to send data to
	 * @param ThreadDescription Description for the thread for debugging purposes
	 * @return The resulting UMercuryUdpSocketSender object or NULL if failed
	 */
	static UMercuryUdpSocketSender* CreateUdpSocketSender(
		const TSharedPtr<FUdpSocketSender>& Resource,
		const UMercurySocket* const& InSocket,
		const FString& ThreadDescription
	);

protected:
	/**
	 * Creates a socket with a default resource.
	 *
	 * @param SocketType Name of socket type
	 * @param SocketDescription Socket description for debugging purposes
	 * @param ProtocolName Protocol name to use
	 * @return The resulting UMercurySocket object or NULL if failed
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create Socket (Protocol)", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object Type Description Protocol Name"
	))
	static UMercurySocket* K2_CreateSocketWithProtocol(
		const FName& SocketType,
		const FString& SocketDescription,
		const FName& ProtocolName
	);

	/**
	 * Creates a TCP listener with a default resource.
	 *
	 * @param LocalEndpoint Local IP endpoint to listen from
	 * @param InSleepTime Maximum wait time for a pending connection
	 * @param bInReusable Can the socket be reused?
	 * @return The resulting UMercuryTcpListener object or NULL if failed
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Create TCP Listener (Endpoint)", Category = "Mercury|TCP", meta = (
		Keywords = "Create TCP Listener Local Endpoint In Sleep Time Reusable"
	))
	static UMercuryTcpListener* K2_CreateTcpListenerWithEndpoint(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
};
