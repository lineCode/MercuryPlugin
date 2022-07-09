// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercurySocketConnectionState.h"
#include "MercurySocketReceiveFlags.h"
#include "MercurySocketShutdownMode.h"
#include "MercurySocketType.h"
#include "MercurySocketWaitCondition.h"
#include "ResourceOwner.h"
#include "Sockets.h"

#include "MercurySocketObject.generated.h"

class UMercuryInternetAddr;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Socket Object")
class MERCURYSOCKET_API UMercurySocketObject : public UObject, public TResourceOwner<FSocket>
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Accept", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Accept Out Addr Address In Description"
	))
	virtual UMercurySocketObject* Accept(const FString& InSocketDescription);
	virtual UMercurySocketObject* Accept(
		UMercuryInternetAddr* const& OutAddr,
		const FString& InSocketDescription
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Bind", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Bind Addr Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Bind(const UMercuryInternetAddr* const& Addr);

	UFUNCTION(BlueprintCallable, DisplayName = "Close", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Close"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Close();

	UFUNCTION(BlueprintCallable, DisplayName = "Connect", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Connect Addr Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Connect(const UMercuryInternetAddr* const& Addr);

	UFUNCTION(BlueprintCallable, DisplayName = "Listen", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Listen Max Backlog"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Listen(int32 MaxBacklog);

	virtual bool Recv(
		uint8* const& Data,
		const int32& BufferSize,
		int32& BytesRead,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);
	
	virtual bool Send(const uint8* const& Data, const int32& Count, int32& BytesSent);

	UFUNCTION(BlueprintCallable, DisplayName = "Shutdown", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Shutdown Mode"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Shutdown(EMercurySocketShutdownMode Mode);

	UFUNCTION(BlueprintCallable, DisplayName = "Wait", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Wait Condition Timespan Time"
	))
	virtual UPARAM(DisplayName = "Success") bool
	Wait(EMercurySocketWaitCondition Condition, FTimespan WaitTime);

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Socket Object Get Addr Address Out"
	))
	virtual void GetAddress(UMercuryInternetAddr*& OutAddr) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Description", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Description",
		Keywords = "Socket Object Get Description"
	))
	virtual FString GetDescription() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Protocol", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Protocol",
		Keywords = "Socket Object Get Protocol"
	))
	virtual FName GetProtocol() const;

	virtual bool RecvFrom(
		uint8* const& Data,
		const int32& BufferSize,
		int32& BytesRead,
		const UMercuryInternetAddr* const& Source,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);
	
	virtual bool RecvMulti(
		FRecvMulti& MultiData,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

	virtual bool SendTo(
		const uint8* const& Data,
		const int32& Count,
		int32& BytesSent,
		const UMercuryInternetAddr* const& Destination
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Broadcast", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Broadcast Allow"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetBroadcast(bool bAllowBroadcast = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Linger", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Linger Should Timeout"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetLinger(bool bShouldLinger = true, int32 Timeout = 0);

	UFUNCTION(BlueprintPure, DisplayName = "Get Connection State", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Connection State",
		Keywords = "Socket Object Get Connection State"
	))
	virtual EMercurySocketConnectionState GetConnectionState() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Peer Address", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Peer Address",
		Keywords = "Socket Object Get Peer Address Out Addr"
	))
	virtual UPARAM(DisplayName = "Success") bool
	GetPeerAddress(UMercuryInternetAddr*& OutAddr) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Port No.", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Port No.",
		Keywords = "Socket Object Get Port No Number"
	))
	virtual int32 GetPortNo() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Socket Type", Category = "Socket|Object", meta = (
		CompactNodeTitle = "Socket Type",
		Keywords = "Socket Object Get Socket Type"
	))
	virtual EMercurySocketType GetSocketType() const;

	UFUNCTION(BlueprintPure, DisplayName = "Has Pending Connection", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Has Pending Connection"
	))
	virtual UPARAM(DisplayName = "Success") bool
	HasPendingConnection(bool& bHasPendingConnection) const;

	virtual bool HasPendingData(uint32& PendingDataSize) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Join Multicast Group", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Join Multicast Group Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	JoinMulticastGroup(const UMercuryInternetAddr* const& GroupAddress);
	
	virtual bool JoinMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Leave Multicast Group", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Leave Multicast Group Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	LeaveMulticastGroup(const UMercuryInternetAddr* const& GroupAddress);
	
	virtual bool LeaveMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast Interface", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast Interface Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastInterface(const UMercuryInternetAddr* const& InterfaceAddress);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast Loopback", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast Loopback"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastLoopback(bool bLoopback);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Multicast TTL", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Multicast TTL Time To Live"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetMulticastTtl(uint8 TimeToLive);

	UFUNCTION(BlueprintCallable, DisplayName = "Set No Delay", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Is No Delay"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetNoDelay(bool bIsNoDelay = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Non Blocking", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Is Non Blocking"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetNonBlocking(bool bIsNonBlocking = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Error", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Receive Err Error Use Queue"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetRecvErr(bool bUseErrorQueue = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Retrieve Timestamp", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Retrieve Timestamp"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetRetrieveTimestamp(bool bRetrieveTimestamp = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Reuse Address", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Reuse Addr Address Allow"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetReuseAddr(bool bAllowReuse = true);

	UFUNCTION(BlueprintCallable, DisplayName = "Set IP Packet Info", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set IP Pkt Packet Info Enable"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetIpPktInfo(bool bEnable);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Buffer Size", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Receive Buffer Size New"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetReceiveBufferSize(int32 Size, int32& NewSize);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Send Buffer Size", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Set Send Buffer Size New"
	))
	virtual UPARAM(DisplayName = "Success") bool
	SetSendBufferSize(int32 Size, int32& NewSize);

	UFUNCTION(BlueprintCallable, DisplayName = "Wait For Pending Connection", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Wait For Pending Connection Time"
	))
	virtual UPARAM(DisplayName = "Success") bool
	WaitForPendingConnection(bool& bHasPendingConnection, const FTimespan& WaitTime) const;

	virtual bool RecvFromWithPktInfo(
		uint8* const& Data,
		const int32& BufferSize,
		int32& BytesRead,
		const UMercuryInternetAddr* const& Source,
		const UMercuryInternetAddr* const& Destination,
		const EMercurySocketReceiveFlags& Flags = EMercurySocketReceiveFlags::None
	);

