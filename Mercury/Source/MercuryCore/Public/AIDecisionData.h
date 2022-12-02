// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "AIDecisionData.generated.h"


/** Container for AI input */
UCLASS(Blueprintable, BlueprintType)
class MERCURYCORE_API UAIDecisionData : public UObject
{
	GENERATED_BODY()

	/** Representation of the AI's actions */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|AI Decision", meta = (AllowPrivateAccess = "true"))
	TArray<double> Input;
	
public:
	/** Checks if the AI wants to reset the environment. */
	UFUNCTION(BlueprintPure, DisplayName = "Wants Reset", Category = "Data|AI Decision", meta = (
		CompactNodeTitle = "Reset?",
		Keywords = "Gym Environment Data AI Decision Server Wants Reset"
	))
	FORCEINLINE bool WantsReset() const { return Input[0u] != 0.0; }
	
	FORCEINLINE const TArray<double>& GetInput() const { return Input; }
	FORCEINLINE TArray<double>& GetInput() { return Input; }
};
