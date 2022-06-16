// Copyright (c) 2022 Kaya Adrian

#include "GymEnvironment.h"


void UGymEnvironment::Step()
{
	ExecuteAction();
	UpdateState();
	UpdateReward();
	IsDone();
}
