#include "UDPClientSocketManager.h"
#include "../Socket/UDPClientSocket.h"
UDPClientSocketManager::UDPClientSocketManager()
{
	mSocket = std::make_shared<UDPClientSocket>();
	mSocket->CreateSocket();
}

UDPClientSocketManager::~UDPClientSocketManager()
{
}

bool UDPClientSocketManager::Bind(const FirstToClientState& state)
{
	//ここのポート番号をプレイヤー番号によって変える
	int portPlus = state.playerNum - 1;
	return !mSocket->BindSocket(12345 + portPlus).isError;
}

void UDPClientSocketManager::Read()
{
	mSocket->Read(mServerToState);
}

void UDPClientSocketManager::Send()
{
	mSocket->Send(mServerAddr, mDotNetState);
}

ServerToClientState UDPClientSocketManager::GetState()
{
	return mServerToState;
}

void UDPClientSocketManager::Close()
{
	mSocket->CloseSocket();
}

void UDPClientSocketManager::SetServerAddr(const sockaddr_in & addr)
{
	mServerAddr = addr;
}

void UDPClientSocketManager::SetState(const DotWarsNet & state)
{
	mDotNetState = state;
}

ServerToClientState UDPClientSocketManager::GetServerState()
{
	return mServerToState;
}
