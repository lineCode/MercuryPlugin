// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpMultichannelOkToSend.generated.h"


/**
 * Mercury implementation of FOnMultichannelTcpOkToSend to allow Blueprints integration
 *
 * @param Count Size of packet
 * @param Channel Place to send packet to
 * @return Does the bandwidth allow the packet to be sent?
 *
 * @see FOnMultichannelTcpOkToSend
 */
UDELEGATE(BlueprintCallable, DisplayName = "OK To Send Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpMultichannelOkToSendDelegate,
	const int32&, Count,
	const int32&, Channel
);
