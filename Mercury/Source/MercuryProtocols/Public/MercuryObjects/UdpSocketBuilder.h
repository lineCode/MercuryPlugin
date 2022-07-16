// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryResourceOwner.h"

#include "UdpSocketBuilder.generated.h"

class FUdpSocketBuilder;
class UMercuryNetworkAddress;
class UMercuryNetworkEndpoint;
class UMercurySocketObject;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Builder")
class MERCURYPROTOCOLS_API UMercuryUdpSocketBuilder : public UObject, public TResourceOwner<FUdpSocketBuilder, FString>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FUdpSocketBuilder> CreateResource(const std::tuple<FString>& Arguments) override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Builder", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Build", Category = "UDP|Socket Builder", meta = (
		Keywords = "Protocols UDP Socket Builder Build"
	))
	virtual UMercurySocketObject* Build();

	UFUNCTION(BlueprintPure, DisplayName = "As Blocking", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Blocking",
		Keywords = "Protocols UDP Socket Builder As Blocking"
	))
	virtual UMercuryUdpSocketBuilder* AsBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "As Reusable", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols UDP Socket Builder As Reusable"
	))
	virtual UMercuryUdpSocketBuilder* AsReusable();

	UFUNCTION(BlueprintPure, DisplayName = "As Non Blocking", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Non Blocking",
		Keywords = "Protocols UDP Socket Builder As Non Blocking"
	))
	virtual UMercuryUdpSocketBuilder* AsNonBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Address", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Address"
	))
	virtual UMercuryUdpSocketBuilder* BoundToAddress(const UMercuryNetworkAddress* const& Address);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Endpoint", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Endpoint"
	))
	virtual UMercuryUdpSocketBuilder* BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Port", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Port"
	))
	virtual UMercuryUdpSocketBuilder* BoundToPort(int32 Port);

	UFUNCTION(BlueprintPure, DisplayName = "Joined To Group", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Joined",
		Keywords = "Protocols UDP Socket Builder Joined To Group Address Interface"
	))
	virtual UMercuryUdpSocketBuilder* JoinedToGroup(
		const UMercuryNetworkAddress* const& GroupAddress,
		const UMercuryNetworkAddress* const& InterfaceAddress
	);

	UFUNCTION(BlueprintPure, DisplayName = "With Multicast Interface", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast Interface",
		Keywords = "Protocols UDP Socket Builder With Multicast Interface Address"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastInterface(const UMercuryNetworkAddress* const& InterfaceAddress);

	UFUNCTION(BlueprintPure, DisplayName = "With Multicast Loopback", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast Loopback",
		Keywords = "Protocols UDP Socket Builder With Multicast Loopback"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastLoopback();

	UFUNCTION(BlueprintPure, DisplayName = "With Multicast TTL", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast TTL",
		Keywords = "Protocols UDP Socket Builder With Multicast TTL Time To Live"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastTtl(uint8 TimeToLive);
	
	UFUNCTION(BlueprintPure, DisplayName = "With Receive Buffer Size", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Receive Buffer Size",
		Keywords = "Protocols UDP Socket Builder With Receive Buffer Size In Bytes"
	))
	virtual UMercuryUdpSocketBuilder* WithReceiveBufferSize(int32 SizeInBytes);

	UFUNCTION(BlueprintPure, DisplayName = "With Send Buffer Size", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Send Buffer Size",
		Keywords = "Protocols UDP Socket Builder With Send Buffer Size In Bytes"
	))
	virtual UMercuryUdpSocketBuilder* WithSendBufferSize(int32 SizeInBytes);
};
