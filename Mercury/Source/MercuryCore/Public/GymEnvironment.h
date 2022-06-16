// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "EnvironmentService.h"

#include "GymEnvironment.generated.h"


UCLASS(Abstract, Blueprintable, BlueprintType)
class MERCURYCORE_API UGymEnvironment : public UObject, public IEnvironmentService
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Step", Category = "Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Next Step"
	))
	virtual void Step();

protected:
	UFUNCTION(BlueprintCallable, DisplayName = "Execute Action", Category = "Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Action"
	))
	virtual void ExecuteAction() override
	PURE_VIRTUAL(UGymEnvironment::ExecuteAction, return void(););

	UFUNCTION(BlueprintCallable, DisplayName = "Update State", Category = "Environment", meta = (
		Keywords = "Gym Environment Update Change State"
	))
	virtual void UpdateState() override
	PURE_VIRTUAL(UGymEnvironment::Reset, return void(););

	UFUNCTION(BlueprintCallable, DisplayName = "Update Reward", Category = "Environment", meta = (
		Keywords = "Gym Environment Update Change Reward"
	))
	virtual void UpdateReward() override
	PURE_VIRTUAL(UGymEnvironment::Reset, return void(););

	UFUNCTION(BlueprintPure, DisplayName = "Is Done?", Category = "Environment", meta = (
		Keywords = "Gym Environment Check If Is Done Finished"
	))
	virtual bool IsDone() override
	PURE_VIRTUAL(UGymEnvironment::Reset, return false;);

	UFUNCTION(BlueprintCallable, DisplayName = "Reset", Category = "Environment", meta = (
		Keywords = "Gym Environment Reset"
	))
	virtual void Reset() override
	PURE_VIRTUAL(UGymEnvironment::Reset, return void(););
};
