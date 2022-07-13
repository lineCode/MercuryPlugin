// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpRequestProgress.generated.h"

class UMercuryHttpRequest;


UDELEGATE(BlueprintCallable, DisplayName = "Request Progress Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestProgressDelegate,
	UMercuryHttpRequest* const&, Request,
	const int32&, BytesSent,
	const int32&, BytesReceived
);
