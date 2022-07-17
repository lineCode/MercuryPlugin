// Copyright (c) 2022 Kaya Adrian

#include "Socket.h"

#include "MercuryNetworkLibrary.h"
#include "MercuryProtocolsLibrary.h"
#include "Sockets.h"


bool UMercurySocket::HasResource() const
{
	return Resource != nullptr;
}

UMercurySocket* UMercurySocket::Accept(const FString& InSocketDescription)
{
	if (!HasResource())
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocket(ClientSocket) : nullptr;
}
UMercurySocket* UMercurySocket::Accept(UMercuryInternetAddr* const& OutAddr, const FString& InSocketDescription)
{
	if (!HasResource())
		return nullptr;

	FSocket* const&& ClientSocket = Resource->Accept(*OutAddr->GetResource(), InSocketDescription);
	return ClientSocket ? UMercuryProtocolsLibrary::CreateSocket(ClientSocket) : nullptr;
}

bool UMercurySocket::Bind(const UMercuryInternetAddr* const& Addr)
{
	return HasResource() && Resource->Bind(*Addr->GetResource());
}

bool UMercurySocket::Close()
{
	return HasResource() && Resource->Close();
}

bool UMercurySocket::Connect(const UMercuryInternetAddr* const& Addr)
{
	return HasResource() && Resource->Connect(*Addr->GetResource());
}

bool UMercurySocket::Listen(const int32 MaxBacklog)
{
	return HasResource() && Resource->Listen(MaxBacklog);
}

bool UMercurySocket::Recv(
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

bool UMercurySocket::Send(const uint8* const& Data, const int32& Count, int32& BytesSent)
{
	BytesSent = 0;
	return HasResource() && Resource->Send(Data, Count, BytesSent);
}

bool UMercurySocket::Shutdown(const EMercurySocketShutdownMode Mode)
{
	return HasResource() && Resource->Shutdown(MercuryEnums::SocketShutdown::Convert(Mode));
}

bool UMercurySocket::Wait(const EMercurySocketWaitCondition Condition, const FTimespan& WaitTime)
{
	return HasResource() && Resource->Wait(MercuryEnums::SocketWait::Convert(Condition), WaitTime);
}

void UMercurySocket::GetAddress(UMercuryInternetAddr*& OutAddr) const
{
	OutAddr = nullptr;
	if (!HasResource())
		return;

	OutAddr = UMercuryNetworkLibrary::CreateInternetAddr();
	Resource->GetAddress(*OutAddr->GetResource());
}

FString UMercurySocket::GetDescription() const
{
	return HasResource() ? Resource->GetDescription() : TEXT("");
}

FName UMercurySocket::GetProtocol() const
{
	return HasResource() ? Resource->GetProtocol() : TEXT("");
}

bool UMercurySocket::RecvFrom(
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

bool UMercurySocket::RecvMulti(FRecvMulti& MultiData, const EMercurySocketReceiveFlags& Flags)
{
	return HasResource() && Resource->RecvMulti(MultiData, MercuryEnums::SocketReceive::Convert(Flags));
}

bool UMercurySocket::SendTo(
	const uint8* const& Data,
	const int32& Count,
	int32& BytesSent,
	const UMercuryInternetAddr* const& Destination
)
{
	BytesSent = 0;
	return HasResource() && Resource->SendTo(Data, Count, BytesSent, *Destination->GetResource());
}

bool UMercurySocket::SetBroadcast(const bool bAllowBroadcast)
{
	return HasResource() && Resource->SetBroadcast(bAllowBroadcast);
}

bool UMercurySocket::SetLinger(const bool bShouldLinger, const int32 Timeout)
{
	return HasResource() && Resource->SetLinger(bShouldLinger, Timeout);
}

EMercurySocketConnectionState UMercurySocket::GetConnectionState() const
{
	return MercuryEnums::SocketConnection::Convert(HasResource() ? Resource->GetConnectionState() : SCS_NotConnected);
}

bool UMercurySocket::GetPeerAddress(UMercuryInternetAddr*& OutAddr) const
{
	return HasResource() && Resource->GetPeerAddress(*OutAddr->GetResource());
}

int32 UMercurySocket::GetPortNo() const
{
	return HasResource() ? Resource->GetPortNo() : 0;
}

EMercurySocketType UMercurySocket::GetSocketType() const
{
	return MercuryEnums::SocketType::Convert(HasResource() ? Resource->GetSocketType() : SOCKTYPE_Unknown);
}

bool UMercurySocket::HasPendingConnection(bool& bHasPendingConnection) const
{
	bHasPendingConnection = false;
	return HasResource() && Resource->HasPendingConnection(bHasPendingConnection);
}

bool UMercurySocket::HasPendingData(uint32& PendingDataSize) const
{
	PendingDataSize = 0u;
	return HasResource() && Resource->HasPendingData(PendingDataSize);
}

bool UMercurySocket::JoinMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	const FInternetAddr* const&& GroupResource = GroupAddress->GetResource().Get();
	if (!HasResource() || !GroupResource)
		return false;

	if (!InterfaceAddress)
		return Resource->JoinMulticastGroup(*GroupResource);

	const FInternetAddr* const&& InterfaceResource = InterfaceAddress->GetResource().Get();
	return Resource->JoinMulticastGroup(*GroupResource, *InterfaceResource);
}

bool UMercurySocket::LeaveMulticastGroup(
	const UMercuryInternetAddr* const& GroupAddress,
	const UMercuryInternetAddr* const& InterfaceAddress
)
{
	const FInternetAddr* const&& GroupResource = GroupAddress->GetResource().Get();
	if (!HasResource() || !GroupResource)
		return false;

	if (!InterfaceAddress)
		return Resource->LeaveMulticastGroup(*GroupResource);

	const FInternetAddr* const&& InterfaceResource = InterfaceAddress->GetResource().Get();
	return Resource->LeaveMulticastGroup(*GroupResource, *InterfaceResource);
}

bool UMercurySocket::SetMulticastInterface(const UMercuryInternetAddr* const& InterfaceAddress)
{
	const FInternetAddr* const&& InternetResource = InterfaceAddress->GetResource().Get();
	return HasResource() && InternetResource ? Resource->SetMulticastInterface(*InternetResource) : false;
}

bool UMercurySocket::SetMulticastLoopback(const bool bLoopback)
{
	return HasResource() && Resource->SetMulticastLoopback(bLoopback);
}

bool UMercurySocket::SetMulticastTtl(const uint8 TimeToLive)
{
	return HasResource() && Resource->SetMulticastTtl(TimeToLive);
}

bool UMercurySocket::SetNoDelay(const bool bIsNoDelay)
{
	return HasResource() && Resource->SetNoDelay(bIsNoDelay);
}

bool UMercurySocket::SetNonBlocking(const bool bIsNonBlocking)
{
	return HasResource() && Resource->SetNonBlocking(bIsNonBlocking);
}

bool UMercurySocket::SetRecvErr(const bool bUseErrorQueue)
{
	return HasResource() && Resource->SetRecvErr(bUseErrorQueue);
}

bool UMercurySocket::SetRetrieveTimestamp(const bool bRetrieveTimestamp)
{
	return HasResource() && Resource->SetRetrieveTimestamp(bRetrieveTimestamp);
}

bool UMercurySocket::SetReuseAddr(const bool bAllowReuse)
{
	return HasResource() && Resource->SetReuseAddr(bAllowReuse);
}

bool UMercurySocket::SetIpPktInfo(const bool bEnable)
{
	return HasResource() && Resource->SetIpPktInfo(bEnable);
}

bool UMercurySocket::SetReceiveBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return HasResource() && Resource->SetReceiveBufferSize(Size, NewSize);
}

