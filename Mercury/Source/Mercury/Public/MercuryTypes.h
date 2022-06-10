// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryTypes.generated.h"


UDELEGATE(BlueprintAuthorityOnly, BlueprintCallable)
DECLARE_DYNAMIC_DELEGATE_ThreeParams(
	FMercuryRequestCompleteDelegate,
	class UMercuryRequest* const&, Request,
	class UMercuryResponse* const&, Response,
	bool, bConnectedSuccessfully
);

UENUM(BlueprintType)
enum class EMercuryRequestStatus : uint8
{
	NotStarted UMETA(DisplayName = "Not Started"),
	Processing UMETA(DisplayName = "Processing"),
	Failed UMETA(DisplayName = "Failed"),
	Failed_ConnectionError UMETA(DisplayName = "Connection Error"),
	Succeeded UMETA(DisplayName = "Succeeded"),
	Unknown UMETA(DisplayName = "Unknown")
};
