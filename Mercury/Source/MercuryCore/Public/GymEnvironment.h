// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "AIDecisionData.h"
#include "EnvironmentData.h"

#include "GymEnvironment.generated.h"


/** Abstract object responsible for bridging the UE simulation with the external AI */
UCLASS(Abstract, Blueprintable, BlueprintType)
class MERCURYCORE_API AGymEnvironment : public AActor
{
	GENERATED_BODY()

	/** Container object that stores received AI input */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIDecisionData> AIDecisionData;

	/** Container object that stores current environment data */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UEnvironmentData> EnvironmentData;

public:
	/** Creates default containers. */
	explicit AGymEnvironment(const FObjectInitializer& ObjectInitializer);

	/** Ticks the environment. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, DisplayName = "Step", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Next Step"
	))
	void Step();

	/** Defines how to communicate with the external AI to send and receive data. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, DisplayName = "Send Data", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Server Exchange Data Client"
	))
	void ExchangeData();

	/** Defines the AI's action based on its input. */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Execute Action", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Execute Perform Do Action")
	)
	void ExecuteAction();

	/** Sets the new environment state. */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update State", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update Change State")
	)
	void UpdateState();

	/** Sets the reward for the AI's latest action. */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update Reward", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update Change Reward")
	)
	void UpdateReward();

	/** Sets if the current episode should be ended. */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update Done", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update If When Done Finished")
	)
	void UpdateDone();

	/** Defines how to reset the environment to its original state to start a new episode. */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Reset Environment", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Reset")
	)
	void ResetEnvironment();

protected:
	/**
	 * Ticks the environment.
	 *
	 * @note This is used to override AGymEnvironment::Step in C++.
	 */
	virtual void Step_Implementation();

	/**
	 * Defines how to communicate with the external AI to send and receive data.
	 *
	 * @note This is used to override AGymEnvironment::ExchangeData in C++.
	 */
	virtual void ExchangeData_Implementation()
	PURE_VIRTUAL(AGymEnvironment::ExchangeData, return void(););

	/**
	 * Defines the AI's action based on its input.
	 *
	 * @note This is used to override AGymEnvironment::ExecuteAction in C++.
	 */
	virtual void ExecuteAction_Implementation()
	PURE_VIRTUAL(AGymEnvironment::ExecuteAction, return void(););

	/**
	 * Sets the new environment state.
	 *
	 * @note This is used to override AGymEnvironment::UpdateState in C++.
	 */
	virtual void UpdateState_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateState, return void(););

	/**
	 * Sets the reward for the AI's latest action.
	 *
	 * @note This is used to override AGymEnvironment::UpdateReward in C++.
	 */
	virtual void UpdateReward_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateReward, return void(););

	/**
	 * Sets if the current episode should be ended.
	 *
	 * @note This is used to override AGymEnvironment::UpdateDone in C++.
	 */
	virtual void UpdateDone_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateDone, return void(););

	/**
	 * Defines how to reset the environment to its original state to start a new episode.
	 *
	 * @note This is used to override AGymEnvironment::ResetEnvironment in C++.
	 */
	virtual void ResetEnvironment_Implementation()
	PURE_VIRTUAL(AGymEnvironment::ResetEnvironment, return void(););

public:
	FORCEINLINE const TObjectPtr<UAIDecisionData>& GetAIDecisionData() const { return AIDecisionData; }
	FORCEINLINE TObjectPtr<UAIDecisionData>& GetAIDecisionData() { return AIDecisionData; }
	
	FORCEINLINE const TObjectPtr<UEnvironmentData>& GetEnvironmentData() const { return EnvironmentData; }
	FORCEINLINE TObjectPtr<UEnvironmentData>& GetEnvironmentData() { return EnvironmentData; }
};
