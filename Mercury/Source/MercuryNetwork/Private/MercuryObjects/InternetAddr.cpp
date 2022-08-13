// Copyright (c) 2022 Kaya Adrian

#include "InternetAddr.h"

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
	return HasResource() ? UMercuryNetworkLibrary::CreateInternetAddr(Resource->Clone()) : nullptr;
}

bool UMercuryInternetAddr::CompareEndpoints(const UMercuryInternetAddr* const& InAddr) const
{
	return HasResource() && Resource->CompareEndpoints(*InAddr->GetResource());
}

void UMercuryInternetAddr::GetIp(uint32& OutAddr) const
{
	OutAddr = 0u;
	if (!HasResource())
		return;
	
	Resource->GetIp(OutAddr);
}

int32 UMercuryInternetAddr::GetPort() const
{
	return HasResource() ? Resource->GetPort() : 0;
}
void UMercuryInternetAddr::GetPort(int32& OutPort) const
{
	if (!HasResource())
		return;

	Resource->GetPort(OutPort);
}

bool UMercuryInternetAddr::IsValid() const
{
	return HasResource() && Resource->IsValid();
}

void UMercuryInternetAddr::SetIp(const FString& InAddr, bool& bIsValid)
{
	bIsValid = false;
	if (!HasResource())
		return;
	
	Resource->SetIp(*InAddr, bIsValid);
}
void UMercuryInternetAddr::SetIp(const uint32& InAddr)
{
	if (!HasResource())
		return;
	
	Resource->SetIp(InAddr);
}

void UMercuryInternetAddr::SetPort(const int32 InPort)
{
	if (!HasResource())
		return;
	
	Resource->SetPort(InPort);
}

FString UMercuryInternetAddr::ToString(const bool bAppendPort) const
{
	return HasResource() ? Resource->ToString(bAppendPort) : TEXT("");
}

void UMercuryInternetAddr::DumpAddrData() const
{
	if (!HasResource())
		return;
	
	Resource->DumpAddrData();
}

int32 UMercuryInternetAddr::GetPlatformPort() const
{
	return HasResource() ? Resource->GetPlatformPort() : 0;
}

FName UMercuryInternetAddr::GetProtocolType() const
{
	return HasResource() ? Resource->GetProtocolType() : TEXT("");
}

TArray<uint8> UMercuryInternetAddr::GetRawIp() const
{
	return HasResource() ? Resource->GetRawIp() : TArray<uint8>({ 0u, 0u, 0u, 0u });
}

uint32 UMercuryInternetAddr::GetTypeHash() const
{
	return HasResource() ? Resource->GetTypeHash() : 0u;
}

void UMercuryInternetAddr::SetAnyAddress()
{
	if (!HasResource())
		return;

	Resource->SetAnyAddress();
}

void UMercuryInternetAddr::SetBroadcastAddress()
{
	if (!HasResource())
		return;

	Resource->SetBroadcastAddress();
}

void UMercuryInternetAddr::SetLoopbackAddress()
{
	if (!HasResource())
		return;

	Resource->SetLoopbackAddress();
}

void UMercuryInternetAddr::SetPlatformPort(const int32 InPort)
{
	if (!HasResource())
		return;

	Resource->SetPlatformPort(InPort);
}

void UMercuryInternetAddr::SetRawIp(const TArray<uint8>& RawAddr)
{
	if (!HasResource())
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
