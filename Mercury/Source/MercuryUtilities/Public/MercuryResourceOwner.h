// Copyright (c) 2022 Kaya Adrian

#pragma once


/**
 * Templated interface for managing a resource.
 *
 * @tparam T Resource type
 * @tparam Args Custom types for resource creation
 */
template<typename T, typename... Args>
class TResourceOwner
{
protected:
	/** Resource to hold, initially NULL */
	TSharedPtr<T> Resource = nullptr;
	
public:
	virtual ~TResourceOwner();

	/** Creates a default resource. */
	virtual TSharedPtr<T> CreateResource();
	
	/** Creates a resource using extra arguments. */
	virtual TSharedPtr<T> CreateResource(const std::tuple<Args...>& Arguments);

	/**
	 * @note This function was implemented as pure virtual to force TResourceOwner to be abstract.
	 */
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
