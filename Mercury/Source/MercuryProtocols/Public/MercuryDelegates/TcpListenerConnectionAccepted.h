// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpListenerConnectionAccepted.generated.h"

class UMercuryNetworkEndpoint;
class UMercurySocket;


/**
 * Mercury implementation of FOnTcpListenerConnectionAccepted to allow Blueprints integration
 *
 * @param Socket Connecting socket
 * @param Endpoint Remote IP endpoint
 * @return Should the connection be accepted?
 *
 * @see FOnTcpListenerConnectionAccepted
 */
UDELEGATE(BlueprintCallable, DisplayName = "Connection Accepted Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpListenerConnectionAcceptedDelegate,
	UMercurySocket* const&, Socket,
	UMercuryNetworkEndpoint* const&, Endpoint
);
