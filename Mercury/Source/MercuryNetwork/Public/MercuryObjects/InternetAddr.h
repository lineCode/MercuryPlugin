// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "IPAddress.h"
#include "MercuryResourceOwner.h"

#include "InternetAddr.generated.h"


/** Structure representing an internet address */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Mercury Internet Addr")
class MERCURYNETWORK_API UMercuryInternetAddr : public UObject, public TResourceOwner<FInternetAddr, FName>
{
	GENERATED_BODY()

public:
	/**
	 * Creates a default internet address resource.
	 *
	 * @return The FInternetAddr object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateInternetAddr
	 */
	virtual TSharedPtr<FInternetAddr> CreateResource() override;

	/**
	 * Creates a default internet address resource.
	 *
	 * @param Arguments Tuple containing ProtocolType
	 * @return The FInternetAddr object resource
	 * 
	 * @see UMercuryNetworkLibrary::CreateInternetAddr
	 */
	virtual TSharedPtr<FInternetAddr> CreateResource(const std::tuple<FName>& Arguments) override;

	/** Checks if the resource is not null. */
	UFUNCTION(BlueprintPure, DisplayName = "Has Resource", Category = "Internet|Addr", meta = (
		Keywords = "Has Mercury Resource"
	))
	virtual bool HasResource() const override;

	/** Creates a new object with the same data as this one. */
	UFUNCTION(BlueprintCallable, DisplayName = "Clone", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Clone"
	))
	virtual UMercuryInternetAddr* Clone() const;

	/**
	 * Compares the logical net addresses of the data stored between two structures.
	 *
	 * @param InAddr Internet address to compare with
	 * @return Are the endpoints the same?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Compare Endpoints", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Compare Endpoints In"
	))
	virtual bool CompareEndpoints(const UMercuryInternetAddr* const& InAddr) const;

	/**
	 * Copies the internet IP address to an integer.
	 *
	 * @param OutAddr Obtained IP address
	 */
	virtual void GetIp(uint32& OutAddr) const;

	/**
	 * Obtains the address port.
	 *
	 * @return The port number
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Port", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Port",
		Keywords = "Internet Addr Address Get Port"
	))
	virtual int32 GetPort() const;

	/**
	 * Copies the internet port number to an integer.
	 *
	 * @param OutPort Obtained port number
	 */
	virtual void GetPort(int32& OutPort) const;

	/** Checks if the internet address is well-formed. */
	UFUNCTION(BlueprintPure, DisplayName = "Is Valid", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Valid",
		Keywords = "Internet Addr Address Is Valid"
	))
	virtual bool IsValid() const;

	/**
	 * Sets a new IP address to use.
	 *
	 * @param InAddr IP as a string
	 * @param bIsValid Was the given string a valid IP address?
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set IP (String)", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set IP String Is Valid"
	))
	virtual void SetIp(const FString& InAddr, bool& bIsValid);

	/**
	 * Sets a new IP address to use.
	 *
	 * @param InAddr IP as an integer
	 */
	virtual void SetIp(const uint32& InAddr);

	/**
	 * Sets a new address port to use.
	 *
	 * @param InPort Address port number
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Port", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Port"
	))
	virtual void SetPort(int32 InPort);

	/**
	 * Obtains the string representation of the internet address.
	 *
	 * @param bAppendPort Should the port number be attached to the IP?
	 * @return The FString object containing the IP and possibly the port
	 */
	UFUNCTION(BlueprintPure, DisplayName = "To String", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Cast",
		Keywords = "Internet Addr Address Cast To String Append Port"
	))
	virtual FString ToString(bool bAppendPort) const;

	/** Prints out address data to the output log. */
	UFUNCTION(BlueprintCallable, DisplayName = "Dump Addr Data", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Dump Data"
	))
	virtual void DumpAddrData() const;

	/** Obtains the port number of the platform. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Platform Port", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Platform Port",
		Keywords = "Internet Addr Address Get Platform Port"
	))
	virtual int32 GetPlatformPort() const;

	/** Obtains the protocol type name of the address or None if unknown. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Protocol Type", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Protocol Type",
		Keywords = "Internet Addr Address Get Protocol Type"
	))
	virtual FName GetProtocolType() const;

	/** Obtains the IP address as an array with 4 elements. */
	UFUNCTION(BlueprintPure, DisplayName = "Get Raw IP", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Raw IP",
		Keywords = "Internet Addr Address Get Raw IP"
	))
	virtual TArray<uint8> GetRawIp() const;

	/** Obtains the hash function used for TMap objects. */
	virtual uint32 GetTypeHash() const;

	/** Sets the internet address to be any address. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Any Address", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Any Address"
	))
	virtual void SetAnyAddress();

	/** Sets the internet address to be the broadcast address. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Broadcast Address", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Broadcast Address"
	))
	virtual void SetBroadcastAddress();

	/** Sets the internet address to be the loopback address. */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Loopback Address", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Loopback Address"
	))
	virtual void SetLoopbackAddress();

	/**
	 * Sets a new platform port to use.
	 *
	 * @param InPort Platform port number
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Platform Port", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Platform Port In"
	))
	virtual void SetPlatformPort(int32 InPort);

	/**
	 * Sets a new IP address to use.
	 *
	 * @param RawAddr IP address as an array with 4 elements
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Raw IP", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set Raw IP"
	))
	virtual void SetRawIp(const TArray<uint8>& RawAddr);

protected:
	/**
	 * Copies the internet IP address to an integer.
	 *
	 * @param OutAddr Obtained IP address
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get IP", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "IP",
		Keywords = "Internet Addr Address Get IP Out"
	))
	virtual void K2_GetIp(int32& OutAddr) const;

	/**
	 * Sets a new IP address to use.
	 *
	 * @param InAddr IP as an integer
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set IP (Integer)", Category = "Internet|Addr", meta = (
		Keywords = "Internet Addr Address Set IP Integer"
	))
	virtual void K2_SetIp(int32 InAddr);

	/**
	 * Obtains the hash function used for TMap objects.
	 *
	 * @note This should be used strictly inside Blueprints.
	 */
	UFUNCTION(BlueprintPure, DisplayName = "Get Type Hash", Category = "Internet|Addr", meta = (
		CompactNodeTitle = "Type Hash",
		Keywords = "Internet Addr Address Get Type Hash"
	))
	virtual int32 K2_GetTypeHash() const;
};