protected:
	UFUNCTION(BlueprintCallable, DisplayName = "Accept With Address", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Accept With Address Out Addr In Description"
	))
	virtual UMercurySocketObject* K2_Accept(UMercuryInternetAddr* const& OutAddr, const FString& InSocketDescription);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Receive", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Receive Data Buffer Size Bytes Read Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_Recv(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Send Data Count Bytes Sent"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_Send(const TArray<uint8>& Data, int32 Count, int32& BytesSent);

	UFUNCTION(BlueprintCallable, DisplayName = "Receive From", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Receive From Data Buffer Size Bytes Read Source Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_RecvFrom(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		const UMercuryInternetAddr* const& Source,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);

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

	UFUNCTION(BlueprintPure, DisplayName = "Has Pending Data", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Has Pending Data Size"
	))
	virtual bool K2_HasPendingData(int32& PendingDataSize) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Join Multicast Group On", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Join Multicast Group On Interface Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_JoinMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Leave Multicast Group On", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Leave Multicast Group On Interface Address"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_LeaveMulticastGroup(
		const UMercuryInternetAddr* const& GroupAddress,
		const UMercuryInternetAddr* const& InterfaceAddress
	);

	UFUNCTION(BlueprintCallable, DisplayName = "Receive From With Packet Info", Category = "Socket|Object", meta = (
		Keywords = "Socket Object Receive From With Packet Info Data Buffer Size Bytes Read Source Destination Flags"
	))
	virtual UPARAM(DisplayName = "Success") bool
	K2_RecvFromWithPktInfo(
		TArray<uint8>& Data,
		int32 BufferSize,
		int32& BytesRead,
		const UMercuryInternetAddr* const& Source,
		const UMercuryInternetAddr* const& Destination,
		EMercurySocketReceiveFlags Flags = EMercurySocketReceiveFlags::None
	);
};
