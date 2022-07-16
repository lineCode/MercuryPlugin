// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpMultichannelReceiverReceive.generated.h"


UDELEGATE(BlueprintCallable, DisplayName = "Receive Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryTcpMultichannelReceiverReceiveDelegate,
	const TArray<uint8>&, Data,
	const int32&, BytesReceived,
	bool, bNeedsByteSwap
);
