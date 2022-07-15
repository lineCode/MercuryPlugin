// Copyright (c) 2022 Kaya Adrian

#include "SocketObject.h"

#include "MercuryNetworkLibrary.h"
#include "MercuryProtocolsLibrary.h"
#include "Sockets.h"


bool UMercurySocketObject::HasResource() const
{
	return Resource != nullptr;
}

UMercurySocketObject* UMercurySocketObject::Accept(const FString& InSocketDescription)
{
	if (!Resource)
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocketObject(ClientSocket) : nullptr;
}
UMercurySocketObject* UMercurySocketObject::Accept(
	UMercuryInternetAddr* const& OutAddr,
	const FString& InSocketDescription
)
{
	if (!Resource)
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(*OutAddr->GetResource(), InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocketObject(ClientSocket) : nullptr;
}

bool UMercurySocketObject::Bind(const UMercuryInternetAddr* const& Addr)
{
	return Resource && Resource->Bind(*Addr->GetResource());
}

bool UMercurySocketObject::Close()
{
	return Resource && Resource->Close();
}

bool UMercurySocketObject::Connect(const UMercuryInternetAddr* const& Addr)
{
	return Resource && Resource->Connect(*Addr->GetResource());
}

bool UMercurySocketObject::Listen(const int32 MaxBacklog)
{
	return Resource && Resource->Listen(MaxBacklog);
}

bool UMercurySocketObject::Recv(
	uint8*& Data,
	const int32& BufferSize,
	int32& BytesRead,
	const EMercurySocketReceiveFlags& Flags
)
{
	BytesRead = 0;
	return Resource && Resource->Recv(Data, BufferSize, BytesRead, MercuryEnums::SocketReceive::Convert(Flags));
}

bool UMercurySocketObject::Send(const uint8* const& Data, const int32& Count, int32& BytesSent)
{
	BytesSent = 0;
	return Resource && Resource->Send(Data, Count, BytesSent);
}

bool UMercurySocketObject::Shutdown(const EMercurySocketShutdownMode Mode)
{
	return Resource && Resource->Shutdown(MercuryEnums::SocketShutdown::Convert(Mode));
}

bool UMercurySocketObject::Wait(const EMercurySocketWaitCondition Condition, const FTimespan& WaitTime)
{
	return Resource && Resource->Wait(MercuryEnums::SocketWait::Convert(Condition), WaitTime);
}

void UMercurySocketObject::GetAddress(UMercuryInternetAddr*& OutAddr) const
{
	OutAddr = nullptr;
	if (!Resource)
		return;

	OutAddr = UMercuryNetworkLibrary::CreateInternetAddr();
	Resource->GetAddress(*OutAddr->GetResource());
}

FString UMercurySocketObject::GetDescription() const
{
	return Resource ? Resource->GetDescription() : TEXT("");
}

FName UMercurySocketObject::GetProtocol() const
{
	return Resource ? Resource->GetProtocol() : TEXT("");
}

bool UMercurySocketObject::RecvFrom(
	uint8*& Data,
	const int32& BufferSize,
	int32& BytesRead,
	const UMercuryInternetAddr* const& Source,
	const EMercurySocketReceiveFlags& Flags
)
{
	BytesRead = 0;
	return Resource && Resource->RecvFrom(
		Data,
		BufferSize,
		BytesRead,
		*Source->GetResource(),
		MercuryEnums::SocketReceive::Convert(Flags)
	);
}

bool UMercurySocketObject::RecvMulti(FRecvMulti& MultiData, const EMercurySocketReceiveFlags& Flags)
{
	return Resource && Resource->RecvMulti(MultiData, MercuryEnums::SocketReceive::Convert(Flags));
}

bool UMercurySocketObject::SendTo(
	const uint8* const& Data,
	const int32& Count,
	int32& BytesSent,
	const UMercuryInternetAddr* const& Destination
)
{
	BytesSent = 0;
	return Resource && Resource->SendTo(Data, Count, BytesSent, *Destination->GetResource());
}

bool UMercurySocketObject::SetBroadcast(const bool bAllowBroadcast)
{
	return Resource && Resource->SetBroadcast(bAllowBroadcast);
}

bool UMercurySocketObject::SetLinger(const bool bShouldLinger, const int32 Timeout)
{
	return Resource && Resource->SetLinger(bShouldLinger, Timeout);
}

EMercurySocketConnectionState UMercurySocketObject::GetConnectionState() const
{
	return MercuryEnums::SocketConnection::Convert(Resource ? Resource->GetConnectionState() : SCS_NotConnected);
}

bool UMercurySocketObject::GetPeerAddress(UMercuryInternetAddr*& OutAddr) const
{
	return Resource && Resource->GetPeerAddress(*OutAddr->GetResource());
}

int32 UMercurySocketObject::GetPortNo() const
{
	return Resource ? Resource->GetPortNo() : 0;
}

EMercurySocketType UMercurySocketObject::GetSocketType() const
{
	return MercuryEnums::SocketType::Convert(Resource ? Resource->GetSocketType() : SOCKTYPE_Unknown);
}

bool UMercurySocketObject::HasPendingConnection(bool& bHasPendingConnection) const
{
	bHasPendingConnection = false;
	return Resource && Resource->HasPendingConnection(bHasPendingConnection);
}

bool UMercurySocketObject::HasPendingData(uint32& PendingDataSize) const
{
	PendingDataSize = 0u;
	return Resource && Resource->HasPendingData(PendingDataSize);
}

bool UMercurySocketObject::JoinMulticastGroup(const UMercuryInternetAddr* const& GroupAddress)
{
	return Resource && Resource->JoinMulticastGroup(*GroupAddress->GetResource());
}

bool UMercurySocketObject::JoinMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return Resource && Resource->JoinMulticastGroup(
		*GroupAddress->GetResource(),
		*InterfaceAddress->GetResource()
	);
}

