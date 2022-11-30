// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4Subnet.h"
#include "MercuryResourceOwner.h"

#include "NetworkSubnet.generated.h"

class UMercuryNetworkAddress;
class UMercuryNetworkMask;


/** Structure representing an IPv4 subnet */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Subnet")
class MERCURYNETWORK_API UMercuryNetworkSubnet : public UObject, public TResourceOwner<FIPv4Subnet>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default IPv4 subnet resource.
	 *
	 * @return The FIPv4Subnet object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateNetworkSubnet
	 */
	virtual TSharedPtr<FIPv4Subnet> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the subnet's IP address by creating a new UMercuryNetworkAddress object. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Address", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Address",
		Keywords = "Network IPv4Subnet Get Address"
	))
	virtual UMercuryNetworkAddress* GetAddress() const;

	/**
	 * Sets the subnet's IP address.
	 *
	 * @param Value UMercuryNetworkAddress object containing the new IP
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Address", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Set Address"
	))
	virtual UMercuryNetworkSubnet* SetAddress(const UMercuryNetworkAddress* const& Value);

	/** Obtains the subnet's mask by creating a new UMercuryNetworkMask object. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Mask", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Mask",
		Keywords = "Network IPv4Subnet Get Mask"
	))
	virtual UMercuryNetworkMask* GetMask() const;

	/**
	 * Sets the subnet's mask.
	 *
	 * @param Value UMercuryNetworkMask object containing the new mask
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Mask", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Set Mask"
	))
	virtual UMercuryNetworkSubnet* SetMask(const UMercuryNetworkMask* const& Value);

	/** Obtains the broadcast address by creating a new UMercuryNetworkAddress object. */
	UFUNCTION(BlueprintPure, DisplayName = "Broadcast Address", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Broadcast Address"
	))
	virtual UMercuryNetworkAddress* BroadcastAddress() const;

	/**
	 * Checks if a network address is contained in this subnet.
	 *
	 * @param TestAddress Address to check
	 * @return Does the subnet contain the given IP address?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Contains Address", Category = "Network|IPv4Subnet", meta = (
		Keywords = "Network IPv4Subnet Contains Address TestAddress"
	))
	virtual bool ContainsAddress(const UMercuryNetworkAddress* const& TestAddress) const;

	/** Obtains the string representation of the network subnet. */
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Subnet Cast To String"
	))
	virtual FString ToString() const;

	/** Obtains the text representation of the network subnet. */
	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4Subnet Cast To Text"
	))
	virtual FText ToText() const;

	/**
	 * Converts a string containing a subnet to this structure.
	 *
	 * @param SubnetString Given IP as a string
	 * @param OutSubnet Resulting object with the subnet set
	 * @return Was the conversion successful?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Parse Subnet", Category = "Network|IPv4Subnet", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4Subnet Parse Subnet String"
	))
	static UPARAM(DisplayName = "Success") bool
	Parse(const FString& SubnetString, UMercuryNetworkSubnet*& OutSubnet);
};
