// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "ResourceOwner.h"

#include "InternetAddr.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Internet Addr")
class MERCURYNETWORK_API UMercuryInternetAddr : public UObject, public TResourceOwner<FInternetAddr, FName>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FInternetAddr> CreateResource() override;
	virtual TSharedPtr<FInternetAddr> CreateResource(const std::tuple<FName>& Arguments) override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|Internet Addr", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;
	
	UFUNCTION(BlueprintCallable, DisplayName = "Clone", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Clone"
	))
	virtual UMercuryInternetAddr* Clone() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Compare Endpoints", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Compare Endpoints In"
	))
	virtual bool CompareEndpoints(const UMercuryInternetAddr* const& InAddr) const;
	
	virtual void GetIp(uint32& OutAddr) const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Network Internet Addr Address Get Port"
	))
	virtual int32 GetPort() const;
	virtual void GetPort(int32& OutPort) const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Valid", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Valid",
		Keywords = "Network Internet Addr Address Is Valid"
	))
	virtual bool IsValid() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set IP (String)", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set IP String Is Valid"
	))
	virtual void SetIp(const FString& InAddr, bool& bIsValid);
	virtual void SetIp(const uint32& InAddr);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Port", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Port"
	))
	virtual void SetPort(int32 InPort);
	
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network Internet Addr Address Cast To String Append Port"
	))
	virtual FString ToString(bool bAppendPort) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Dump Addr Data", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Dump Data"
	))
	virtual void DumpAddrData() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Platform Port", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Platform Port",
		Keywords = "Network Internet Addr Address Get Platform Port"
	))
	virtual int32 GetPlatformPort() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Protocol Type", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Protocol Type",
		Keywords = "Network Internet Addr Address Get Protocol Type"
	))
	virtual FName GetProtocolType() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Raw IP", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Raw IP",
		Keywords = "Network Internet Addr Address Get Raw IP"
	))
	virtual TArray<uint8> GetRawIp() const;

	virtual uint32 GetTypeHash() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set Any Address", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Any Address"
	))
	virtual void SetAnyAddress();

	UFUNCTION(BlueprintCallable, DisplayName = "Set Broadcast Address", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Broadcast Address"
	))
	virtual void SetBroadcastAddress();

	UFUNCTION(BlueprintCallable, DisplayName = "Set Loopback Address", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Loopback Address"
	))
	virtual void SetLoopbackAddress();

	UFUNCTION(BlueprintCallable, DisplayName = "Set Platform Port", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Platform Port In"
	))
	virtual void SetPlatformPort(int32 InPort);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Raw IP", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set Raw IP"
	))
	virtual void SetRawIp(const TArray<uint8>& RawAddr);

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get IP", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "IP",
		Keywords = "Network Internet Addr Address Get IP Out"
	))
	virtual void K2_GetIp(int32& OutAddr) const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set IP (Integer)", Category = "Network|Internet Addr", meta = (
		Keywords = "Network Internet Addr Address Set IP Integer"
	))
	virtual void K2_SetIp(int32 InAddr);

	UFUNCTION(BlueprintPure, DisplayName = "Get Type Hash", Category = "Network|Internet Addr", meta = (
		CompactNodeTitle = "Type Hash",
		Keywords = "Network Internet Addr Address Get Type Hash"
	))
	virtual int32 K2_GetTypeHash() const;
};
