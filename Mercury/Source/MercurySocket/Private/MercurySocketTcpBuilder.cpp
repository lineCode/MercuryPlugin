// Copyright (c) 2022 Kaya Adrian

#include "MercurySocketTcpBuilder.h"

#include "MercuryNetworkAddress.h"
#include "MercuryNetworkEndpoint.h"
#include "MercurySocketObject.h"


UMercurySocketTcpBuilder::UMercurySocketTcpBuilder(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	Resource = MakeShareable(new FTcpSocketBuilder(TEXT("TCP Socket")));
}

UMercurySocketObject* UMercurySocketTcpBuilder::Build() const
{
	if (!Resource)
		return nullptr;

	UMercurySocketObject* const&& Socket = NewObject<UMercurySocketObject>();
	Socket->GetResource() = MakeShareable(Resource->Build());
	return Socket;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::Lingering(const int32 Timeout)
{
	if (!Resource)
		return nullptr;
	
	*Resource = Resource->Lingering(Timeout);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::Listening(const int32 MaxBacklog)
{
	if (!Resource)
		return nullptr;
	
	*Resource = Resource->Listening(MaxBacklog);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::AsBlocking()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsBlocking();
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::AsReusable()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsReusable();
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::AsReusable(const bool& bInReusable)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsReusable(bInReusable);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::AsNonBlocking()
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->AsNonBlocking();
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::BoundToAddress(const UMercuryNetworkAddress* const& Address)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToAddress(*Address->GetResource());
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToEndpoint(*Endpoint->GetResource());
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::BoundToPort(const int32 Port)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->BoundToPort(Port);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::WithReceiveBufferSize(const int32 SizeInBytes)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->WithReceiveBufferSize(SizeInBytes);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::WithSendBufferSize(const int32 SizeInBytes)
{
	if (!Resource)
		return nullptr;

	*Resource = Resource->WithSendBufferSize(SizeInBytes);
	return this;
}

UMercurySocketTcpBuilder* UMercurySocketTcpBuilder::K2_AsReusable(const bool bInReusable)
{
	return AsReusable(bInReusable);
}
