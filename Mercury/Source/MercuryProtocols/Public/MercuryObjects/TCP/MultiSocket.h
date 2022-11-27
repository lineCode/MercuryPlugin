// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryResourceOwner.h"
#include "MultichannelTcpSocket.h"

#include "MultiSocket.generated.h"


/** Multichannel socket that can be used for TCP connections */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Multi Socket")
class MERCURYPROTOCOLS_API UMercuryTcpMultiSocket
: public UObject, public TResourceOwner<FMultichannelTcpSocket, FSocket*, uint64>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a multichannel TCP socket resource.
	 *
	 * @param Arguments Tuple containing InSocket and InBandwidthLatencyProduct
	 * @return The FMultichannelTcpSocket object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpMultiSocket
	 */
	virtual TSharedPtr<FMultichannelTcpSocket> CreateResource(const std::tuple<FSocket*, uint64>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/**
	 * Sends data through a channel without blocking on bandwidth or failing.
	 *
	 * @param Data Buffer to send
	 * @param Count Number of bytes in the buffer
	 * @param Channel Given channel
	 *
	 * @note Can be called from any thread, but multi-threading requires sending an atomic unit.
	 */
	virtual void Send(const uint8* const& Data, const int32& Count, const uint32& Channel);

	/**
	 * Blocks until socket receives data through a channel.
	 *
	 * @param Data Buffer to fill
	 * @param Count Number of bytes to receive
	 * @param Channel Given channel
	 * @return The amount of bytes actually received
	 *
	 * @note Can be called from any thread, but multiple threads can't use the same channel at once.
	 */
	virtual int32 BlockingReceive(uint8*& Data, const int32& Count, const uint32& Channel);

	/**
	 * Checks if there is data to read from a channel without blocking.
	 *
	 * @param Channel Given channel
	 * @return The amount of bytes to be read
	 *
	 * @note Can be called from any thread, but another thread can steal the data if it exists.
	 */
	virtual int32 DataAvailable(const uint32& Channel);

	/**
	 * Receives data through a channel without blocking.
	 *
	 * @param Data Buffer to fill
	 * @param MaxCount Number of bytes to receive
	 * @param Channel Given channel
	 * @return The amount of bytes actually received
	 *
	 * @note Can be called from any thread, but multiple threads shouldn't use the same channel at once.
	 */
	virtual int32 PollingReceive(uint8*& Data, const int32& MaxCount, const uint32& Channel);

protected:
	/**
	 * Sends data through a channel without blocking on bandwidth or failing.
	 *
	 * @param Data Buffer to send
	 * @param Count Number of bytes in the buffer
	 * @param Channel Given channel
	 *
	 * @note Can be called from any thread, but multi-threading requires sending an atomic unit.
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Send", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Send Data Count Channel"
	))
	virtual void K2_Send(const TArray<uint8>& Data, int32 Count, int32 Channel);

	/**
	 * Blocks until socket receives data through a channel.
	 *
	 * @param Data Buffer to fill
	 * @param Count Number of bytes to receive
	 * @param Channel Given channel
	 * @return The amount of bytes actually received
	 *
	 * @note Can be called from any thread, but multiple threads can't use the same channel at once.
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Blocking Receive", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Blocking Receive Data Count Channel"
	))
	virtual UPARAM(DisplayName = "Bytes Read") int32
	K2_BlockingReceive(TArray<uint8>& Data, int32 Count, int32 Channel);

	/**
	 * Checks if there is data to read from a channel without blocking.
	 *
	 * @param Channel Given channel
	 * @return The amount of bytes to be read
	 *
	 * @note Can be called from any thread, but another thread can steal the data if it exists.
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Data Available", Category = "TCP|Multi|Socket", meta = (
		CompactNodeTitle = "Buffer Size",
		Keywords = "Protocols TCP Multi Multichannel Socket Check Data Available Channel"
	))
	virtual UPARAM(DisplayName = "Buffer Size") int32
	K2_DataAvailable(int32 Channel);

	/**
	 * Receives data through a channel without blocking.
	 *
	 * @param Data Buffer to fill
	 * @param MaxCount Number of bytes to receive
	 * @param Channel Given channel
	 * @return The amount of bytes actually received
	 *
	 * @note Can be called from any thread, but multiple threads shouldn't use the same channel at once.
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Blocking Receive", Category = "TCP|Multi|Socket", meta = (
		Keywords = "Protocols TCP Multi Multichannel Socket Polling Receive Data Max Count Channel"
	))
	virtual UPARAM(DisplayName = "Bytes Read") int32
	K2_PollingReceive(TArray<uint8>& Data, int32 MaxCount, int32 Channel);
};
