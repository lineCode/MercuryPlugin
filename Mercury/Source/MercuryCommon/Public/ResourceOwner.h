// Copyright (c) 2022 Kaya Adrian

#pragma once


template<typename T>
class TResourceOwner
{
protected:
	TSharedPtr<T> Resource = nullptr;
	
public:
	FORCEINLINE const TSharedPtr<T>& GetResource() const { return Resource; }
	FORCEINLINE TSharedPtr<T>& GetResource() { return Resource; }
};
