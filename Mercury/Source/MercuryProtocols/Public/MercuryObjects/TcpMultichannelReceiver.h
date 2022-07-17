// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelReceive.h"
#include "MercuryResourceOwner.h"
#include "MultichannelTcpReceiver.h"

#include "TcpMultichannelReceiver.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multichannel Receiver")
class MERCURYPROTOCOLS_API UMercuryTcpMultichannelReceiver
: public UObject, public TResourceOwner<FMultichannelTcpReceiver, FSocket*>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive Event", Category = "TCP|Multichannel|Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelReceiveDelegate OnMercuryTcpMultichannelReceiveDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive", Category = "TCP|Multichannel|Receiver", meta = (
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
	
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "On Set Receive Delegate Event"
	))
	virtual UMercuryTcpMultichannelReceiver* K2_SetReceiveEvent(
		const FMercuryTcpMultichannelReceiveDelegate& Event
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Multichannel|Receiver", meta = (
		Keywords = "Protocols TCP Multichannel Receiver Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

public:
	FORCEINLINE const FMercuryTcpMultichannelReceiveDelegate& OnReceive() const
	{
		return OnMercuryTcpMultichannelReceiveDelegate;
	}
	FORCEINLINE FMercuryTcpMultichannelReceiveDelegate& OnReceive()
	{
		return OnMercuryTcpMultichannelReceiveDelegate;
	}

	FORCEINLINE bool IsReceiveDone() const { return bReceiveDone; }
};
