// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "AIDecisionData.h"
#include "EnvironmentData.h"

#include "GymEnvironment.generated.h"


UCLASS(Abstract, Blueprintable, BlueprintType)
class MERCURYCORE_API UGymEnvironment : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIDecisionData> AIDecisionData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UEnvironmentData> EnvironmentData;

public:
	UFUNCTION(BlueprintNativeEvent, DisplayName = "Step", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Next Step"
	))
	void Step();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Send Data", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Server Exchange Data Client"
	))
	void ExchangeData(UAIDecisionData*& ServerData, UEnvironmentData* const& ClientData = nullptr);
	FORCEINLINE void ExchangeData(
		UAIDecisionData* const& ServerData,
		const UEnvironmentData* const& ClientData = nullptr
	)
	{
		ExchangeData(const_cast<UAIDecisionData*&>(ServerData), const_cast<UEnvironmentData* const&>(ClientData));
	}
	
	UFUNCTION(BlueprintNativeEvent, DisplayName = "Execute Action", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Action"
	))
	void ExecuteAction();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Update State", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Update Change State"
	))
	void UpdateState();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Update Reward", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Update Change Reward"
	))
	void UpdateReward();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Update Done", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Update If When Done Finished"
	))
	void UpdateDone();

	UFUNCTION(BlueprintNativeEvent, DisplayName = "Reset", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Reset"
	))
	void Reset();

protected:
	virtual void Step_Implementation();

	virtual void ExchangeData_Implementation(
		UAIDecisionData*& ServerData,
		UEnvironmentData* const& ClientData = nullptr
	)
	PURE_VIRTUAL(UGymEnvironment::ExchangeData, return void(););

	virtual void ExecuteAction_Implementation()
	PURE_VIRTUAL(UGymEnvironment::ExecuteAction, return void(););

	virtual void UpdateState_Implementation()
	PURE_VIRTUAL(UGymEnvironment::UpdateState, return void(););

	virtual void UpdateReward_Implementation()
	PURE_VIRTUAL(UGymEnvironment::UpdateReward, return void(););

	virtual void UpdateDone_Implementation()
	PURE_VIRTUAL(UGymEnvironment::UpdateDone, return void(););

	virtual void Reset_Implementation()
	PURE_VIRTUAL(UGymEnvironment::Reset, return void(););

public:
	FORCEINLINE const TObjectPtr<const UAIDecisionData>&& GetAIDecisionData() const { return AIDecisionData; }
	FORCEINLINE TObjectPtr<UAIDecisionData>& GetAIDecisionData() { return AIDecisionData; }
	
	FORCEINLINE const TObjectPtr<const UEnvironmentData>&& GetEnvironmentData() const { return EnvironmentData; }
	FORCEINLINE TObjectPtr<UEnvironmentData>& GetEnvironmentData() { return EnvironmentData; }
};
