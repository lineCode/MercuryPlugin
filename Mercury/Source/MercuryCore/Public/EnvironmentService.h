// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "EnvironmentService.generated.h"


UINTERFACE(MinimalAPI)
class UEnvironmentService : public UInterface
{
	GENERATED_BODY()
};


class MERCURYCORE_API IEnvironmentService
{
	GENERATED_BODY()

public:
	virtual void ExecuteAction() = 0;
	virtual void UpdateState() = 0;
	virtual void UpdateReward() = 0;
	virtual bool IsDone() = 0;
	virtual void Reset() = 0;
};
