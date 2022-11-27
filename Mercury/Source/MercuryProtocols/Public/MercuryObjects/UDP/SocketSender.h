// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/UdpSocketSender.h"
#include "MercuryResourceOwner.h"

#include "SocketSender.generated.h"

class UMercuryNetworkEndpoint;


/** Multi-threaded socket that sends UDP data */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Sender")
class MERCURYPROTOCOLS_API UMercuryUdpSocketSender
: public UObject, public TResourceOwner<FUdpSocketSender, FSocket*, const TCHAR*>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a UDP socket sender resource.
	 *
	 * @param Arguments Tuple containing InSocket and ThreadDescription
	 * @return The FUdpSocketSender object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateUdpSocketSender
	 */
	virtual TSharedPtr<FUdpSocketSender> CreateResource(const std::tuple<FSocket*, const TCHAR*>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Sender", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Cleans up the object within the aggregating thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Exit Thread"
	))
	virtual void Exit();

	/**
	 * Initialises the object within the aggregating thread.
	 *
	 * @return Did the initialisation succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return The exit code of the runnable object
	 */
	virtual uint32 Run();

	/**
	 * Sends data to a specified recipient.
	 *
	 * @param Data Buffer to send
	 * @param Recipient Location to send data to
	 * @return Will the data be sent?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Send Data Recipient"
	))
	virtual bool Send(const TArray<uint8>& Data, const UMercuryNetworkEndpoint* const& Recipient);

	/** Ends execution within the aggregating thread early. */
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Stop Thread"
	))
	virtual void Stop();

	/** Obtains throughput in bytes per second. */
	virtual uint32 GetThroughput() const;

	/** Obtains maximum send rate in bytes per second. */
	virtual uint32 GetSendRate() const;

	/**
	 * Sets the maximum send rate.
	 *
	 * @param Rate New send rate in bytes per second
	 *
	 * @note Setting Rate to 0 will make the send rate unlimited.
	 */
	virtual void SetSendRate(const uint32& Rate);

	/**
	 * Sets the maximum time span to wait for work items.
	 *
	 * @param Timespan Amount of time to wait
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Wait Time", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Set Wait Time Timespan"
	))
	virtual void SetWaitTime(const FTimespan& Timespan);

	/**
	 * Obtains the interface used when multi-threading is disabled.
	 *
	 * @return The runnable interface
	 */
	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return Exit code of the runnable object
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	/**
	 * Obtains throughput in bytes per second.
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Throughput", Category = "UDP|Socket Sender", meta = (
		CompactNodeTitle = "Throughput",
		Keywords = "Protocols UDP Socket Sender Get Throughput"
	))
	virtual int32 K2_GetThroughput() const;

	/**
	 * Obtains maximum send rate in bytes per second.
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Send Rate", Category = "UDP|Socket Sender", meta = (
		CompactNodeTitle = "Send Rate",
		Keywords = "Protocols UDP Socket Sender Get Send Rate"
	))
	virtual int32 K2_GetSendRate() const;

	/**
	 * Sets the maximum send rate.
	 *
	 * @param Rate New send rate in bytes per second
	 *
	 * @note Setting Rate to 0 will make the send rate unlimited.
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Send Rate", Category = "UDP|Socket Sender", meta = (
		Keywords = "Protocols UDP Socket Sender Set Send Rate"
	))
	virtual void K2_SetSendRate(int32 Rate);
};
