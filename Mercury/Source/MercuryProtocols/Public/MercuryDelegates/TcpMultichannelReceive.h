// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpMultichannelReceive.generated.h"


UDELEGATE(BlueprintCallable, DisplayName = "Receive Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryTcpMultichannelReceiveDelegate,
	const TArray<uint8>&, Data,
	const int32&, BytesReceived,
	bool, bNeedsByteSwap
);
