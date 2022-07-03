// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercuryCommon/Public/ResourceOwner.h"

#include "MercuryWebEndpoint.generated.h"

struct FIPv4Endpoint;

class UMercuryWebAddress;


UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Web Address")
class MERCURYWEB_API UMercuryWebEndpoint : public UObject, public TResourceOwner<FIPv4Endpoint>
{
	GENERATED_BODY()

public:
	explicit UMercuryWebEndpoint(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Web|IPv4Endpoint", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Web IPv4Endpoint Get Address"
	))
	virtual UMercuryWebAddress* GetAddress() const;

	UFUNCTION(BlueprintPure, DisplayName = "Get Any", Category = "Web|IPv4Endpoint", meta = (
		CompactNodeTitle = "Any",
		Keywords = "Static Web IPv4Endpoint Get Any"
	))
	static const UMercuryWebEndpoint* const& GetAny();

	UFUNCTION(BlueprintCallable, DisplayName = "Initialize", Category = "Web|IPv4Endpoint", meta = (
		Keywords = "Static Web IPv4Endpoint Initialize"
	))
	static void Initialize();

	UFUNCTION(BlueprintPure, DisplayName = "Parse", Category = "Web|IPv4Endpoint", meta = (
		Keywords = "Static Web IPv4Endpoint Parse Endpoint String"
	))
	static void Parse(const FString& EndpointString, UMercuryWebEndpoint*& OutEndpoint);

	virtual uint16 GetPort() const;
	
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Web|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Endpoint Cast To String"
	))
	virtual FString ToString() const;

	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Web|IPv4Endpoint", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Web IPv4Endpoint Cast To Text"
	))
	virtual FText ToText() const;

	virtual TSharedPtr<FInternetAddr> ToInternetAddr() const;

	UFUNCTION(BlueprintPure, DisplayName = "From Host And Port", Category = "Web|IPv4Endpoint", meta = (
		Keywords = "Static Web IPv4Endpoint From Host And Port String Endpoint"
	))
	static UPARAM(DisplayName = "Success") bool
	FromHostAndPort(const FString& HostAndPortString, UMercuryWebEndpoint*& OutEndpoint);

	virtual TSharedPtr<FInternetAddr> ToInternetAddrIPv4() const;

protected:
	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Web|IPv4Endpoint", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Web IPv4Endpoint Get Port"
	))
	virtual int32 K2_GetPort() const;
};
