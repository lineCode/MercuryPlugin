// Copyright (c) 2022 Kaya Adrian

#include "MercurySocketLibrary.h"


UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject()
{
	return CreateSocketObject(nullptr);
}
UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject(FSocket* const& Resource)
{
	return CreateSocketObject(MakeShareable(Resource));
}
UMercurySocketObject* UMercurySocketLibrary::CreateSocketObject(const TSharedPtr<FSocket>& Resource)
{
	UMercurySocketObject* const&& SocketObject = NewObject<UMercurySocketObject>();
	SocketObject->SetResource(Resource ? Resource : SocketObject->CreateResource());
	return SocketObject;
}

UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(const FString& InDescription)
{
	return CreateSocketTcpBuilder(nullptr, InDescription);
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(FTcpSocketBuilder* const& Resource)
{
	return CreateSocketTcpBuilder(MakeShareable(Resource));
}
UMercurySocketTcpBuilder* UMercurySocketLibrary::CreateSocketTcpBuilder(
	const TSharedPtr<FTcpSocketBuilder>& Resource,
	const FString& InDescription
)
{
	UMercurySocketTcpBuilder* const&& TcpBuilder = NewObject<UMercurySocketTcpBuilder>();
	TcpBuilder->SetResource(Resource ? Resource : TcpBuilder->CreateResource(InDescription));
	return TcpBuilder;
}
