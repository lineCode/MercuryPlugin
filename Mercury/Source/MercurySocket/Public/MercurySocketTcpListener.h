// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/TcpListener.h"
#include "ResourceOwner.h"

#include "MercurySocketTcpListener.generated.h"

class UMercuryNetworkEndpoint;
class UMercurySocketObject;


UDELEGATE(BlueprintCallable, DisplayName = "Connection Accepted Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpListenerConnectionAcceptedDelegate,
	UMercurySocketObject* const&, Socket,
	UMercuryNetworkEndpoint* const&, Endpoint
);


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Socket TCP Listener")
class MERCURYSOCKET_API UMercurySocketTcpListener
: public UObject, public TResourceOwner<FTcpListener, FSocket*, FTimespan, bool>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "Connection Accepted Event", Category = "Socket|TCP Listener", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpListenerConnectionAcceptedDelegate OnMercuryTcpListenerConnectionAcceptedDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "Connection Accepted", Category = "Socket|TCP Listener", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bConnectionAcceptedDone : 1;

public:
	virtual TSharedPtr<FTcpListener> CreateResource(const std::tuple<FSocket*, FTimespan, bool>& Arguments) override;
	explicit UMercurySocketTcpListener(const FObjectInitializer& ObjectInitializer);

	virtual TSharedPtr<FTcpListener> CreateResourceWithEndpoint(
		const std::tuple<FIPv4Endpoint, FTimespan, bool>& Arguments
	);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Socket|TCP Listener", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "Socket|TCP Listener", meta = (
		Keywords = "Socket TCP Listener Exit"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "Socket|TCP Listener", meta = (
		Keywords = "Socket TCP Listener Init Initialise Initialize Begin Start"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "Socket|TCP Listener", meta = (
		Keywords = "Socket TCP Listener Stop"
	))
	virtual void Stop();

	UFUNCTION(BlueprintPure, DisplayName = "Get Socket", Category = "Socket|TCP Listener", meta = (
		CompactNodeTitle = "Socket",
		Keywords = "Socket TCP Listener Get Socket"
	))
	virtual UMercurySocketObject* GetSocket() const;

	UFUNCTION(BlueprintPure, DisplayName = "Is Active", Category = "Socket|TCP Listener", meta = (
		Keywords = "Socket TCP Listener Is Active Activated"
	))
	virtual bool IsActive() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Local Endpoint", Category = "Socket|TCP Listener", meta = (
		CompactNodeTitle = "Local Endpoint",
		Keywords = "Socket TCP Listener Get Local Endpoint"
	))
	virtual UMercuryNetworkEndpoint* GetLocalEndpoint() const;

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	virtual bool BindConnectionAccepted(FSocket* Socket, const FIPv4Endpoint& Endpoint);

	UFUNCTION(
		BlueprintCallable,
		DisplayName = "Set Connection Accepted Event",
		Category = "Socket|TCP Listener",
		meta = (Keywords = "On Set Connection Accepted Delegate Event")
	)
	virtual UMercurySocketTcpListener* K2_SetConnectionAcceptedEvent(
		const FMercuryTcpListenerConnectionAcceptedDelegate& Event
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "Socket|TCP Listener", meta = (
		Keywords = "Socket TCP Listener Run Activate Execute"
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
