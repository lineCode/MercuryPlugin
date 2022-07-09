// Copyright (c) 2022 Kaya Adrian

#pragma once

#include "MercurySocketObject.h"
#include "MercurySocketTcpBuilder.h"

#include "MercurySocketLibrary.generated.h"


UCLASS(Abstract, DisplayName = "Mercury Socket Blueprint Function Library")
class MERCURYSOCKET_API UMercurySocketLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName = "Create Socket Object", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket Object"
	))
	static UMercurySocketObject* CreateSocketObject();
	static UMercurySocketObject* CreateSocketObject(const FSocket& Resource) = delete;
	static UMercurySocketObject* CreateSocketObject(const TSharedPtr<FSocket>& Resource);

	UFUNCTION(BlueprintCallable, DisplayName = "Create Socket TCP Builder", Category = "Mercury|Socket", meta = (
		Keywords = "Create Socket TCP Builder In Description"
	))
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(const FString& InDescription = TEXT("TCP Socket"));
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(const FTcpSocketBuilder& Resource);
	static UMercurySocketTcpBuilder* CreateSocketTcpBuilder(
		const TSharedPtr<FTcpSocketBuilder>& Resource,
		const FString& InDescription = TEXT("TCP Socket")
	);
};
