// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpHeaderReceived.generated.h"

class UMercuryHttpRequest;


/**
 * Mercury implementation of FHttpRequestHeaderReceivedDelegate to allow Blueprints integration
 *
 * @param Request Original HTTP request 
 * @param HeaderName Name of request header
 * @param NewHeaderValue Value of request header
 *
 * @see FHttpRequestHeaderReceivedDelegate
 */
UDELEGATE(BlueprintCallable, DisplayName = "Header Received Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpHeaderReceivedDelegate,
	UMercuryHttpRequest* const&, Request,
	const FString&, HeaderName,
	const FString&, NewHeaderValue
);
