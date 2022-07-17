// Copyright (c) 2022 Kaya Adrian

#include "SocketSender.h"

#include "MercuryObjects/NetworkEndpoint.h"


TSharedPtr<FUdpSocketSender> UMercuryUdpSocketSender::CreateResource(
	const std::tuple<FSocket*, const TCHAR*>& Arguments
)
{
	return MakeShareable(new FUdpSocketSender(std::get<0>(Arguments), std::get<1>(Arguments)));
}

bool UMercuryUdpSocketSender::HasResource() const
{
	return Resource != nullptr;
}

void UMercuryUdpSocketSender::Exit()
{
	if (!HasResource())
		return;

	Resource->Exit();
}

bool UMercuryUdpSocketSender::Init()
{
	return HasResource() && Resource->Init();
}

uint32 UMercuryUdpSocketSender::Run()
{
	return HasResource() ? Resource->Run() : 0u;
}

bool UMercuryUdpSocketSender::Send(const TArray<uint8>& Data, const UMercuryNetworkEndpoint* const& Recipient)
{
	const TSharedRef<TArray<uint8>> DataReference;
	DataReference->Append(Data);
	
	const FIPv4Endpoint* const&& RecipientResource = Recipient->GetResource().Get();
	return RecipientResource && HasResource() && Resource->Send(DataReference, *RecipientResource);
}

void UMercuryUdpSocketSender::Stop()
{
	if (!HasResource())
		return;

	Resource->Stop();
}

uint32 UMercuryUdpSocketSender::GetThroughput() const
{
	return HasResource() ? Resource->GetThroughput() : 0u;
}

uint32 UMercuryUdpSocketSender::GetSendRate() const
{
	return HasResource() ? Resource->GetSendRate() : 0u;
}

void UMercuryUdpSocketSender::SetSendRate(const uint32& Rate)
{
	if (!HasResource())
		return;

	Resource->SetSendRate(Rate);
}

void UMercuryUdpSocketSender::SetWaitTime(const FTimespan& Timespan)
{
	if (!HasResource())
		return;

	Resource->SetWaitTime(Timespan);
}

FSingleThreadRunnable* UMercuryUdpSocketSender::GetSingleThreadInterface()
{
	return HasResource() ? Resource->GetSingleThreadInterface() : nullptr;
}

int32 UMercuryUdpSocketSender::K2_Run()
{
	return Run();
}

int32 UMercuryUdpSocketSender::K2_GetThroughput() const
{
	return GetThroughput();
}

int32 UMercuryUdpSocketSender::K2_GetSendRate() const
{
	return GetSendRate();
}

void UMercuryUdpSocketSender::K2_SetSendRate(const int32 Rate)
{
	SetSendRate(Rate);
}