bool UMercurySocket::SetSendBufferSize(const int32 Size, int32& NewSize)
{
	NewSize = 0;
	return HasResource() && Resource->SetSendBufferSize(Size, NewSize);
}

bool UMercurySocket::WaitForPendingConnection(bool& bHasPendingConnection, const FTimespan& WaitTime) const
{
	bHasPendingConnection = false;
	return HasResource() && Resource->WaitForPendingConnection(bHasPendingConnection, WaitTime);
}

bool UMercurySocket::RecvFromWithPktInfo(
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

UMercurySocket* UMercurySocket::K2_Accept(UMercuryInternetAddr* const& OutAddr, const FString& InSocketDescription)
{
	return Accept(OutAddr, InSocketDescription);
}

bool UMercurySocket::K2_Recv(
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

bool UMercurySocket::K2_Send(const TArray<uint8>& Data, const int32 Count, int32& BytesSent)
{
	return Send(Data.GetData(), Count, BytesSent);
}

bool UMercurySocket::K2_RecvFrom(
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

bool UMercurySocket::K2_SendTo(
	const TArray<uint8>& Data,
	const int32 Count,
	int32& BytesSent,
	const UMercuryInternetAddr* const& Destination
)
{
	return SendTo(Data.GetData(), Count, BytesSent, Destination);
}

bool UMercurySocket::K2_HasPendingData(int32& PendingDataSize) const
{
	return HasPendingData(reinterpret_cast<uint32&>(PendingDataSize));
}

bool UMercurySocket::K2_RecvFromWithPktInfo(
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
