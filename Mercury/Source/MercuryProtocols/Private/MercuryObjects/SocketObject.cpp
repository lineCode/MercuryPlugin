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
	if (!HasResource())
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocketObject(ClientSocket) : nullptr;
}
UMercurySocketObject* UMercurySocketObject::Accept(
	UMercuryInternetAddr* const& OutAddr,
	const FString& InSocketDescription
)
{
	if (!HasResource())
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(*OutAddr->GetResource(), InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocketObject(ClientSocket) : nullptr;
}

bool UMercurySocketObject::Bind(const UMercuryInternetAddr* const& Addr)
{
	return HasResource() && Resource->Bind(*Addr->GetResource());
}

bool UMercurySocketObject::Close()
{
	return HasResource() && Resource->Close();
}

bool UMercurySocketObject::Connect(const UMercuryInternetAddr* const& Addr)
{
	return HasResource() && Resource->Connect(*Addr->GetResource());
}

bool UMercurySocketObject::Listen(const int32 MaxBacklog)
{
	return HasResource() && Resource->Listen(MaxBacklog);
}

bool UMercurySocketObject::Recv(
	uint8*& Data,
	const int32& BufferSize,
	int32& BytesRead,
	const EMercurySocketReceiveFlags& Flags
)
{
	BytesRead = 0;
	return HasResource() && Resource->Recv(
		Data,
		BufferSize,
		BytesRead,
		MercuryEnums::SocketReceive::Convert(Flags)
	);
}

bool UMercurySocketObject::Send(const uint8* const& Data, const int32& Count, int32& BytesSent)
{
	BytesSent = 0;
	return HasResource() && Resource->Send(Data, Count, BytesSent);
}

bool UMercurySocketObject::Shutdown(const EMercurySocketShutdownMode Mode)
{
	return HasResource() && Resource->Shutdown(MercuryEnums::SocketShutdown::Convert(Mode));
}

bool UMercurySocketObject::Wait(const EMercurySocketWaitCondition Condition, const FTimespan& WaitTime)
{
	return HasResource() && Resource->Wait(MercuryEnums::SocketWait::Convert(Condition), WaitTime);
}

void UMercurySocketObject::GetAddress(UMercuryInternetAddr*& OutAddr) const
{
	OutAddr = nullptr;
	if (!HasResource())
		return;

	OutAddr = UMercuryNetworkLibrary::CreateInternetAddr();
	Resource->GetAddress(*OutAddr->GetResource());
}

FString UMercurySocketObject::GetDescription() const
{
	return HasResource() ? Resource->GetDescription() : TEXT("");
}

FName UMercurySocketObject::GetProtocol() const
{
	return HasResource() ? Resource->GetProtocol() : TEXT("");
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
	return HasResource() && Resource->RecvFrom(
		Data,
		BufferSize,
		BytesRead,
		*Source->GetResource(),
		MercuryEnums::SocketReceive::Convert(Flags)
	);
}

bool UMercurySocketObject::RecvMulti(FRecvMulti& MultiData, const EMercurySocketReceiveFlags& Flags)
{
	return HasResource() && Resource->RecvMulti(MultiData, MercuryEnums::SocketReceive::Convert(Flags));
}

bool UMercurySocketObject::SendTo(
	const uint8* const& Data,
	const int32& Count,
	int32& BytesSent,
	const UMercuryInternetAddr* const& Destination
)
{
	BytesSent = 0;
	return HasResource() && Resource->SendTo(Data, Count, BytesSent, *Destination->GetResource());
}

bool UMercurySocketObject::SetBroadcast(const bool bAllowBroadcast)
{
	return HasResource() && Resource->SetBroadcast(bAllowBroadcast);
}

bool UMercurySocketObject::SetLinger(const bool bShouldLinger, const int32 Timeout)
{
	return HasResource() && Resource->SetLinger(bShouldLinger, Timeout);
}

EMercurySocketConnectionState UMercurySocketObject::GetConnectionState() const
{
	return MercuryEnums::SocketConnection::Convert(HasResource() ? Resource->GetConnectionState() : SCS_NotConnected);
}

bool UMercurySocketObject::GetPeerAddress(UMercuryInternetAddr*& OutAddr) const
{
	return HasResource() && Resource->GetPeerAddress(*OutAddr->GetResource());
}

int32 UMercurySocketObject::GetPortNo() const
{
	return HasResource() ? Resource->GetPortNo() : 0;
}

EMercurySocketType UMercurySocketObject::GetSocketType() const
{
	return MercuryEnums::SocketType::Convert(HasResource() ? Resource->GetSocketType() : SOCKTYPE_Unknown);
}

bool UMercurySocketObject::HasPendingConnection(bool& bHasPendingConnection) const
{
	bHasPendingConnection = false;
	return HasResource() && Resource->HasPendingConnection(bHasPendingConnection);
}

bool UMercurySocketObject::HasPendingData(uint32& PendingDataSize) const
{
	PendingDataSize = 0u;
	return HasResource() && Resource->HasPendingData(PendingDataSize);
}

bool UMercurySocketObject::JoinMulticastGroup(const UMercuryInternetAddr* const& GroupAddress)
{
	return HasResource() && Resource->JoinMulticastGroup(*GroupAddress->GetResource());
}

bool UMercurySocketObject::JoinMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return HasResource() && Resource->JoinMulticastGroup(
		*GroupAddress->GetResource(),
		*InterfaceAddress->GetResource()
	);
}

