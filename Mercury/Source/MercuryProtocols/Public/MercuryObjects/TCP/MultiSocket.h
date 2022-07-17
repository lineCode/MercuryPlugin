﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryResourceOwner.h"
#include "MultichannelTcpSocket.h"

#include "MultiSocket.generated.h"


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multi Socket")
class MERCURYPROTOCOLS_API UMercuryTcpMultiSocket
: public UObject, public TResourceOwner<FMultichannelTcpSocket, FSocket*, uint64>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FMultichannelTcpSocket> CreateResource(const std::tuple<FSocket*, uint64>& Arguments) override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;
	
	virtual void Send(const uint8* const& Data, const int32& Count, const uint32& Channel);
	virtual int32 BlockingReceive(uint8*& Data, const int32& Count, const uint32& Channel);
	virtual int32 DataAvailable(const uint32& Channel);
	virtual int32 PollingReceive(uint8*& Data, const int32& MaxCount, const uint32& Channel);

protected:
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Send Data Count Channel"
	))
	virtual void K2_Send(const TArray<uint8>& Data, int32 Count, int32 Channel);

	UFUNCTION(BlueprintCallable, DisplayName = "Blocking Receive", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Blocking Receive Data Count Channel"
	))
	virtual UPARAM(DisplayName = "Bytes Read") int32
	K2_BlockingReceive(TArray<uint8>& Data, int32 Count, int32 Channel);

	UFUNCTION(BlueprintPure, DisplayName = "Data Available", Category = "TCP|Multi|Socket", meta = (
		CompactNodeTitle = "Buffer Size",
		Keywords = "Protocols TCP Multi Multichannel Socket Check Data Available Channel"
	))
	virtual UPARAM(DisplayName = "Buffer Size") int32
	K2_DataAvailable(int32 Channel);

	UFUNCTION(BlueprintCallable, DisplayName = "Blocking Receive", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Polling Receive Data Max Count Channel"
	))
	virtual UPARAM(DisplayName = "Bytes Read") int32
	K2_PollingReceive(TArray<uint8>& Data, int32 MaxCount, int32 Channel);
};