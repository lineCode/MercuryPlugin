// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/TcpSocketBuilder.h"
#include "MercuryResourceOwner.h"

#include "StreamSocketBuilder.generated.h"

class UMercuryNetworkAddress;
class UMercuryNetworkEndpoint;
class UMercurySocket;


/** Object that builds simple TCP sockets */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Socket Builder")
class MERCURYPROTOCOLS_API UMercuryTcpSocketBuilder : public UObject, public TResourceOwner<FTcpSocketBuilder, FString>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a TCP socket builder resource.
	 *
	 * @param Arguments Tuple containing InDescription
	 * @return The FTcpSocketBuilder object resource
	 * 
	 * @see UMercuryProtocolsLibrary::CreateTcpSocketBuilder
	 */
	virtual TSharedPtr<FTcpSocketBuilder> CreateResource(const std::tuple<FString>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Socket Builder", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/**
	 * Constructs the TCP socket as configured.
	 *
	 * @return The built UMercurySocket object
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Build", Category = "TCP|Socket Builder", meta = (
		Keywords = "Protocols TCP Socket Builder Build"
	))
	virtual UMercurySocket* Build();

	/**
	 * Sets the TCP socket as lingering.
	 *
	 * @param Timeout Amount of time to linger before closing
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Lingering", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Lingering",
		Keywords = "Protocols TCP Socket Builder Lingering Timeout"
	))
	virtual UMercuryTcpSocketBuilder* Lingering(int32 Timeout);

	/**
	 * Sets the TCP socket as a listener.
	 *
	 * @param MaxBacklog Amount of connections to listen for before refusing them
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Listening", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Listening",
		Keywords = "Protocols TCP Socket Builder Listening Max Backlog"
	))
	virtual UMercuryTcpSocketBuilder* Listening(int32 MaxBacklog);

	/**
	 * Sets the TCP socket as blocking.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Blocking", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Blocking",
		Keywords = "Protocols TCP Socket Builder As Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsBlocking();

	/**
	 * Makes the TCP socket's bound address reusable.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Reusable", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols TCP Socket Builder As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* AsReusable();

	/**
	 * Sets the TCP socket's bound address reusability.
	 *
	 * @param bInReusable Can the bound address be reused by other sockets?
	 * @return The same builder for method chaining
	 */
	virtual UMercuryTcpSocketBuilder* AsReusable(const bool& bInReusable);

	/**
	 * Sets the TCP socket as non-blocking.
	 *
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "As Non Blocking", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Non Blocking",
		Keywords = "Protocols TCP Socket Builder As Non Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsNonBlocking();

	/**
	 * Sets the TCP socket's local bound address.
	 *
	 * @param Address Local address to bind to
	 * @return The same builder for method chaining
	 *
	 * @note A random port number will be assigned by the provider if not set before building.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Address", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Address"
	))
	virtual UMercuryTcpSocketBuilder* BoundToAddress(const UMercuryNetworkAddress* const& Address);

	/**
	 * Sets the TCP socket's local endpoint.
	 *
	 * @param Endpoint Local IP endpoint to bind to
	 * @return The same builder for method chaining
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Endpoint", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Endpoint"
	))
	virtual UMercuryTcpSocketBuilder* BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint);

	/**
	 * Sets the TCP socket's local port number.
	 *
	 * @param Port Local port number to bind to
	 * @return The same builder for method chaining
	 *
	 * @note A random local address will be assigned by the provider if not set before building.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Bound To Port", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Port"
	))
	virtual UMercuryTcpSocketBuilder* BoundToPort(int32 Port);

	/**
	 * Sets the amount of data this TCP socket can receive at once.
	 *
	 * @param SizeInBytes Buffer size
	 * @return The same builder for method chaining
	 *
	 * @note The socket creation will not fail even if the desired buffer size couldn't be set properly.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Receive Buffer Size", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Receive Buffer Size",
		Keywords = "Protocols TCP Socket Builder With Receive Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithReceiveBufferSize(int32 SizeInBytes);

	/**
	 * Sets the amount of data this TCP socket can send at once.
	 *
	 * @param SizeInBytes Buffer size
	 * @return The same builder for method chaining
	 *
	 * @note The socket creation will not fail even if the desired buffer size couldn't be set properly.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "With Send Buffer Size", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Send Buffer Size",
		Keywords = "Protocols TCP Socket Builder With Send Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithSendBufferSize(int32 SizeInBytes);

protected:
	/**
	 * Sets the TCP socket's bound address reusability.
	 *
	 * @param bInReusable Can the bound address be reused by other sockets?
	 * @return The same builder for method chaining
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Set As Reusable", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols TCP Socket Builder Set As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* K2_AsReusable(bool bInReusable);
};
