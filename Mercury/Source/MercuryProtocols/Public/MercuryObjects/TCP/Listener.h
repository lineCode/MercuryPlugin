// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/TcpListener.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "MercuryDelegates/TcpListenerConnectionAccepted.h"
#include "MercuryResourceOwner.h"

#include "Listener.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Listener")
class MERCURYPROTOCOLS_API UMercuryTcpListener
: public UObject, public TResourceOwner<FTcpListener, FSocket*, FTimespan, bool>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Connection Accepted Event", Category = "TCP|Listener", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpListenerConnectionAcceptedDelegate OnMercuryTcpListenerConnectionAcceptedDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Connection Accepted", Category = "TCP|Listener", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bConnectionAcceptedDone : 1;

public:
	virtual TSharedPtr<FTcpListener> CreateResource(const std::tuple<FSocket*, FTimespan, bool>& Arguments) override;
	explicit UMercuryTcpListener(const FObjectInitializer& ObjectInitializer);

	virtual TSharedPtr<FTcpListener> CreateResourceWithEndpoint(
		const std::tuple<FIPv4Endpoint, FTimespan, bool>& Arguments
	);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Listener", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Init Initialise Initialize Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Stop Thread"
	))
	virtual void Stop();

	UFUNCTION(BlueprintPure, DisplayName = "Get Socket", Category = "TCP|Listener", meta = (
		CompactNodeTitle = "Socket",
		Keywords = "Protocols TCP Listener Get Socket"
	))
	virtual UMercurySocket* GetSocket() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Active", Category = "TCP|Listener", meta = (
		Keywords = "Protocols TCP Listener Is Active Activated"
	))
	virtual bool IsActive() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Local Endpoint", Category = "TCP|Listener", meta = (
		CompactNodeTitle = "Local Endpoint",
		Keywords = "Protocols TCP Listener Get Local Endpoint"
	))
	virtual UMercuryNetworkEndpoint* GetLocalEndpoint() const;

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	virtual bool BindConnectionAccepted(FSocket* Socket, const FIPv4Endpoint& Endpoint);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Connection Accepted Event", Category = "TCP|Listener", meta = (
		Keywords = "On Set Connection Accepted Delegate Event"
	))
	virtual UMercuryTcpListener* K2_SetConnectionAcceptedEvent(
		const FMercuryTcpListenerConnectionAcceptedDelegate& Event
	);
	
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

	FORCEINLINE bool IsConnectionAcceptedDone() const { return bConnectionAcceptedDone; }
};
