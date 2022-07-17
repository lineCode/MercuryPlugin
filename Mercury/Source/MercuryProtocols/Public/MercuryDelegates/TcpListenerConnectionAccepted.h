// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpListenerConnectionAccepted.generated.h"

class UMercuryNetworkEndpoint;
class UMercurySocket;


UDELEGATE(BlueprintCallable, DisplayName = "Connection Accepted Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpListenerConnectionAcceptedDelegate,
	UMercurySocket* const&, Socket,
	UMercuryNetworkEndpoint* const&, Endpoint
);
