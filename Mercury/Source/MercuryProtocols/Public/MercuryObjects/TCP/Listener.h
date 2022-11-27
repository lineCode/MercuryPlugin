// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/TcpListener.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "MercuryDelegates/TcpListenerConnectionAccepted.h"
#include "MercuryResourceOwner.h"

#include "Listener.generated.h"


/** Multi-threaded socket that listens to TCP connections */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Listener")
class MERCURYPROTOCOLS_API UMercuryTcpListener
: public UObject, public TResourceOwner<FTcpListener, FSocket*, FTimespan, bool>
{
	GENERATED_BODY()

	/** Invoked when the listener found a new connection */
	UPROPERTY(BlueprintReadOnly, DisplayName = "Connection Accepted Event", Category = "TCP|Listener", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpListenerConnectionAcceptedDelegate OnMercuryTcpListenerConnectionAcceptedDelegate;

public:
	/**
	 * Creates a TCP listener resource.
	 *
	 * @param Arguments Tuple containing InSocket, InSleepTime and bInReusable
	 * @return The FTcpListener object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpListener
	 */
	virtual TSharedPtr<FTcpListener> CreateResource(const std::tuple<FSocket*, FTimespan, bool>& Arguments) override;

	/**
	 * Creates a TCP listener resource using other types.
	 *
	 * @param Arguments Tuple containing LocalEndpoint, InSleepTime and bInReusable
	 * @return The FTcpListener object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpListener
	 */
	virtual TSharedPtr<FTcpListener> CreateResourceWithEndpoint(
		const std::tuple<FIPv4Endpoint, FTimespan, bool>& Arguments
	);

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Listener", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Cleans up the object within the aggregating thread. */
	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Exit Thread"
	))
	virtual void Exit();

	/**
	 * Initialises the object within the aggregating thread.
	 *
	 * @return Did the initialisation succeed?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return The exit code of the runnable object
	 */
	virtual uint32 Run();

	/** Ends execution within the aggregating thread early. */
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Stop Thread"
	))
	virtual void Stop();

	/**
	 * Obtains the listener's network socket.
	 *
	 * @return The UMercurySocket object
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Socket", Category = "TCP|Listener", meta = (
		CompactNodeTitle = "Socket",
		Keywords = "Protocols TCP Listener Get Socket"
	))
	virtual UMercurySocket* GetSocket() const;

	/**
	 * Checks if the listener is online.
	 *
	 * @return Is the listener listening for incoming connections?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Is Active", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Is Active Activated"
	))
	virtual bool IsActive() const;

	/**
	 * Obtains the listener's local IP endpoint.
	 *
	 * @return The UMercuryNetworkEndpoint object
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Local Endpoint", Category = "TCP|Listener", meta = (
		CompactNodeTitle = "Local Endpoint",
		Keywords = "Protocols TCP Listener Get Local Endpoint"
	))
	virtual UMercuryNetworkEndpoint* GetLocalEndpoint() const;

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
	 * @see FMercuryTcpListenerConnectionAcceptedDelegate
	 */
	virtual bool BindConnectionAccepted(FSocket* Socket, const FIPv4Endpoint& Endpoint);

	/** @note This should be used strictly inside Blueprints. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Connection Accepted Event", Category = "TCP|Listener", meta = (
		Keywords = "On Set Connection Accepted Delegate Event"
	))
	virtual UMercuryTcpListener* K2_SetConnectionAcceptedEvent(
		const FMercuryTcpListenerConnectionAcceptedDelegate& Event
	);

	/**
	 * Executes work on the aggregating thread.
	 *
	 * @return Exit code of the runnable object
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

public:
	FORCEINLINE const FMercuryTcpListenerConnectionAcceptedDelegate& OnConnectionAccepted() const
	{
		return OnMercuryTcpListenerConnectionAcceptedDelegate;
	}
	FORCEINLINE FMercuryTcpListenerConnectionAcceptedDelegate& OnConnectionAccepted()
	{
		return OnMercuryTcpListenerConnectionAcceptedDelegate;
	}
};
