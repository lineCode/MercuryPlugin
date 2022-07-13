// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "HttpProcessRequestComplete.generated.h"

class UMercuryHttpRequest;
class UMercuryHttpResponse;


UDELEGATE(BlueprintCallable, DisplayName = "Process Request Complete Event")
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryHttpProcessRequestCompleteDelegate,
	UMercuryHttpRequest* const&, Request,
	UMercuryHttpResponse* const&, Response,
	bool, bConnectedSuccessfully
);
