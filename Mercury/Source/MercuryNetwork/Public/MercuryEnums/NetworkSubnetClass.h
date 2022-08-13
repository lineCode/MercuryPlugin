// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "Interfaces/IPv4/IPv4SubnetMask.h"
#include "MercuryNetwork.h"
#include "UObject/ObjectMacros.h"


UENUM(BlueprintType, meta = (Keywords = "Network Subnet Mask Class Invalid A B C"))
enum class EMercuryNetworkSubnetClass : uint8
{
	Invalid UMETA(DisplayName = "Invalid"),
	ClassA UMETA(DisplayName = "Class A"),
	ClassB UMETA(DisplayName = "Class B"),
	ClassC UMETA(DisplayName = "Class C")
};

namespace MercuryEnums::SubnetMask
{
	constexpr EMercuryNetworkSubnetClass Convert(const EIPv4SubnetClasses::Type& SubnetClass)
	{
		switch (SubnetClass)
		{
		case EIPv4SubnetClasses::Invalid:
			return EMercuryNetworkSubnetClass::Invalid;

		case EIPv4SubnetClasses::ClassA:
			return EMercuryNetworkSubnetClass::ClassA;

		case EIPv4SubnetClasses::ClassB:
			return EMercuryNetworkSubnetClass::ClassB;

		case EIPv4SubnetClasses::ClassC:
			return EMercuryNetworkSubnetClass::ClassC;

		default:
			UE_LOG(LogMercuryNetwork, Error, TEXT("Unknown subnet class: %d"), SubnetClass);
			return EMercuryNetworkSubnetClass::Invalid;
		}
	}

	constexpr EIPv4SubnetClasses::Type Convert(const EMercuryNetworkSubnetClass& SubnetClass)
	{
		switch (SubnetClass)
		{
		case EMercuryNetworkSubnetClass::Invalid:
			return EIPv4SubnetClasses::Invalid;

		case EMercuryNetworkSubnetClass::ClassA:
			return EIPv4SubnetClasses::ClassA;

		case EMercuryNetworkSubnetClass::ClassB:
			return EIPv4SubnetClasses::ClassB;

		case EMercuryNetworkSubnetClass::ClassC:
			return EIPv4SubnetClasses::ClassC;

		default:
			UE_LOG(LogMercuryNetwork, Error, TEXT("Unknown subnet class: %d"), SubnetClass);
			return EIPv4SubnetClasses::Invalid;
		}
	}
}
