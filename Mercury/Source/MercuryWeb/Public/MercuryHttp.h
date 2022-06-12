// Copyright (c) 2022 Kaya Adrian

#pragma once


class IHttpBase;

template<class THttpBase, std::enable_if_t<std::is_base_of_v<IHttpBase, THttpBase>>* = nullptr>
class MERCURYWEB_API TMercuryHttp
{
protected:
	THttpBase* Reference = nullptr;

public:
	virtual ~TMercuryHttp() = 0 {}
	
	FORCEINLINE const THttpBase* const& GetReference() const { return Reference; }
	FORCEINLINE THttpBase*& GetReference() { return Reference; }
};
