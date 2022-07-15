// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "SocketConnectionAccepted.generated.h"

class UMercuryNetworkEndpoint;
class UMercurySocketObject;


UDELEGATE(BlueprintCallable, DisplayName = "Connection Accepted Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpListenerConnectionAcceptedDelegate,
	UMercurySocketObject* const&, Socket,
	UMercuryNetworkEndpoint* const&, Endpoint
);
