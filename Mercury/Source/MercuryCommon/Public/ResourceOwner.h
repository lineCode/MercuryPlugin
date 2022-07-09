// Copyright (c) 2022 Kaya Adrian

#pragma once


template<typename T, typename... Args>
class TResourceOwner
{
protected:
	TSharedPtr<T> Resource = nullptr;
	
public:
	virtual ~TResourceOwner() = 0;

	virtual TSharedPtr<T> CreateResource();
	virtual TSharedPtr<T> CreateResource(const std::tuple<Args...>&& Arguments);

	FORCEINLINE virtual const TSharedPtr<T>& GetResource() const { return Resource; }
	FORCEINLINE virtual TSharedPtr<T>& GetResource() { return Resource; }
};


template<typename T, typename ... Args>
TResourceOwner<T, Args...>::~TResourceOwner()
{
	Resource.Reset();
}

template<typename T, typename ... Args>
TSharedPtr<T> TResourceOwner<T, Args...>::CreateResource()
{
	return nullptr;
}

template<typename T, typename ... Args>
TSharedPtr<T> TResourceOwner<T, Args...>::CreateResource(const std::tuple<Args...>&& Arguments)
{
	return nullptr;
}
