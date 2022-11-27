// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "UdpSocketDataReceived.generated.h"

class UMercuryNetworkEndpoint;


/**
 * Mercury implementation of FOnSocketDataReceived to allow Blueprints integration
 *
 * @param Data Received bytes
 * @param Endpoint Sender IP endpoint
 *
 * @see FOnSocketDataReceived
 */
UDELEGATE(BlueprintCallable, DisplayName = "Data Received Event")
DECLARE_DYNAMIC_DELEGATE_TwoParams(
	FMercuryUdpSocketDataReceivedDelegate,
	const TArray<uint8>&, Data,
	UMercuryNetworkEndpoint* const&, Endpoint
);
