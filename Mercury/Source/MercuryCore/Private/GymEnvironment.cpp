// Copyright (c) 2022 Kaya Adrian

#include "GymEnvironment.h"


void UGymEnvironment::Step_Implementation()
{
	if (AIDecisionData->WantsReset())
	{
		Reset();
	}
	else
	{
		ExecuteAction();
		UpdateReward();
		UpdateDone();
	}
	
	UpdateState();
	ExchangeData(AIDecisionData.Get(), EnvironmentData.Get());
}
