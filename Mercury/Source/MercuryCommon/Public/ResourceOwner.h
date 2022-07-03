// Copyright (c) 2022 Kaya Adrian

#pragma once


template<typename T>
class TResourceOwner
{
protected:
	TSharedPtr<T> Resource = nullptr;
	
public:
	virtual ~TResourceOwner() = 0
	{
		Resource.Reset();
	}

	FORCEINLINE virtual const TSharedPtr<T>& GetResource() const { return Resource; }
	FORCEINLINE virtual TSharedPtr<T>& GetResource() { return Resource; }
};
