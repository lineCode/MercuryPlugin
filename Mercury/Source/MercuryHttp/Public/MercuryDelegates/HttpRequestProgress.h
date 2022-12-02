// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpRequestProgress.generated.h"

class UMercuryHttpRequest;


/**
 * Mercury implementation of FHttpRequestProgressDelegate to allow Blueprints integration
 *
 * @param Request Original HTTP request 
 * @param BytesSent Amount of bytes sent
 * @param BytesReceived Amount of bytes received
 *
 * @see FHttpRequestProgressDelegate
 */
UDELEGATE(BlueprintCallable, DisplayName = "Request Progress Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestProgressDelegate,
	UMercuryHttpRequest* const&, Request,
	const int32&, BytesSent,
	const int32&, BytesReceived
);