bool UMercurySocketObject::LeaveMulticastGroup(const UMercuryInternetAddr* const& GroupAddress)
{
	return Resource && Resource->LeaveMulticastGroup(*GroupAddress->GetResource());
}

bool UMercurySocketObject::LeaveMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return Resource && Resource->LeaveMulticastGroup(
		*GroupAddress->GetResource(),
		*InterfaceAddress->GetResource()
	);
}

bool UMercurySocketObject::SetMulticastInterface(const UMercuryInternetAddr* const& InterfaceAddress)
{
	return Resource && Resource->SetMulticastInterface(*InterfaceAddress->GetResource());
}

bool UMercurySocketObject::SetMulticastLoopback(const bool bLoopback)
{
	return Resource && Resource->SetMulticastLoopback(bLoopback);
}

bool UMercurySocketObject::SetMulticastTtl(const uint8 TimeToLive)
{
	return Resource && Resource->SetMulticastTtl(TimeToLive);
}

bool UMercurySocketObject::SetNoDelay(const bool bIsNoDelay)
{
	return Resource && Resource->SetNoDelay(bIsNoDelay);
}

bool UMercurySocketObject::SetNonBlocking(const bool bIsNonBlocking)
{
	return Resource && Resource->SetNonBlocking(bIsNonBlocking);
}

bool UMercurySocketObject::SetRecvErr(const bool bUseErrorQueue)
{
	return Resource && Resource->SetRecvErr(bUseErrorQueue);
}

bool UMercurySocketObject::SetRetrieveTimestamp(const bool bRetrieveTimestamp)
{
	return Resource && Resource->SetRetrieveTimestamp(bRetrieveTimestamp);
}

bool UMercurySocketObject::SetReuseAddr(const bool bAllowReuse)
{
	return Resource && Resource->SetReuseAddr(bAllowReuse);
}

bool UMercurySocketObject::SetIpPktInfo(const bool bEnable)
{
	return Resource && Resource->SetIpPktInfo(bEnable);
}

bool UMercurySocketObject::SetReceiveBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return Resource && Resource->SetReceiveBufferSize(Size, NewSize);
}

bool UMercurySocketObject::SetSendBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return Resource && Resource->SetSendBufferSize(Size, NewSize);
}

