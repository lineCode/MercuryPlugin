// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4SubnetMask.h"
#include "MercuryEnums/NetworkSubnetClass.h"
#include "MercuryResourceOwner.h"

#include "NetworkMask.generated.h"


/** Structure representing an IPv4 subnet mask */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Network Mask")
class MERCURYNETWORK_API UMercuryNetworkMask : public UObject, public TResourceOwner<FIPv4SubnetMask>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default IPv4 subnet mask resource.
	 *
	 * @return The FIPv4SubnetMask object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateNetworkMask
	 */
	virtual TSharedPtr<FIPv4SubnetMask> CreateResource() override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Network|IPv4Mask", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Obtains the subnet class that the mask specifies or Invalid if resource is null. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Subnet Class", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Subnet Class",
		Keywords = "Network IPv4SubnetMask Get Subnet Class"
	))
	virtual EMercuryNetworkSubnetClass GetSubnetClass() const;

	/** Obtains the string representation of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To String"
	))
	virtual FString ToString() const;

	/** Obtains the text representation of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "To Text", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Network IPv4SubnetMask Cast To Text"
	))
	virtual FText ToText() const;

	/** Obtains the 1st byte of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "Get A", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "A",
		Keywords = "Network IPv4SubnetMask Get A"
	))
	virtual uint8 GetA() const;

	/**
	 * Sets the 1st byte of the network subnet mask.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set A", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set A"
	))
	virtual UMercuryNetworkMask* SetA(uint8 Value);

	/** Obtains the 2nd byte of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "Get B", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "B",
		Keywords = "Network IPv4SubnetMask Get B"
	))
	virtual uint8 GetB() const;

	/**
	 * Sets the 2nd byte of the network subnet mask.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set B", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set B"
	))
	virtual UMercuryNetworkMask* SetB(uint8 Value);

	/** Obtains the 3rd byte of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "Get C", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "C",
		Keywords = "Network IPv4SubnetMask Get C"
	))
	virtual uint8 GetC() const;

	/**
	 * Sets the 3rd byte of the network subnet mask.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set C", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set C"
	))
	virtual UMercuryNetworkMask* SetC(uint8 Value);

	/** Obtains the 4th byte of the network subnet mask. */
	UFUNCTION(BlueprintPure, DisplayName = "Get D", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "D",
		Keywords = "Network IPv4SubnetMask Get D"
	))
	virtual uint8 GetD() const;

	/**
	 * Sets the 4th byte of the network subnet mask.
	 *
	 * @param Value New byte value
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set D", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set D"
	))
	virtual UMercuryNetworkMask* SetD(uint8 Value);

	/** Obtains the network subnet mask as an integer. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Value", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Value",
		Keywords = "Network IPv4SubnetMask Get Value"
	))
	virtual int32 GetValue() const;

	/**
	 * Sets the network subnet mask from an integer.
	 *
	 * @param Value New mask
	 * @return The same object for method chaining
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Value", Category = "Network|IPv4Mask", meta = (
		Keywords = "Network IPv4SubnetMask Set Value"
	))
	virtual UMercuryNetworkMask* SetValue(int32 Value);

	/**
	 * Converts a string containing a subnet mask to this structure.
	 *
	 * @param MaskString Given IP as a string
	 * @param OutMask Resulting object with the mask set
	 * @return Was the conversion successful?
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Parse Mask", Category = "Network|IPv4Mask", meta = (
		CompactNodeTitle = "Parse",
		Keywords = "Static Network IPv4SubnetMask Parse Mask String"
	))
	static UPARAM(DisplayName = "Success") bool
	Parse(const FString& MaskString, UMercuryNetworkMask*& OutMask);
};
