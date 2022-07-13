﻿// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "ResourceOwner.h"

#include "NetworkEndpoint.generated.h"

class UMercuryInternetAddr;
class UMercuryNetworkAddress;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Endpoint")
class MERCURYNETWORK_API UMercuryNetworkEndpoint : public UObject, public TResourceOwner<FIPv4Endpoint>
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<FIPv4Endpoint> CreateResource() override;

	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Network IPv4Endpoint Get Address"
	))
	virtual UMercuryNetworkAddress* GetAddress() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set Address", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Set Address"
	))
	virtual UMercuryNetworkEndpoint* SetAddress(const UMercuryNetworkAddress* const& Value);

	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Network IPv4Endpoint Get Any"
	))
	static const UMercuryNetworkEndpoint* const& GetAny();

	UFUNCTION(BlueprintCallable, DisplayName = "Initialize", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint Initialize"
	))
	static void Initialize();

	UFUNCTION(BlueprintPure, DisplayName = "Parse Endpoint", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Endpoint Parse Endpoint String"
	))
	static void Parse(const FString& EndpointString, UMercuryNetworkEndpoint*& OutEndpoint);

	virtual uint16 GetPort() const;
	virtual UMercuryNetworkEndpoint* SetPort(const uint16& Value);
	
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

	UFUNCTION(BlueprintPure, DisplayName = "To Internet Addr", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Endpoint Cast To Internet Addr Address"
	))
	virtual UMercuryInternetAddr* ToInternetAddr() const;

	UFUNCTION(BlueprintPure, DisplayName = "From Host And Port", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Static Network IPv4Endpoint From Host And Port String Endpoint"
	))
	static UPARAM(DisplayName = "Success") bool
	FromHostAndPort(const FString& HostAndPortString, UMercuryNetworkEndpoint*& OutEndpoint);

	UFUNCTION(BlueprintPure, DisplayName = "To Internet Addr IPv4", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Cast To Internet Addr Address IPv4"
	))
	virtual UMercuryInternetAddr* ToInternetAddrIPv4() const;

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Network|IPv4Endpoint", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Network IPv4Endpoint Get Port"
	))
	virtual int32 K2_GetPort() const;
	UFUNCTION(BlueprintCallable, DisplayName = "Set Port", Category = "Network|IPv4Endpoint", meta = (
		Keywords = "Network IPv4Endpoint Set Port"
	))
	virtual UMercuryNetworkEndpoint* K2_SetPort(int32 Value);
};