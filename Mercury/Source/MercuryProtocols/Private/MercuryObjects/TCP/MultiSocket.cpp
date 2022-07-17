// Copyright (c) 2022 Kaya Adrian

#include "MultiSocket.h"

#include "MercuryProtocolsLibrary.h"


TSharedPtr<FMultichannelTcpSocket> UMercuryTcpMultiSocket::CreateResource(const std::tuple<FSocket*, uint64>& Arguments)
{
	return MakeShareable(new FMultichannelTcpSocket(
		std::get<0>(Arguments),
		std::get<1>(Arguments)
	));
}

bool UMercuryTcpMultiSocket::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryTcpMultiSocket::Send(const uint8* const& Data, const int32& Count, const uint32& Channel)
{
	if (!HasResource())
		return;

	Resource->Send(Data, Count, Channel);
}

int32 UMercuryTcpMultiSocket::BlockingReceive(uint8*& Data, const int32& Count, const uint32& Channel)
{
	return HasResource() ? Resource->BlockingReceive(Data, Count, Channel) : 0;
}

int32 UMercuryTcpMultiSocket::DataAvailable(const uint32& Channel)
{
	return HasResource() ? Resource->DataAvailable(Channel) : 0;
}

int32 UMercuryTcpMultiSocket::PollingReceive(uint8*& Data, const int32& MaxCount, const uint32& Channel)
{
	return HasResource() ? Resource->PollingReceive(Data, MaxCount, Channel) : 0;
}

void UMercuryTcpMultiSocket::K2_Send(const TArray<uint8>& Data, const int32 Count, const int32 Channel)
{
	return Send(Data.GetData(), Count, Channel);
}

int32 UMercuryTcpMultiSocket::K2_BlockingReceive(TArray<uint8>& Data, const int32 Count, const int32 Channel)
{
	uint8*&& ReceivedData = new uint8[Count];
	Data.SetNumUninitialized(Count);

	const int32&& BytesRead = BlockingReceive(ReceivedData, Count, Channel);
	for (int32&& Index = 0; Index < BytesRead; ++Index)
	{
		Data[Index] = ReceivedData[Index];
	}

	delete[] ReceivedData;
	return BytesRead;
}

int32 UMercuryTcpMultiSocket::K2_DataAvailable(const int32 Channel)
{
	return DataAvailable(Channel);
}

int32 UMercuryTcpMultiSocket::K2_PollingReceive(TArray<uint8>& Data, const int32 MaxCount, const int32 Channel)
{
	uint8*&& ReceivedData = new uint8[MaxCount];
	Data.SetNumUninitialized(MaxCount);

	const int32&& BytesRead = PollingReceive(ReceivedData, MaxCount, Channel);
	for (int32&& Index = 0; Index < BytesRead; ++Index)
	{
		Data[Index] = ReceivedData[Index];
	}

	delete[] ReceivedData;
	return BytesRead;
}
