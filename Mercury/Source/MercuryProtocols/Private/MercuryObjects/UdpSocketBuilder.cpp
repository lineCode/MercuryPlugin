// Copyright (c) 2022 Kaya Adrian

#include "UdpSocketBuilder.h"

#include "Common/UdpSocketBuilder.h"
#include "MercuryProtocolsLibrary.h"
#include "MercuryObjects/NetworkAddress.h"
#include "MercuryObjects/NetworkEndpoint.h"


TSharedPtr<FUdpSocketBuilder> UMercuryUdpSocketBuilder::CreateResource(const std::tuple<FString>& Arguments)
{
	return MakeShareable(new FUdpSocketBuilder(std::get<0>(Arguments)));
}

bool UMercuryUdpSocketBuilder::HasResource() const
{
	return Resource != nullptr;
}

UMercurySocketObject* UMercuryUdpSocketBuilder::Build()
{
	return HasResource() ? UMercuryProtocolsLibrary::CreateSocketObject(Resource->Build()) : nullptr;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::AsBlocking()
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->AsBlocking();
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::AsReusable()
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->AsReusable();
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::AsNonBlocking()
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->AsNonBlocking();
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::BoundToAddress(const UMercuryNetworkAddress* const& Address)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->BoundToAddress(*Address->GetResource());
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->BoundToEndpoint(*Endpoint->GetResource());
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::BoundToPort(const int32 Port)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->BoundToPort(Port);
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::JoinedToGroup(
	const UMercuryNetworkAddress* const& GroupAddress,
	const UMercuryNetworkAddress* const& InterfaceAddress
)
{
	const FIPv4Address* const&& GroupResource = GroupAddress->GetResource().Get();
	if (!HasResource() || !GroupResource)
		return nullptr;

	if (!InterfaceAddress)
	{
		*Resource = Resource->JoinedToGroup(*GroupResource);
		return this;
	}

	const FIPv4Address* const&& InterfaceResource = InterfaceAddress->GetResource().Get();
	*Resource = Resource->JoinedToGroup(*GroupResource, *InterfaceResource);
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::WithMulticastInterface(
	const UMercuryNetworkAddress* const& InterfaceAddress
)
{
	const FIPv4Address* const&& InterfaceResource = InterfaceAddress->GetResource().Get();
	if (!HasResource() || !InterfaceResource)
		return nullptr;
	
	*Resource = Resource->WithMulticastInterface(*InterfaceResource);
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::WithMulticastLoopback()
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->WithMulticastLoopback();
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::WithMulticastTtl(const uint8 TimeToLive)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->WithMulticastTtl(TimeToLive);
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::WithReceiveBufferSize(const int32 SizeInBytes)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->WithReceiveBufferSize(SizeInBytes);
	return this;
}

UMercuryUdpSocketBuilder* UMercuryUdpSocketBuilder::WithSendBufferSize(const int32 SizeInBytes)
{
	if (!HasResource())
		return nullptr;

	*Resource = Resource->WithSendBufferSize(SizeInBytes);
	return this;
}
