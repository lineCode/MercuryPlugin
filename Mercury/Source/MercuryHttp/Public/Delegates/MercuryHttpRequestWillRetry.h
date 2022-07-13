// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryHttpRequestWillRetry.generated.h"

class UMercuryHttpRequest;
class UMercuryHttpResponse;


UDELEGATE(BlueprintCallable, DisplayName = "Request Will Retry Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestWillRetryDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	const float&, SecondsToRetry
);
