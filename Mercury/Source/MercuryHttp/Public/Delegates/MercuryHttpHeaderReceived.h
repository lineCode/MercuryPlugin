// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttpHeaderReceived.generated.h"

class UMercuryHttpRequest;

	
UDELEGATE(BlueprintCallable, DisplayName = "Header Received Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpHeaderReceivedDelegate,
	UMercuryHttpRequest* const&, Request,
	const FString&, HeaderName,
	const FString&, NewHeaderValue
);
