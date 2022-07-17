// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/UdpSocketSender.h"
#include "MercuryResourceOwner.h"

#include "SocketSender.generated.h"

class UMercuryNetworkEndpoint;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Sender")
class MERCURYPROTOCOLS_API UMercuryUdpSocketSender
: public UObject, public TResourceOwner<FUdpSocketSender, FSocket*, const TCHAR*>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FUdpSocketSender> CreateResource(const std::tuple<FSocket*, const TCHAR*>& Arguments) override;
	
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Sender", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Send Data Recipient"
	))
	virtual bool Send(const TArray<uint8>& Data, const UMercuryNetworkEndpoint* const& Recipient);

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Stop Thread"
	))
	virtual void Stop();

	virtual uint32 GetThroughput() const;
	virtual uint32 GetSendRate() const;
	virtual void SetSendRate(const uint32& Rate);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Wait Time", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Set Wait Time Timespan"
	))
	virtual void SetWaitTime(const FTimespan& Timespan);

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	UFUNCTION(BlueprintPure, DisplayName = "Get Throughput", Category = "UDP|Socket Sender", meta = (
		CompactNodeTitle = "Throughput",
		Keywords = "Protocols UDP Socket Sender Get Throughput"
	))
	virtual int32 K2_GetThroughput() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Send Rate", Category = "UDP|Socket Sender", meta = (
		CompactNodeTitle = "Send Rate",
		Keywords = "Protocols UDP Socket Sender Get Send Rate"
	))
	virtual int32 K2_GetSendRate() const;

	UFUNCTION(BlueprintCallable, DisplayName = "Set Send Rate", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Set Send Rate"
	))
	virtual void K2_SetSendRate(int32 Rate);
};
