// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "EnvironmentData.generated.h"


UCLASS(Blueprintable, BlueprintType)
class MERCURYCORE_API UEnvironmentData : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Environment", meta = (AllowPrivateAccess = "true"))
	TArray<double> State;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Environment", meta = (AllowPrivateAccess = "true"))
	double Reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Environment", meta = (AllowPrivateAccess = "true"))
	uint8 bIsDone : 1;
	
public:
	FORCEINLINE const TArray<double>& GetState() const { return State; }
	FORCEINLINE TArray<double>& GetState() { return State; }
	
	FORCEINLINE const double& GetReward() const { return Reward; }
	FORCEINLINE void SetReward(const double& Value) { Reward = Value; }

	FORCEINLINE bool&& IsDone() const { return bIsDone; }
	FORCEINLINE void SetDone(const bool& bValue) { bIsDone = bValue; }
};
