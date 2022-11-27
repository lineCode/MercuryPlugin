// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelOkToSend.h"
#include "MercuryResourceOwner.h"
#include "MultichannelTcpSender.h"

#include "MultiSender.generated.h"


/** Multi-threaded multichannel socket that sends TCP data */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multi Sender")
class MERCURYPROTOCOLS_API UMercuryTcpMultiSender
: public UObject, public TResourceOwner<FMultichannelTcpSender, FSocket*>
{
	GENERATED_BODY()

	/** Invoked when the socket is sending data */
	UPROPERTY(BlueprintReadOnly, DisplayName = "OK To Send Event", Category = "TCP|Multi|Sender", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelOkToSendDelegate OnMercuryTcpMultichannelOkToSendDelegate;

public:
	/**
	 * Creates a multichannel TCP sender resource.
	 *
	 * @param Arguments Tuple containing InSocket
	 * @return The FMultichannelTcpSender object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpMultiSender
	 */
	virtual TSharedPtr<FMultichannelTcpSender> CreateResource(const std::tuple<FSocket*>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Cleans up the object within the aggregating thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Exit Thread"
	))
	virtual void Exit();

	/**
	 * Initialises the object within the aggregating thread.
	 *
	 * @return Did the initialisation succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return The exit code of the runnable object
	 */
	virtual uint32 Run();

	/**
	 * Sends data through a channel without blocking on bandwidth or failing.
	 *
	 * @param Data Buffer to send
	 * @param Count Number of bytes in the buffer
	 * @param Channel Given channel
	 */
	virtual void Send(const uint8* const& Data, const int32& Count, const uint32& Channel);

	/** Ends execution within the aggregating thread early. */
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Stop Thread"
	))
	virtual void Stop();

	/** Retries bandwidth tests to possibly send data if available. */
	UFUNCTION(BlueprintCallable, DisplayName = "Attempt Resume Sending", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Attempt Resume Sending"
	))
	virtual void AttemptResumeSending();

	/**
	 * Obtains how many bytes have been sent.
	 *
	 * @return The amount of sent bytes
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Bytes Sent", Category = "TCP|Multi|Sender", meta = (
		CompactNodeTitle = "Bytes Sent",
		Keywords = "Protocols TCP Multi Multichannel Sender Get Bytes Received"
	))
	virtual int32 GetBytesSent() const;

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
	 * @see FMercuryTcpMultichannelOkToSendDelegate
	 */
	virtual bool BindOkToSend(int32 Count, uint32 Channel);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multi|Sender", meta = (
		Keywords = "On Set OK To Send Delegate Event"
	))
	virtual UMercuryTcpMultiSender* K2_SetOkToSendEvent(
		const FMercuryTcpMultichannelOkToSendDelegate& Event
	);

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return Exit code of the runnable object
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	/**
	 * Sends data through a channel without blocking on bandwidth or failing.
	 *
	 * @param Data Buffer to send
	 * @param Count Number of bytes in the buffer
	 * @param Channel Given channel
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "TCP|Multi|Sender", meta = (
		Keywords = "Protocols TCP Multi Multichannel Sender Send Data Count Channel"
	))
	virtual void K2_Send(const TArray<uint8>& Data, int32 Count, int32 Channel);

public:
	FORCEINLINE const FMercuryTcpMultichannelOkToSendDelegate& OnOkToSend() const
	{
		return OnMercuryTcpMultichannelOkToSendDelegate;
	}
	FORCEINLINE FMercuryTcpMultichannelOkToSendDelegate& OnOkToSend()
	{
		return OnMercuryTcpMultichannelOkToSendDelegate;
	}
};
