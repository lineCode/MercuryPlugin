// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/UdpSocketBuilder.h"
#include "MercuryResourceOwner.h"

#include "DatagramSocketBuilder.generated.h"

class UMercuryNetworkAddress;
class UMercuryNetworkEndpoint;
class UMercurySocket;


/** Object that builds simple UDP sockets */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury UDP Socket Builder")
class MERCURYPROTOCOLS_API UMercuryUdpSocketBuilder : public UObject, public TResourceOwner<FUdpSocketBuilder, FString>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a UDP socket builder resource.
	 *
	 * @param Arguments Tuple containing InDescription
	 * @return The FTcpSocketBuilder object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateUdpSocketBuilder
	 */
	virtual TSharedPtr<FUdpSocketBuilder> CreateResource(const std::tuple<FString>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "UDP|Socket Builder", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/**
	 * Constructs the UDP socket as configured.
	 *
	 * @return The built UMercurySocket object
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Build", Category = "UDP|Socket Builder", meta = (
		Keywords = "Protocols UDP Socket Builder Build"
	))
	virtual UMercurySocket* Build();

	/**
	 * Sets the UDP socket as blocking.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Blocking", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Blocking",
		Keywords = "Protocols UDP Socket Builder As Blocking"
	))
	virtual UMercuryUdpSocketBuilder* AsBlocking();

	/**
	 * Makes the UDP socket's bound address reusable.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Reusable", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols UDP Socket Builder As Reusable"
	))
	virtual UMercuryUdpSocketBuilder* AsReusable();

	/**
	 * Sets the UDP socket as non-blocking.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Non Blocking", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Non Blocking",
		Keywords = "Protocols UDP Socket Builder As Non Blocking"
	))
	virtual UMercuryUdpSocketBuilder* AsNonBlocking();

	/**
	 * Sets the UDP socket's local bound address.
	 *
	 * @param Address Local address to bind to
	 * @return The same builder for method chaining
	 *
	 * @note A random port number will be assigned by the provider if not set before building.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Address", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Address"
	))
	virtual UMercuryUdpSocketBuilder* BoundToAddress(const UMercuryNetworkAddress* const& Address);

	/**
	 * Sets the UDP socket's local endpoint.
	 *
	 * @param Endpoint Local IP endpoint to bind to
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Endpoint", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Endpoint"
	))
	virtual UMercuryUdpSocketBuilder* BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint);

	/**
	 * Sets the UDP socket's local port number.
	 *
	 * @param Port Local port number to bind to
	 * @return The same builder for method chaining
	 *
	 * @note A random local address will be assigned by the provider if not set before building.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Port", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols UDP Socket Builder Bound To Port"
	))
	virtual UMercuryUdpSocketBuilder* BoundToPort(int32 Port);

	/**
	 * Joins the UDP socket to the specified multicast group.
	 *
	 * @param GroupAddress Multicast group IP address
	 * @param InterfaceAddress Interface IP address
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Joined To Group", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Joined",
		Keywords = "Protocols UDP Socket Builder Joined To Group Address Interface"
	))
	virtual UMercuryUdpSocketBuilder* JoinedToGroup(
		const UMercuryNetworkAddress* const& GroupAddress,
		const UMercuryNetworkAddress* const& InterfaceAddress
	);

	/**
	 * Sets the UDP socket's multicast outgoing interface.
	 *
	 * @param InterfaceAddress Interface to use for sending multicast datagrams
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Multicast Interface", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast Interface",
		Keywords = "Protocols UDP Socket Builder With Multicast Interface Address"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastInterface(const UMercuryNetworkAddress* const& InterfaceAddress);

	/**
	 * Allows the UDP socket to use multicast loopback.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Multicast Loopback", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast Loopback",
		Keywords = "Protocols UDP Socket Builder With Multicast Loopback"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastLoopback();

	/**
	 * Sets the UDP socket multicast TTL.
	 *
	 * @param TimeToLive Amount of time to live
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Multicast TTL", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Multicast TTL",
		Keywords = "Protocols UDP Socket Builder With Multicast TTL Time To Live"
	))
	virtual UMercuryUdpSocketBuilder* WithMulticastTtl(uint8 TimeToLive);

	/**
	 * Sets the amount of data this UDP socket can receive at once.
	 *
	 * @param SizeInBytes Buffer size
	 * @return The same builder for method chaining
	 *
	 * @note The socket creation will not fail even if the desired buffer size couldn't be set properly.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Receive Buffer Size", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Receive Buffer Size",
		Keywords = "Protocols UDP Socket Builder With Receive Buffer Size In Bytes"
	))
	virtual UMercuryUdpSocketBuilder* WithReceiveBufferSize(int32 SizeInBytes);

	/**
	 * Sets the amount of data this UDP socket can send at once.
	 *
	 * @param SizeInBytes Buffer size
	 * @return The same builder for method chaining
	 *
	 * @note The socket creation will not fail even if the desired buffer size couldn't be set properly.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Send Buffer Size", Category = "UDP|Socket Builder", meta = (
		CompactNodeTitle = "Send Buffer Size",
		Keywords = "Protocols UDP Socket Builder With Send Buffer Size In Bytes"
	))
	virtual UMercuryUdpSocketBuilder* WithSendBufferSize(int32 SizeInBytes);
};
