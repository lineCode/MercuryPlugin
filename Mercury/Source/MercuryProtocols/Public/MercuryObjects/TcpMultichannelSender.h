// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryDelegates/TcpMultichannelOkToSend.h"
#include "MercuryResourceOwner.h"
#include "MultichannelTcpSender.h"

#include "TcpMultichannelSender.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multichannel Sender")
class MERCURYPROTOCOLS_API UMercuryTcpMultichannelSender
: public UObject, public TResourceOwner<FMultichannelTcpSender, FSocket*>
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, DisplayName = "OK To Send Event", Category = "TCP|Multichannel|Sender", meta = (
		AllowPrivateAccess = "true"
	))
	FMercuryTcpMultichannelOkToSendDelegate OnMercuryTcpMultichannelOkToSendDelegate;

	UPROPERTY(BlueprintReadOnly, DisplayName = "OK To Send", Category = "TCP|Multichannel|Sender", meta = (
		AllowPrivateAccess = "true"
	))
	uint8 bOkToSendDone : 1;

public:
	virtual TSharedPtr<FMultichannelTcpSender> CreateResource(const std::tuple<FSocket*>& Arguments) override;
	explicit UMercuryTcpMultichannelSender(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Exit", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Exit Thread"
	))
	virtual void Exit();

	UFUNCTION(BlueprintCallable, DisplayName = "Init", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Init Initialise Initialize Begin Start Thread"
	))
	virtual UPARAM(DisplayName = "Success") bool Init();
	
	virtual uint32 Run();
	virtual void Send(const uint8* const& Data, const int32& Count, const uint32& Channel);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Stop", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Stop Thread"
	))
	virtual void Stop();

	UFUNCTION(BlueprintCallable, DisplayName = "Attempt Resume Sending", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Attempt Resume Sending"
	))
	virtual void AttemptResumeSending();

	UFUNCTION(BlueprintPure, DisplayName = "Get Bytes Sent", Category = "TCP|Multichannel|Sender", meta = (
		CompactNodeTitle = "Bytes Sent",
		Keywords = "Protocols TCP Multichannel Sender Get Bytes Received"
	))
	virtual int32 GetBytesSent() const;

	virtual FSingleThreadRunnable* GetSingleThreadInterface();

protected:
	virtual bool BindOkToSend(int32 Count, uint32 Channel);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Set Receive Event", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "On Set OK To Send Delegate Event"
	))
	virtual UMercuryTcpMultichannelSender* K2_SetOkToSendEvent(
		const FMercuryTcpMultichannelOkToSendDelegate& Event
	);
	
	UFUNCTION(BlueprintCallable, DisplayName = "Run", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Run Activate Execute Thread"
	))
	virtual int32 K2_Run();

	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "TCP|Multichannel|Sender", meta = (
		Keywords = "Protocols TCP Multichannel Sender Send Data Count Channel"
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

	FORCEINLINE bool IsOkToSendDone() const { return bOkToSendDone; }
};
