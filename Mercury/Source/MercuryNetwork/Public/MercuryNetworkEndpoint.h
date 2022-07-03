// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryCommon/Public/ResourceOwner.h"

#include "MercuryNetworkEndpoint.generated.h"

struct FIPv4Endpoint;

class UMercuryNetworkAddress;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Address")
class MERCURYNETWORK_API UMercuryNetworkEndpoint : public UObject, public TResourceOwner<FIPv4Endpoint>
{
	GENERATED_BODY()

public:
	explicit UMercuryNetworkEndpoint(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Network IPv4Endpoint Get Address"
	))
	virtual UMercuryNetworkAddress* GetAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Network IPv4Endpoint Get Any"
	))
	static const UMercuryNetworkEndpoint* const& GetAny();

	UFUNCTION(BlueprintCallable, DisplayName = "Initialize", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint Initialize"
	))
	static void Initialize();

	UFUNCTION(BlueprintPure, DisplayName = "Parse", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint Parse Endpoint String"
	))
	static void Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint);

	virtual uint16 GetPort() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To Text"
	))
	virtual FText ToText() const;

	virtual TSharedPtr<FInternetAddr> ToInternetAddr() const;

	UFUNCTION(BlueprintPure, DisplayName = "From Host And Port", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint From Host And Port String Endpoint"
	))
	static UPARAM(DisplayName = "Success") bool
	FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint);

	virtual TSharedPtr<FInternetAddr> ToInternetAddrIPv4() const;

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Network IPv4Endpoint Get Port"
	))
	virtual int32 K2_GetPort() const;
};
