// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "AIDecisionData.h"
#include "EnvironmentData.h"

#include "GymEnvironment.generated.h"


UCLASS(Abstract, Blueprintable, BlueprintType)
class MERCURYCORE_API AGymEnvironment : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIDecisionData> AIDecisionData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gym|Environment", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UEnvironmentData> EnvironmentData;

public:
	explicit AGymEnvironment(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, DisplayName = "Step", Category = "Gym|Environment", meta = (
		Keywords = "Gym Environment Execute Perform Do Next Step"
	))
	void Step();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, DisplayName = "Send Data", Category = "Gym|Environment", meta = (
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
	
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Execute Action", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Execute Perform Do Action")
	)
	void ExecuteAction();

	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update State", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update Change State")
	)
	void UpdateState();

	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update Reward", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update Change Reward")
	)
	void UpdateReward();

	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Update Done", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Update If When Done Finished")
	)
	void UpdateDone();

	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, DisplayName = "Reset Environment", Category = "Gym|Environment",
		meta = (Keywords = "Gym Environment Reset")
	)
	void ResetEnvironment();

protected:
	virtual void Step_Implementation();

	virtual void ExchangeData_Implementation(
		UAIDecisionData*& ServerData,
		UEnvironmentData* const& ClientData = nullptr
	)
	PURE_VIRTUAL(AGymEnvironment::ExchangeData, return void(););

	virtual void ExecuteAction_Implementation()
	PURE_VIRTUAL(AGymEnvironment::ExecuteAction, return void(););

	virtual void UpdateState_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateState, return void(););

	virtual void UpdateReward_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateReward, return void(););

	virtual void UpdateDone_Implementation()
	PURE_VIRTUAL(AGymEnvironment::UpdateDone, return void(););

	virtual void ResetEnvironment_Implementation()
	PURE_VIRTUAL(AGymEnvironment::ResetEnvironment, return void(););

public:
	FORCEINLINE const TObjectPtr<UAIDecisionData>& GetAIDecisionData() const { return AIDecisionData; }
	FORCEINLINE TObjectPtr<UAIDecisionData>& GetAIDecisionData() { return AIDecisionData; }
	
	FORCEINLINE const TObjectPtr<UEnvironmentData>& GetEnvironmentData() const { return EnvironmentData; }
	FORCEINLINE TObjectPtr<UEnvironmentData>& GetEnvironmentData() { return EnvironmentData; }
};
