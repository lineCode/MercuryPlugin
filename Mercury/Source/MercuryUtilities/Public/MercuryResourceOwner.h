// Copyright (c) 2022 Kaya Adrian

#pragma once


template<typename T, typename... Args>
class TResourceOwner
{
protected:
	TSharedPtr<T> Resource = nullptr;
	
public:
	virtual ~TResourceOwner();

	virtual TSharedPtr<T> CreateResource();
	virtual TSharedPtr<T> CreateResource(const std::tuple<Args...>& Arguments);

	virtual bool HasResource() const = 0;

	FORCEINLINE virtual TSharedPtr<T> GetResource() { return Resource; }
	FORCEINLINE virtual const TSharedPtr<T>& GetResource() const { return Resource; }
	FORCEINLINE virtual void SetResource(const TSharedPtr<T>& Value) { Resource = Value; }
	FORCEINLINE virtual void SetResource(TSharedPtr<T>&& Value) { Resource = Value; }
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
TSharedPtr<T> TResourceOwner<T, Args...>::CreateResource(const std::tuple<Args...>& Arguments)
{
	return nullptr;
}