bool UMercurySocketObject::LeaveMulticastGroup(const UMercuryInternetAddr* const& GroupAddress)
{
	return HasResource() && Resource->LeaveMulticastGroup(*GroupAddress->GetResource());
}

bool UMercurySocketObject::LeaveMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	return HasResource() && Resource->LeaveMulticastGroup(
		*GroupAddress->GetResource(),
		*InterfaceAddress->GetResource()
	);
}

bool UMercurySocketObject::SetMulticastInterface(const UMercuryInternetAddr* const& InterfaceAddress)
{
	return HasResource() && Resource->SetMulticastInterface(*InterfaceAddress->GetResource());
}

bool UMercurySocketObject::SetMulticastLoopback(const bool bLoopback)
{
	return HasResource() && Resource->SetMulticastLoopback(bLoopback);
}

bool UMercurySocketObject::SetMulticastTtl(const uint8 TimeToLive)
{
	return HasResource() && Resource->SetMulticastTtl(TimeToLive);
}

bool UMercurySocketObject::SetNoDelay(const bool bIsNoDelay)
{
	return HasResource() && Resource->SetNoDelay(bIsNoDelay);
}

bool UMercurySocketObject::SetNonBlocking(const bool bIsNonBlocking)
{
	return HasResource() && Resource->SetNonBlocking(bIsNonBlocking);
}

bool UMercurySocketObject::SetRecvErr(const bool bUseErrorQueue)
{
	return HasResource() && Resource->SetRecvErr(bUseErrorQueue);
}

bool UMercurySocketObject::SetRetrieveTimestamp(const bool bRetrieveTimestamp)
{
	return HasResource() && Resource->SetRetrieveTimestamp(bRetrieveTimestamp);
}

bool UMercurySocketObject::SetReuseAddr(const bool bAllowReuse)
{
	return HasResource() && Resource->SetReuseAddr(bAllowReuse);
}

bool UMercurySocketObject::SetIpPktInfo(const bool bEnable)
{
	return HasResource() && Resource->SetIpPktInfo(bEnable);
}

bool UMercurySocketObject::SetReceiveBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return HasResource() && Resource->SetReceiveBufferSize(Size, NewSize);
}

bool UMercurySocketObject::SetSendBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return HasResource() && Resource->SetSendBufferSize(Size, NewSize);
}

bool UMercurySocketObject::WaitForPendingConnection(bool& bHasPendingConnection, const FTimespan& WaitTime) const
{
	bHasPendingConnection = false;
	return HasResource() && Resource->WaitForPendingConnection(bHasPendingConnection, WaitTime);
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
	return HasResource() && Resource->RecvFromWithPktInfo(
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
