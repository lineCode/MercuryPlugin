// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpMultichannelReceive.generated.h"


/**
 * Mercury implementation of FOnMultichannelTcpReceive to allow Blueprints integration
 *
 * @param Data Received bytes
 * @param BytesReceived Number of bytes received
 * @param bNeedsByteSwap Is byte swapping required?
 *
 * @see FOnMultichannelTcpReceive
 */
UDELEGATE(BlueprintCallable, DisplayName = "Receive Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryTcpMultichannelReceiveDelegate,
	const TArray<uint8>&, Data,
	const int32&, BytesReceived,
	bool, bNeedsByteSwap
);
