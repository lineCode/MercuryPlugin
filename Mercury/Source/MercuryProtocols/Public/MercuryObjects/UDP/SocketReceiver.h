// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/UdpSocketReceiver.h"
#include "MercuryDelegates/UdpSocketDataReceived.h"
#include "MercuryResourceOwner.h"

#include "SocketReceiver.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Receiver")
class MERCURYPROTOCOLS_API UMercuryUdpSocketReceiver
: public UObject, public TResourceOwner<FUdpSocketReceiver, FSocket*, FTimespan, const TCHAR*>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Data Received Event", Category = "UDP|Socket Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryUdpSocketDataReceivedDelegate OnMercuryUdpSocketDataReceivedDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Data Received", Category = "UDP|Socket Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bDataReceivedDone : 1;

public:
	virtual TSharedPtr<FUdpSocketReceiver> CreateResource(
		const std::tuple<FSocket*, FTimespan, const TCHAR*>& Arguments
	) override;
	explicit UMercuryUdpSocketReceiver(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Start", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Start Begin"
	))
	virtual void Start();

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Stop Thread"
	))
	virtual void Stop();

	virtual FSingleThreadRunnable* GetSingleThreadInterface();
	virtual void SetMaxReadBufferSize(const uint32& InMaxReadBufferSize);

protected:
	virtual void BindDataReceived(const FArrayReaderPtr& Data, const FIPv4Endpoint& Endpoint);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "UDP|Socket Receiver", meta = (
		Keywords = "On Set Data Received Delegate Event"
	))
	virtual UMercuryUdpSocketReceiver* K2_SetDataReceivedEvent(const FMercuryUdpSocketDataReceivedDelegate& Event);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Set Max Read Buffer Size", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver In Set Max Read Buffer Size"
	))
	virtual void K2_SetMaxReadBufferSize(int32 InMaxReadBufferSize);

public:
	FORCEINLINE const FMercuryUdpSocketDataReceivedDelegate& OnDataReceived() const
	{
		return OnMercuryUdpSocketDataReceivedDelegate;
	}
	FORCEINLINE FMercuryUdpSocketDataReceivedDelegate& OnDataReceived()
	{
		return OnMercuryUdpSocketDataReceivedDelegate;
	}

	FORCEINLINE bool IsDataReceivedDone() const { return bDataReceivedDone; }
};
