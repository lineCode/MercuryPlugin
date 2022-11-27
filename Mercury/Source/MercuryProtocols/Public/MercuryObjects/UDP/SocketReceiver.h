// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/UdpSocketReceiver.h"
#include "MercuryDelegates/UdpSocketDataReceived.h"
#include "MercuryResourceOwner.h"

#include "SocketReceiver.generated.h"


/** Multi-threaded socket that receives UDP data */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Receiver")
class MERCURYPROTOCOLS_API UMercuryUdpSocketReceiver
: public UObject, public TResourceOwner<FUdpSocketReceiver, FSocket*, FTimespan, const TCHAR*>
{
	GENERATED_BODY()

	/** Invoked when the socket received data */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Data Received Event", Category = "UDP|Socket Receiver", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryUdpSocketDataReceivedDelegate OnMercuryUdpSocketDataReceivedDelegate;

public:
	/**
	 * Creates a UDP socket receiver resource.
	 *
	 * @param Arguments Tuple containing InSocket, InWaitTime and InThreadName
	 * @return The FUdpSocketReceiver object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateUdpSocketReceiver
	 */
	virtual TSharedPtr<FUdpSocketReceiver> CreateResource(
		const std::tuple<FSocket*, FTimespan, const TCHAR*>& Arguments
	) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Cleans up the object within the aggregating thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Exit Thread"
	))
	virtual void Exit();

	/**
	 * Initialises the object within the aggregating thread.
	 *
	 * @return Did the initialisation succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return The exit code of the runnable object
	 */
	virtual uint32 Run();

	/** Creates and starts the runnable thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Start", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Start Begin"
	))
	virtual void Start();

	/** Ends execution within the aggregating thread early. */
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Stop Thread"
	))
	virtual void Stop();

	/**
	 * Obtains the interface used when multi-threading is disabled.
	 *
	 * @return The runnable interface
	 */
	virtual FSingleThreadRunnable* GetSingleThreadInterface();
	
	/**
	 * Sets how many bytes the socket is allowed to read at once.
	 *
	 * @param InMaxReadBufferSize Amount of bytes that can be read
	 */
	virtual void SetMaxReadBufferSize(const uint32& InMaxReadBufferSize);

protected:
	/**
	 * Bridges the Mercury delegate execution to the UE one.
	 * 
	 * @see FMercuryUdpSocketDataReceivedDelegate
	 */
	virtual void BindDataReceived(const FArrayReaderPtr& Data, const FIPv4Endpoint& Endpoint);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "UDP|Socket Receiver", meta = (
		Keywords = "On Set Data Received Delegate Event"
	))
	virtual UMercuryUdpSocketReceiver* K2_SetDataReceivedEvent(const FMercuryUdpSocketDataReceivedDelegate& Event);

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return Exit code of the runnable object
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "UDP|Socket Receiver", meta = (
		Keywords = "Protocols UDP Socket Receiver Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	/**
	 * Sets how many bytes the socket is allowed to read at once.
	 *
	 * @param InMaxReadBufferSize Amount of bytes that can be read
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
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
};
