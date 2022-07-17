// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelReceive.h"
#include "MercuryResourceOwner.h"
#include "MultichannelTcpReceiver.h"

#include "MultiReceiver.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multi Receiver")
class MERCURYPROTOCOLS_API UMercuryTcpMultiReceiver
: public UObject, public TResourceOwner<FMultichannelTcpReceiver, FSocket*>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive Event", Category = "TCP|Multi|Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelReceiveDelegate OnMercuryTcpMultichannelReceiveDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive", Category = "TCP|Multi|Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bReceiveDone : 1;

public:
	virtual TSharedPtr<FMultichannelTcpReceiver> CreateResource(const std::tuple<FSocket*>& Arguments) override;
	explicit UMercuryTcpMultiReceiver(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Stop Thread"
	))
	virtual void Stop();

	UFUNCTION(BlueprintPure, DisplayName = "Get Bytes Received", Category = "TCP|Multi|Receiver", meta = (
		CompactNodeTitle = "Bytes Received",
		Keywords = "Protocols TCP Multi Multichannel Receiver Get Bytes Received"
	))
	virtual int32 GetBytesReceived() const;

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	virtual void BindReceive(const TArray<uint8>& Data, uint32 BytesReceived, bool bNeedsByteSwap);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "On Set Receive Delegate Event"
	))
	virtual UMercuryTcpMultiReceiver* K2_SetReceiveEvent(
		const FMercuryTcpMultichannelReceiveDelegate& Event
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Run Activate Execute Thread"
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
