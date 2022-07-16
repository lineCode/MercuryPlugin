// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "TcpMultichannelOkToSend.generated.h"


UDELEGATE(BlueprintCallable, DisplayName = "OK To Send Event")
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(
	bool, FMercuryTcpMultichannelOkToSendDelegate,
	const int32&, Count,
	const int32&, Channel
);
