// Copyright (c) 2022 Kaya Adrian

#include "MercurySocketLibrary.h"


UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject()
{
	return CreateSocketObject(nullptr);
}
UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject(const TSharedPtr<FSocket>& Resource)
{
	UMercurySocketObject* const&& SocketObject = NewObject<UMercurySocketObject>();
	SocketObject->GetResource() = Resource ? Resource : SocketObject->CreateResource();
	return SocketObject;
}

UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(const FString& InDescription)
{
	return CreateSocketTcpBuilder(nullptr, InDescription);
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(const FTcpSocketBuilder& Resource)
{
	UMercurySocketTcpBuilder* const&& TcpBuilder = NewObject<UMercurySocketTcpBuilder>();
	*TcpBuilder->GetResource() = Resource;
	return TcpBuilder;
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(
	const TSharedPtr<FTcpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercurySocketTcpBuilder* const&& TcpBuilder = NewObject<UMercurySocketTcpBuilder>();
	TcpBuilder->GetResource() = Resource ? Resource : TcpBuilder->CreateResource(InDescription);
	return TcpBuilder;
}
