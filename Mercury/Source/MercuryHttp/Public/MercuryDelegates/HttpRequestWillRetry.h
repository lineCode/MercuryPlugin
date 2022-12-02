// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpRequestWillRetry.generated.h"

class UMercuryHttpRequest;
class UMercuryHttpResponse;


/**
 * Mercury implementation of FHttpRequestWillRetryDelegate to allow Blueprints integration
 *
 * @param Request Original HTTP request 
 * @param Response Obtained HTTP response
 * @param SecondsToRetry Amount of time to pass before retrying
 *
 * @see FHttpRequestWillRetryDelegate
 */
UDELEGATE(BlueprintCallable, DisplayName = "Request Will Retry Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpRequestWillRetryDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	const float&, SecondsToRetry
);
