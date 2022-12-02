// Copyright (c) 2022 Kaya Adrian

#include "GymEnvironment.h"


AGymEnvironment::AGymEnvironment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AIDecisionData = CreateDefaultSubobject<UAIDecisionData>("AI Decision Data");
	EnvironmentData = CreateDefaultSubobject<UEnvironmentData>("Environment Data");
}

void AGymEnvironment::Step_Implementation()
{
	if (AIDecisionData->WantsReset())
	{
		ResetEnvironment();
	}
	else
	{
		ExecuteAction();
		UpdateReward();
		UpdateDone();
	}
	
	UpdateState();
	ExchangeData();
}
