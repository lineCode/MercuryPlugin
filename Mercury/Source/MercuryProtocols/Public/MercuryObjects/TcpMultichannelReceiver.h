﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelReceiverReceive.h"
#include "MultichannelTcpReceiver.h"
#include "ResourceOwner.h"

#include "TcpMultichannelReceiver.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multichannel Receiver")
class MERCURYPROTOCOLS_API UMercuryTcpMultichannelReceiver
: public UObject, public TResourceOwner<FMultichannelTcpReceiver, FSocket*>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive Event", Category = "TCP|Multichannel|Receive", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelReceiverReceiveDelegate OnMercuryTcpMultichannelReceiverReceiveDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive", Category = "TCP|Multichannel|Receive", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bReceiveDone : 1;

public:
	virtual TSharedPtr<FMultichannelTcpReceiver> CreateResource(const std::tuple<FSocket*>& Arguments) override;
	explicit UMercuryTcpMultichannelReceiver(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "Protocols TCP Multichannel Receiver Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "Protocols TCP Multichannel Receiver Init Initialise Initialize Begin Start Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "Protocols TCP Multichannel Receiver Stop Thread"
	))
	virtual void Stop();

	UFUNCTION(BlueprintPure, DisplayName = "Get Bytes Received", Category = "TCP|Multichannel|Receiver", meta = (
		CompactNodeTitle = "Bytes Received",
		Keywords = "Protocols TCP Multichannel Receiver Get Bytes Received"
	))
	virtual int32 GetBytesReceived() const;

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	virtual void BindReceive(const TArray<uint8>& Data, uint32 BytesReceived, bool bNeedsByteSwap);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multichannel|Receive", meta = (
		Keywords = "On Set Receive Delegate Event"
	))
	virtual UMercuryTcpMultichannelReceiver* K2_SetReceiveEvent(
		const FMercuryTcpMultichannelReceiverReceiveDelegate& Event
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Multichannel|Receive", meta = (
		Keywords = "Protocols TCP Multichannel Receive Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

public:
	FORCEINLINE const FMercuryTcpMultichannelReceiverReceiveDelegate& OnReceive() const
	{
		return OnMercuryTcpMultichannelReceiverReceiveDelegate;
	}
	FORCEINLINE FMercuryTcpMultichannelReceiverReceiveDelegate& OnReceive()
	{
		return OnMercuryTcpMultichannelReceiverReceiveDelegate;
	}

	FORCEINLINE bool IsReceiveDone() const { return bReceiveDone; }
};
