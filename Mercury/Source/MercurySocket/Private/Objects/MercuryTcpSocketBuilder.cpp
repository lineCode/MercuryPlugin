// Copyright (c) 2022 Kaya Adrian

#include "MercuryTcpSocketBuilder.h"

#include "MercuryNetworkAddress.h"
#include "MercuryNetworkEndpoint.h"
#include "MercurySocketLibrary.h"


TSharedPtr<FTcpSocketBuilder> UMercuryTcpSocketBuilder::CreateResource(const std::tuple<FString>& Arguments)
{
	return MakeShareable(new FTcpSocketBuilder(std::get<0>(Arguments)));
}

bool UMercuryTcpSocketBuilder::HasResource() const
{
	return Resource != nullptr;
}

UMercurySocketObject* UMercuryTcpSocketBuilder::Build()
{
	return Resource ? UMercurySocketLibrary::CreateSocketObject(Resource->Build()) : nullptr;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::Lingering(const int32 Timeout)
{
	if (!Resource)
		return nullptr;
	
	*Resource = Resource->Lingering(Timeout);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::Listening(const int32 MaxBacklog)
{
	if (!Resource)
		return nullptr;
	
	*Resource = Resource->Listening(MaxBacklog);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::AsBlocking()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsBlocking();
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::AsReusable()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsReusable();
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::AsReusable(const bool& bInReusable)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsReusable(bInReusable);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::AsNonBlocking()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsNonBlocking();
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::BoundToAddress(const UMercuryNetworkAddress* const& Address)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToAddress(*Address->GetResource());
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToEndpoint(*Endpoint->GetResource());
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::BoundToPort(const int32 Port)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToPort(Port);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::WithReceiveBufferSize(const int32 SizeInBytes)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->WithReceiveBufferSize(SizeInBytes);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::WithSendBufferSize(const int32 SizeInBytes)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->WithSendBufferSize(SizeInBytes);
	return this;
}

UMercuryTcpSocketBuilder* UMercuryTcpSocketBuilder::K2_AsReusable(const bool bInReusable)
{
	return AsReusable(bInReusable);
}
