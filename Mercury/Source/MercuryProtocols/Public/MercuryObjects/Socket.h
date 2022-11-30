// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryEnums/SocketConnectionState.h"
#include "MercuryEnums/SocketReceiveFlags.h"
#include "MercuryEnums/SocketShutdownMode.h"
#include "MercuryEnums/SocketType.h"
#include "MercuryEnums/SocketWaitCondition.h"
#include "MercuryResourceOwner.h"

#include "Socket.generated.h"

class UMercuryInternetAddr;


/** General socket that can be used for any protocol */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Socket")
class MERCURYPROTOCOLS_API UMercurySocket : public UObject, public TResourceOwner<FSocket, FName, FString, bool>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a socket resource.
	 *
	 * @param Arguments Tuple containing SocketType, SocketDescription and bForceUDP
	 * @return The FSocket object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateSocket
	 */
	virtual TSharedPtr<FSocket> CreateResource(const std::tuple<FName, FString, bool>& Arguments) override;

	/**
	 * Creates a socket resource using other types.
	 *
	 * @param Arguments Tuple containing SocketType, SocketDescription and ProtocolName
	 * @return The FSocket object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateSocket
	 */
	virtual TSharedPtr<FSocket> CreateResourceWithProtocol(const std::tuple<FName, FString, FName>& Arguments);

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Socket|Object", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/**
	 * Accepts a pending connection.
	 *
	 * @param InSocketDescription Description of socket for debugging purposes
	 * @return A new socket or NULL if failed
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Accept", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Accept Out Addr Address In Description"
	))
	virtual UMercurySocket* Accept(const FString& InSocketDescription);

	/**
	 * Accepts a pending connection.
	 *
	 * @param OutAddr Connection address
	 * @param InSocketDescription Description of socket for debugging purposes
	 * @return A new socket or NULL if failed
	 */
	virtual UMercurySocket* Accept(UMercuryInternetAddr* const& OutAddr, const FString& InSocketDescription);

	/**
	 * Bind to a network address.
	 *
	 * @param Addr Address to bind to
	 * @return Did the binding succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Bind", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Bind Addr Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Bind(const UMercuryInternetAddr* const& Addr);

	/**
	 * Close the socket.
	 *
	 * @return Did the socket close without error?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Close", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Close"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Close();

	/**
	 * Connect to a network address.
	 *
	 * @param Addr Address to connect to
	 * @return Was the connection successful?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Connect", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Connect Addr Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Connect(const UMercuryInternetAddr* const& Addr);

	/**
	 * Listens for incoming connections.
	 *
	 * @param MaxBacklog Number of connections to queue before refusing them
	 * @return Is the socket listening?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Listen", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Listen Max Backlog"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Listen(int32 MaxBacklog);

	/**
	 * Reads a chunk of data.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Flags Receive options
	 * @return Was data received?
	 */
	virtual bool Recv(
		uint8*& Data,
		const int32& BufferSize,
		int32& BytesRead,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

	/**
	 * Sends a chunk of data.
	 *
	 * @param Data Buffer to send
	 * @param Count Amount of data to send
	 * @param BytesSent Number of bytes actually sent
	 * @return Was data sent?
	 */
	virtual bool Send(const uint8* const& Data, const int32& Count, int32& BytesSent);

	/**
	 * Shuts the socket down using a certain mode.
	 *
	 * @param Mode Method to shut down
	 * @return Was the socket shut down?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Shutdown", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Shutdown Mode"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Shutdown(EMercurySocketShutdownMode Mode);

	/**
	 * Waits until a condition is met.
	 *
	 * @param Condition Condition to wait for
	 * @param WaitTime Maximum time to wait
	 * @return Was the condition met within the time limit?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Wait", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Wait Condition Timespan Time"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Wait(EMercurySocketWaitCondition Condition, const FTimespan& WaitTime);

	/**
	 * Obtains the bound address.
	 *
	 * @param OutAddr Address the socket is bound to
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Socket Object Get Addr Address Out"
	))
	virtual void GetAddress(UMercuryInternetAddr*& OutAddr) const;

	/**
	 * Obtains the debug description of the socket.
	 *
	 * @return The FString object containing the description
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Description", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Description",
		Keywords = "Socket Object Get Description"
	))
	virtual FString GetDescription() const;

	/**
	 * Obtains the protocol name of the socket.
	 *
	 * @return The FName object containing the protocol type
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Protocol", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Protocol",
		Keywords = "Socket Object Get Protocol"
	))
	virtual FName GetProtocol() const;

	/**
	 * Reads a chunk of data from a network address and obtains it.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Source Receiving address of the sender
	 * @param Flags Receive options
	 * @return Was data received?
	 */
	virtual bool RecvFrom(
		uint8*& Data,
		const int32& BufferSize,
		int32& BytesRead,
		UMercuryInternetAddr*& Source,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

	/**
	 * Reads multiple packets at once with optional platform-specific data.
	 *
	 * @param MultiData Container for received data
	 * @param Flags Receive options
	 * @return Was data received?
	 */
	virtual bool RecvMulti(
		FRecvMulti& MultiData,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

	/**
	 * Sends a chunk of data to a network address.
	 *
	 * @param Data Buffer to send
	 * @param Count Amount of data to send
	 * @param BytesSent Number of bytes actually sent
	 * @param Destination Address to send data to
	 * @return Was data sent?
	 */
	virtual bool SendTo(
		const uint8* const& Data,
		const int32& Count,
		int32& BytesSent,
		const UMercuryInternetAddr* const& Destination
	);

	/**
	 * Sets the socket into broadcast mode.
	 *
	 * @param bAllowBroadcast Should broadcast be enabled?
	 * @return Was data sent?
	 *
	 * @note Can only be used for UDP.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Broadcast", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Broadcast Allow"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetBroadcast(bool bAllowBroadcast = true);

	/**
	 * Sets how long the socket can linger before closing it.
	 *
	 * @param bShouldLinger Can the socket linger?
	 * @param Timeout Amount of time to linger
	 * @return Did setting the linger succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Linger", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Linger Should Timeout"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetLinger(bool bShouldLinger = true, int32 Timeout = 0);

	/**
	 * Obtains the state of the socket's connection.
	 *
	 * @return The connection state of the socket
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Connection State", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Connection State",
		Keywords = "Socket Object Get Connection State"
	))
	virtual EMercurySocketConnectionState GetConnectionState() const;

	/**
	 * Obtains the address of the peer the socket is connected to.
	 *
	 * @param OutAddr Address of the peer
	 * @return Was the peer address returned successfully?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Peer Address", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Peer Address",
		Keywords = "Socket Object Get Peer Address Out Addr"
	))
	virtual UPARAM(DisplayName = "Success") bool
	GetPeerAddress(UMercuryInternetAddr*& OutAddr) const;

	/**
	 * Obtains the port this socket is bound to.
	 *
	 * @return The bound port
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Port No.", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Port No.",
		Keywords = "Socket Object Get Port No Number"
	))
	virtual int32 GetPortNo() const;

	/**
	 * Obtains the type of protocol this socket is bound to.
	 *
	 * @return The protocol
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Socket Type", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Socket Type",
		Keywords = "Socket Object Get Socket Type"
	))
	virtual EMercurySocketType GetSocketType() const;

	/**
	 * Queries the socket to determine if there's a pending connection.
	 *
	 * @param bHasPendingConnection Is there a connection pending?
	 * @return Was the query successful?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Has Pending Connection", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Has Pending Connection"
	))
	virtual UPARAM(DisplayName = "Success") bool
	HasPendingConnection(bool& bHasPendingConnection) const;

	/**
	 * Queries the socket to determine if there's pending data.
	 *
	 * @param PendingDataSize Size of data pending in one call
	 * @return Does the socket have data?
	 */
	virtual bool HasPendingData(uint32& PendingDataSize) const;

	/**
	 * Joins this socket to the specified multicast group using an interface.
	 *
	 * @param GroupAddress Address of the multicast group
	 * @param InterfaceAddress Address representing the interface
	 * @return Did the socket successfully join the group?
	 *
	 * @note The multicast group address must be between 224.0.0.0 and 239.255.255.255.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Join Multicast Group", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Join Multicast Group Address Interface"
	))
	virtual UPARAM(DisplayName = "Success") bool
	JoinMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress = nullptr
	);

	/**
	 * Removes this socket from the specified multicast group using an interface.
	 *
	 * @param GroupAddress Address of the multicast group
	 * @param InterfaceAddress Address representing the interface
	 * @return Did the socket successfully leave the group?
	 *
	 * @note The multicast group address must be between 224.0.0.0 and 239.255.255.255.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Leave Multicast Group", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Leave Multicast Group Address Interface"
	))
	virtual UPARAM(DisplayName = "Success") bool
	LeaveMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress = nullptr
	);

	/**
	 * Sets a new interface address for sending outgoing multicast datagrams.
	 *
	 * @param InterfaceAddress Address representing the new interface
	 * @return Was the new interface successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast Interface", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast Interface Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastInterface(const UMercuryInternetAddr* const& InterfaceAddress);

	/**
	 * Sets multicast loopback on the socket.
	 *
	 * @param bLoopback Should loopback be enabled?
	 * @return Was loopback successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast Loopback", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast Loopback"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastLoopback(bool bLoopback);

	/**
	 * Sets the time to live for multicast datagrams.
	 *
	 * @param TimeToLive Number of hops the datagram can make
	 * @return Was TTL successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast TTL", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast TTL Time To Live"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastTtl(uint8 TimeToLive);

	/**
	 * Sets this socket into TCP_NODELAY mode.
	 *
	 * @param bIsNoDelay Should the no delay mode be enabled?
	 * @return Was the no delay mode successfully set?
	 *
	 * @note Can only be used with TCP.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set No Delay", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Is No Delay"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetNoDelay(bool bIsNoDelay = true);

	/**
	 * Sets this socket into non-blocking mode.
	 *
	 * @param bIsNonBlocking Should the non-blocking mode be enabled?
	 * @return Was the non-blocking mode successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Non Blocking", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Is Non Blocking"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetNonBlocking(bool bIsNonBlocking = true);

	/**
	 * Sets error queue support for the socket.
	 *
	 * @param bUseErrorQueue Should error queuing be enabled?
	 * @return Was the error queue support successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Error", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Receive Err Error Use Queue"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetRecvErr(bool bUseErrorQueue = true);

	/**
	 * Sets if this socket can retrieve system-level receive timestamps.
	 *
	 * @param bRetrieveTimestamp Should timestamps be retrieved on receive?
	 * @return Was the option to retrieve timestamps successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Retrieve Timestamp", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Retrieve Timestamp"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetRetrieveTimestamp(bool bRetrieveTimestamp = true);

	/**
	 * Sets if this socket can be bound to an address in use.
	 *
	 * @param bAllowReuse Can the socket bind to an address in use?
	 * @return Was the reuse option successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Reuse Address", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Reuse Addr Address Allow"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetReuseAddr(bool bAllowReuse = true);

	/**
	 * Sets IP_PKTINFO support.
	 *
	 * @param bEnable Is IP_PKTINFO support enabled?
	 * @return Was the option successfully set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set IP Packet Info", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set IP Pkt Packet Info Enable"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetIpPktInfo(bool bEnable);

	/**
	 * Sets how much data the socket can receive.
	 *
	 * @param Size Amount to change to
	 * @param NewSize Amount that can be held
	 * @return Was the size set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Buffer Size", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Receive Buffer Size New"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetReceiveBufferSize(int32 Size, int32& NewSize);

	/**
	 * Sets how much data the socket can send.
	 *
	 * @param Size Amount to change to
	 * @param NewSize Amount that can be held
	 * @return Was the size set?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Send Buffer Size", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Send Buffer Size New"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetSendBufferSize(int32 Size, int32& NewSize);

	/**
	 * Waits for a pending connection on the socket.
	 *
	 * @param bHasPendingConnection Is there a connection pending?
	 * @param WaitTime Maximum amount of time to wait
	 * @return Did the connection finish in time?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Wait For Pending Connection", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Wait For Pending Connection Time"
	))
	virtual UPARAM(DisplayName = "Success") bool
	WaitForPendingConnection(bool& bHasPendingConnection, const FTimespan& WaitTime) const;

	/**
	 * Reads a chunk of data from a network address and obtains it with its destination.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Source Receiving address of the sender
	 * @param Destination Destination address used by the sender
	 * @param Flags Receive options
	 * @return Was data received?
	 */
	virtual bool RecvFromWithPktInfo(
		uint8*& Data,
		const int32& BufferSize,
		int32& BytesRead,
		UMercuryInternetAddr*& Source,
		UMercuryInternetAddr*& Destination,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

protected:
	/**
	 * Accepts a pending connection.
	 *
	 * @param OutAddr Connection address
	 * @param InSocketDescription Description of socket for debugging purposes
	 * @return A new socket or NULL if failed
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Accept With Address", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Accept With Address Out Addr In Description"
	))
	virtual UMercurySocket* K2_Accept(UMercuryInternetAddr* const& OutAddr, const FString& InSocketDescription);

	/**
	 * Reads a chunk of data.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Flags Receive options
	 * @return Was data received?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Recv", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Recv Data Buffer Size Bytes Read Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_Recv(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);

	/**
	 * Sends a chunk of data.
	 *
	 * @param Data Buffer to send
	 * @param Count Amount of data to send
	 * @param BytesSent Number of bytes actually sent
	 * @return Was data sent?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Send Data Count Bytes Sent"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_Send(const TArray<uint8>& Data, int32 Count, int32& BytesSent);

	/**
	 * Reads a chunk of data from a network address and obtains it.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Source Receiving address of the sender
	 * @param Flags Receive options
	 * @return Was data received?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Recv From", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Recv From Data Buffer Size Bytes Read Source Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_RecvFrom(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		UMercuryInternetAddr*& Source,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);

	/**
	 * Sends a chunk of data to a network address.
	 *
	 * @param Data Buffer to send
	 * @param Count Amount of data to send
	 * @param BytesSent Number of bytes actually sent
	 * @param Destination Address to send data to
	 * @return Was data sent?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Send To", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Send Data Count Bytes Sent Destination"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_SendTo(
		const TArray<uint8>& Data,
		int32 Count,
		int32& BytesSent,
		const UMercuryInternetAddr* const& Destination
	);

	/**
	 * Queries the socket to determine if there's pending data.
	 *
	 * @param PendingDataSize Size of data pending in one call
	 * @return Does the socket have data?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Has Pending Data", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Has Pending Data Size"
	))
	virtual bool K2_HasPendingData(int32& PendingDataSize) const;

	/**
	 * Reads a chunk of data from a network address and obtains it with its destination.
	 *
	 * @param Data Buffer to read into
	 * @param BufferSize Maximum amount of data to receive
	 * @param BytesRead Number of bytes actually read
	 * @param Source Receiving address of the sender
	 * @param Destination Destination address used by the sender
	 * @param Flags Receive options
	 * @return Was data received?
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Recv From With Packet Info", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Recv From With Packet Info Data Buffer Size Bytes Read Source Destination Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_RecvFromWithPktInfo(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		UMercuryInternetAddr*& Source,
		UMercuryInternetAddr*& Destination,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);
};
