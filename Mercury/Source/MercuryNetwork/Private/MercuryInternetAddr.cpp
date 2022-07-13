// Copyright (c) 2022 Kaya Adrian

#include "MercuryInternetAddr.h"

#include "MercuryNetwork.h"
#include "MercuryNetworkLibrary.h"


TSharedPtr<FInternetAddr> UMercuryInternetAddr::CreateResource()
{
	return FMercuryNetworkModule::GetSocketSubsystem()->CreateInternetAddr();
}
TSharedPtr<FInternetAddr> UMercuryInternetAddr::CreateResource(const std::tuple<FName>& Arguments)
{
	return FMercuryNetworkModule::GetSocketSubsystem()->CreateInternetAddr(std::get<0>(Arguments));
}

bool UMercuryInternetAddr::HasResource() const
{
	return Resource != nullptr;
}

UMercuryInternetAddr* UMercuryInternetAddr::Clone() const
{
	return Resource ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->Clone()) : nullptr;
}

bool UMercuryInternetAddr::CompareEndpoints(const UMercuryInternetAddr* const& InAddr) const
{
	return Resource && Resource->CompareEndpoints(*InAddr->GetResource());
}

void UMercuryInternetAddr::GetIp(uint32& OutAddr) const
{
	OutAddr = 0u;
	if (!Resource)
		return;
	
	Resource->GetIp(OutAddr);
}

int32 UMercuryInternetAddr::GetPort() const
{
	return Resource ? Resource->GetPort() : 0;
}
void UMercuryInternetAddr::GetPort(int32& OutPort) const
{
	if (!Resource)
		return;

	Resource->GetPort(OutPort);
}

bool UMercuryInternetAddr::IsValid() const
{
	return Resource && Resource->IsValid();
}

void UMercuryInternetAddr::SetIp(const FString& InAddr, bool& bIsValid)
{
	bIsValid = false;
	if (!Resource)
		return;
	
	Resource->SetIp(*InAddr, bIsValid);
}
void UMercuryInternetAddr::SetIp(const uint32& InAddr)
{
	if (!Resource)
		return;
	
	Resource->SetIp(InAddr);
}

void UMercuryInternetAddr::SetPort(const int32 InPort)
{
	if (!Resource)
		return;
	
	Resource->SetPort(InPort);
}

FString UMercuryInternetAddr::ToString(const bool bAppendPort) const
{
	return Resource ? Resource->ToString(bAppendPort) : TEXT("");
}

void UMercuryInternetAddr::DumpAddrData() const
{
	if (!Resource)
		return;
	
	Resource->DumpAddrData();
}

int32 UMercuryInternetAddr::GetPlatformPort() const
{
	return Resource ? Resource->GetPlatformPort() : 0;
}

FName UMercuryInternetAddr::GetProtocolType() const
{
	return Resource ? Resource->GetProtocolType() : TEXT("");
}

TArray<uint8> UMercuryInternetAddr::GetRawIp() const
{
	return Resource ? Resource->GetRawIp() : TArray<uint8>({ 0u, 0u, 0u, 0u });
}

uint32 UMercuryInternetAddr::GetTypeHash() const
{
	return Resource ? Resource->GetTypeHash() : 0u;
}

void UMercuryInternetAddr::SetAnyAddress()
{
	if (!Resource)
		return;

	Resource->SetAnyAddress();
}

void UMercuryInternetAddr::SetBroadcastAddress()
{
	if (!Resource)
		return;

	Resource->SetBroadcastAddress();
}

void UMercuryInternetAddr::SetLoopbackAddress()
{
	if (!Resource)
		return;

	Resource->SetLoopbackAddress();
}

void UMercuryInternetAddr::SetPlatformPort(const int32 InPort)
{
	if (!Resource)
		return;

	Resource->SetPlatformPort(InPort);
}

void UMercuryInternetAddr::SetRawIp(const TArray<uint8>& RawAddr)
{
	if (!Resource)
		return;

	Resource->SetRawIp(RawAddr);
}

void UMercuryInternetAddr::K2_GetIp(int32& OutAddr) const
{
	GetIp(reinterpret_cast<uint32&>(OutAddr));
}

void UMercuryInternetAddr::K2_SetIp(const int32 InAddr)
{
	SetIp(InAddr);
}

int32 UMercuryInternetAddr::K2_GetTypeHash() const
{
	return GetTypeHash();
}
