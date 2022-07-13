// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercurySocketObject.h"
#include "MercurySocketTcpBuilder.h"
#include "MercurySocketTcpListener.h"

#include "MercurySocketLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Socket Blueprint Function Library")
class MERCURYSOCKET_API UMercurySocketLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, DisplayName = "Create Socket Object", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object"
	))
	static UMercurySocketObject* CreateSocketObject();
	static UMercurySocketObject* CreateSocketObject(FSocket* const& Resource);
	static UMercurySocketObject* CreateSocketObject(const TSharedPtr<FSocket>& Resource);

	UFUNCTION(BlueprintPure, DisplayName = "Create Socket TCP Builder", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket TCP Builder In Description"
	))
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(const FString& InDescription = TEXT("TCP Socket"));
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(FTcpSocketBuilder* const& Resource);
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(
		const TSharedPtr<FTcpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("TCP Socket")
	);

	UFUNCTION(BlueprintPure, DisplayName = "Create Socket TCP Listener", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket TCP Listener In Socket Sleep Time Reusable"
	))
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		UMercurySocketObject* const& InSocket,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		FTcpListener* const& Resource,
		UMercurySocketObject* const& InSocket
	);
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		UMercurySocketObject* const& InSocket,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		const bool& bInReusable = true
	);
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		FTcpListener* const& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint
	);
	static UMercurySocketTcpListener* CreateSocketTcpListener(
		const TSharedPtr<FTcpListener>& Resource,
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime = FTimespan::FromSeconds(1.0),
		const bool& bInReusable = true
	);

protected:
	UFUNCTION(
		BlueprintPure,
		DisplayName = "Create Socket TCP Listener (Endpoint)",
		Category = "Mercury|Socket",
		meta = (Keywords = "Create Socket TCP Listener Local Endpoint In Sleep Time Reusable")
	)
	static UMercurySocketTcpListener* K2_CreateSocketTcpListenerWithEndpoint(
		const UMercuryNetworkEndpoint* const& LocalEndpoint,
		const FTimespan& InSleepTime,
		bool bInReusable = true
	);
};
