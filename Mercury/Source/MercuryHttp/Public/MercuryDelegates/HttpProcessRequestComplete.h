// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpProcessRequestComplete.generated.h"

class UMercuryHttpRequest;
class UMercuryHttpResponse;


/**
 * Mercury implementation of FHttpRequestCompleteDelegate to allow Blueprints integration
 *
 * @param Request Original HTTP request 
 * @param Response Obtained HTTP response
 * @param bConnectedSuccessfully Was the request completed successfully?
 *
 * @see FHttpRequestCompleteDelegate
 */
UDELEGATE(BlueprintCallable, DisplayName = "Process Request Complete Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpProcessRequestCompleteDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	bool, bConnectedSuccessfully
);
