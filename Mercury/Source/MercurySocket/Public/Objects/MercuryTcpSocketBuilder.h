// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Common/TcpSocketBuilder.h"
#include "ResourceOwner.h"

#include "MercuryTcpSocketBuilder.generated.h"

class UMercuryNetworkAddress;
class UMercuryNetworkEndpoint;
class UMercurySocketObject;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury TCP Socket Builder")
class MERCURYSOCKET_API UMercuryTcpSocketBuilder : public UObject, public TResourceOwner<FTcpSocketBuilder, FString>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FTcpSocketBuilder> CreateResource(const std::tuple<FString>& Arguments) override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Socket|TCP Builder", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintCallable, DisplayName = "Build", Category = "Socket|TCP Builder", meta = (
		Keywords = "Socket TCP Builder Build"
	))
	virtual UMercurySocketObject* Build();

	UFUNCTION(BlueprintPure, DisplayName = "Lingering", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Lingering",
		Keywords = "Socket TCP Builder Lingering Timeout"
	))
	virtual UMercuryTcpSocketBuilder* Lingering(int32 Timeout);

	UFUNCTION(BlueprintPure, DisplayName = "Listening", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Listening",
		Keywords = "Socket TCP Builder Listening Max Backlog"
	))
	virtual UMercuryTcpSocketBuilder* Listening(int32 MaxBacklog);

	UFUNCTION(BlueprintPure, DisplayName = "As Blocking", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Blocking",
		Keywords = "Socket TCP Builder As Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "As Reusable", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Socket TCP Builder As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* AsReusable();
	virtual UMercuryTcpSocketBuilder* AsReusable(const bool& bInReusable);

	UFUNCTION(BlueprintPure, DisplayName = "As Non Blocking", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Non Blocking",
		Keywords = "Socket TCP Builder As Non Blocking"
	))
	virtual UMercuryTcpSocketBuilder* AsNonBlocking();

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Address", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Socket TCP Builder Bound To Address"
	))
	virtual UMercuryTcpSocketBuilder* BoundToAddress(const UMercuryNetworkAddress* const& Address);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Endpoint", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Socket TCP Builder Bound To Endpoint"
	))
	virtual UMercuryTcpSocketBuilder* BoundToEndpoint(const UMercuryNetworkEndpoint* const& Endpoint);

	UFUNCTION(BlueprintPure, DisplayName = "Bound To Port", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Bound",
		Keywords = "Socket TCP Builder Bound To Port"
	))
	virtual UMercuryTcpSocketBuilder* BoundToPort(int32 Port);
	
	UFUNCTION(BlueprintPure, DisplayName = "With Receive Buffer Size", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Receive Buffer Size",
		Keywords = "Socket TCP Builder With Receive Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithReceiveBufferSize(int32 SizeInBytes);

	UFUNCTION(BlueprintPure, DisplayName = "With Send Buffer Size", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Send Buffer Size",
		Keywords = "Socket TCP Builder With Send Buffer Size In Bytes"
	))
	virtual UMercuryTcpSocketBuilder* WithSendBufferSize(int32 SizeInBytes);

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Set As Reusable", Category = "Socket|TCP Builder", meta = (
		CompactNodeTitle = "Reusable",
		Keywords = "Socket TCP Builder Set As Reusable"
	))
	virtual UMercuryTcpSocketBuilder* K2_AsReusable(bool bInReusable);
};