bool UMercurySocketObject::WaitForPendingConnection(bool& bHasPendingConnection, const FTimespan& WaitTime) const
{
	bHasPendingConnection = false;
	return Resource && Resource->WaitForPendingConnection(bHasPendingConnection, WaitTime);
}

bool UMercurySocketObject::RecvFromWithPktInfo(
	uint8*& Data,
	const int32& BufferSize,
	int32& BytesRead,
	const UMercuryInternetAddr* const& Source,
	const UMercuryInternetAddr* const& Destination,
	const EMercurySocketReceiveFlags& Flags
)
{
	BytesRead = 0;
	return Resource && Resource->RecvFromWithPktInfo(
		Data,
		BufferSize,
		BytesRead,
		*Source->GetResource(),
		*Destination->GetResource(),
		MercuryEnums::SocketReceive::Convert(Flags)
	);
}

UMercurySocketObject* UMercurySocketObject::K2_Accept(
	UMercuryInternetAddr* const& OutAddr,
	const FString& InSocketDescription
)
{
	return Accept(OutAddr, InSocketDescription);
}

bool UMercurySocketObject::K2_Recv(
	TArray<uint8>& Data,
	const int32 BufferSize,
	int32& BytesRead,
	const EMercurySocketReceiveFlags Flags
)
{
	uint8*&& ReceivedData = new uint8[BufferSize];
	Data.SetNumUninitialized(BufferSize);
	
	const bool&& bSuccess = Recv(ReceivedData, BufferSize, BytesRead, Flags);
	for (int32&& Index = 0; Index < BytesRead; ++Index)
	{
		Data[Index] = ReceivedData[Index];
	}
	
	delete[] ReceivedData;
	return bSuccess;
}

bool UMercurySocketObject::K2_Send(const TArray<uint8>& Data, const int32 Count, int32& BytesSent)
{
	return Send(Data.GetData(), Count, BytesSent);
}

bool UMercurySocketObject::K2_RecvFrom(
	TArray<uint8>& Data,
	const int32 BufferSize,
	int32& BytesRead,
	const UMercuryInternetAddr* const& Source,
	const EMercurySocketReceiveFlags Flags
)
{
	uint8*&& ReceivedData = new uint8[BufferSize];
	Data.SetNumUninitialized(BufferSize);
	
	const bool&& bSuccess = RecvFrom(ReceivedData, BufferSize, BytesRead, Source, Flags);
	for (int32&& Index = 0; Index < BytesRead; ++Index)
	{
		Data[Index] = ReceivedData[Index];
	}
	
	delete[] ReceivedData;
	return bSuccess;
}

bool UMercurySocketObject::K2_SendTo(
	const TArray<uint8>& Data,
	const int32 Count,
	int32& BytesSent,
	const UMercuryInternetAddr* const& Destination
)
{
	return SendTo(Data.GetData(), Count, BytesSent, Destination);
}

bool UMercurySocketObject::K2_HasPendingData(int32& PendingDataSize) const
{
	return HasPendingData(reinterpret_cast<uint32&>(PendingDataSize));
}

bool UMercurySocketObject::K2_JoinMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return JoinMulticastGroup(GroupAddress, InterfaceAddress);
}

bool UMercurySocketObject::K2_LeaveMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return LeaveMulticastGroup(GroupAddress, InterfaceAddress);
}

bool UMercurySocketObject::K2_RecvFromWithPktInfo(
	TArray<uint8>& Data,
	const int32 BufferSize,
	int32& BytesRead,
	const UMercuryInternetAddr* const& Source,
	const UMercuryInternetAddr* const& Destination,
	const EMercurySocketReceiveFlags Flags
)
{
	uint8*&& ReceivedData = new uint8[BufferSize];
	Data.SetNumUninitialized(BufferSize);
	
	const bool&& bSuccess = RecvFromWithPktInfo(ReceivedData, BufferSize, BytesRead, Source, Destination, Flags);
	for (int32&& Index = 0; Index < BytesRead; ++Index)
	{
		Data[Index] = ReceivedData[Index];
	}
	
	delete[] ReceivedData;
	return bSuccess;
}
