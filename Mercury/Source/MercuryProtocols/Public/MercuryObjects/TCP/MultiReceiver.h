// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelReceive.h"
#include "MercuryResourceOwner.h"
#include "MultichannelTcpReceiver.h"

#include "MultiReceiver.generated.h"


/** Multi-threaded multichannel socket that receives TCP data */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multi Receiver")
class MERCURYPROTOCOLS_API UMercuryTcpMultiReceiver
: public UObject, public TResourceOwner<FMultichannelTcpReceiver, FSocket*>
{
	GENERATED_BODY()

	/** Invoked when the socket received data */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Receive Event", Category = "TCP|Multi|Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelReceiveDelegate OnMercuryTcpMultichannelReceiveDelegate;

public:
	/**
	 * Creates a multichannel TCP receiver resource.
	 *
	 * @param Arguments Tuple containing InSocket
	 * @return The FMultichannelTcpReceiver object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpMultiReceiver
	 */
	virtual TSharedPtr<FMultichannelTcpReceiver> CreateResource(const std::tuple<FSocket*>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Cleans up the object within the aggregating thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Exit Thread"
	))
	virtual void Exit();

	/**
	 * Initialises the object within the aggregating thread.
	 *
	 * @return Did the initialisation succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return The exit code of the runnable object
	 */
	virtual uint32 Run();

	/** Ends execution within the aggregating thread early. */
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "Protocols TCP Multi Multichannel Receiver Stop Thread"
	))
	virtual void Stop();

	/**
	 * Obtains how many bytes have been received.
	 *
	 * @return The amount of received bytes
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Bytes Received", Category = "TCP|Multi|Receiver", meta = (
		CompactNodeTitle = "Bytes Received",
		Keywords = "Protocols TCP Multi Multichannel Receiver Get Bytes Received"
	))
	virtual int32 GetBytesReceived() const;

	/**
	 * Obtains the interface used when multi-threading is disabled.
	 *
	 * @return The runnable interface
	 */
	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryTcpMultichannelReceiveDelegate
	 */
	virtual void BindReceive(const TArray<uint8>& Data, uint32 BytesReceived, bool bNeedsByteSwap);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multi|Receiver", meta = (
		Keywords = "On Set Receive Delegate Event"
	))
	virtual UMercuryTcpMultiReceiver* K2_SetReceiveEvent(
		const FMercuryTcpMultichannelReceiveDelegate& Event
	);

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return Exit code of the runnable object
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
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
};
