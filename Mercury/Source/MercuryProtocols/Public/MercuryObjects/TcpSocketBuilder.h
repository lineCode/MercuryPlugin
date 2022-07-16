// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryResourceOwner.h"

#include "TcpSocketBuilder.generated.h"

class FTcpSocketBuilder;
class UMercuryNetworkAddress;
class UMercuryNetworkEndpoint;
class UMercurySocketObject;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Socket Builder")
class MERCURYPROTOCOLS_API UMercuryTcpSocketBuilder : public UObject, public TResourceOwner<FTcpSocketBuilder, FString>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FTcpSocketBuilder> CreateResource(const std::tuple<FString>& Arguments) override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "TCP|Socket Builder", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Build", Category = "TCP|Socket Builder", meta = (
		Keywords = "Protocols TCP Socket Builder Build"
	))
	virtual UMercurySocketObject* Build();

	UFUNCTION(BlueprintPure, DisplayName = "Lingering", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Lingering",
		Keywords = "Protocols TCP Socket Builder Lingering Timeout"
	))
	virtual UMercuryTcpSocketBuilder* Lingering(int32 Timeout);

	UFUNCTION(BlueprintPure, DisplayName = "Listening", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Listening",
		Keywords = "Protocols TCP Socket Builder Listening Max Backlog"
	))
	virtual UMercuryTcpSocketBuilder* Listening(int32 MaxBacklog);

	UFUNCTION(BlueprintPure, DisplayName = "As Blocking", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Blocking",
		Keywords = "Protocols TCP Socket Builder As Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "As Reusable", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols TCP Socket Builder As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* AsReusable();
	virtual UMercuryTcpSocketBuilder* AsReusable(const bool& bInReusable);

	UFUNCTION(BlueprintPure, DisplayName = "As Non Blocking", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Non Blocking",
		Keywords = "Protocols TCP Socket Builder As Non Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsNonBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Address", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Address"
	))
	virtual UMercuryTcpSocketBuilder* BoundToAddress(const UMercuryNetworkAddress* const& Address);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Endpoint", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Endpoint"
	))
	virtual UMercuryTcpSocketBuilder* BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Port", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Protocols TCP Socket Builder Bound To Port"
	))
	virtual UMercuryTcpSocketBuilder* BoundToPort(int32 Port);
	
	UFUNCTION(BlueprintPure, DisplayName = "With Receive Buffer Size", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Receive Buffer Size",
		Keywords = "Protocols TCP Socket Builder With Receive Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithReceiveBufferSize(int32 SizeInBytes);

	UFUNCTION(BlueprintPure, DisplayName = "With Send Buffer Size", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Send Buffer Size",
		Keywords = "Protocols TCP Socket Builder With Send Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithSendBufferSize(int32 SizeInBytes);

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Set As Reusable", Category = "TCP|Socket Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Protocols TCP Socket Builder Set As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* K2_AsReusable(bool bInReusable);
};
