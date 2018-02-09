#include "UDPServerSocketManager.h"
#include "../../TCP/Socket/TCPClientSocket.h"
UDPServerSocketManager::UDPServerSocketManager()
{
	mSocket = std::make_shared<UDPServerSocket>();
	mSocket->CreateSocket();
	mSocket->BindSocket(1234567);
}

UDPServerSocketManager::~UDPServerSocketManager()
{
}

bool UDPServerSocketManager::Bind()
{
	return true;
}

void UDPServerSocketManager::AddClientAdd(TCPClientSocketPtr client)
{
	mClients.push_back(client);
}

void UDPServerSocketManager::Read()
{
	DotWarsNet state;
	mSocket->Read(state);
	mServerState.states[state.playerNum - 1] = state;
}

void UDPServerSocketManager::Send()
{
	int count = 12345;
	//アドレスが一緒のためポート番号を分ける
	for (auto i : mClients) {
		sockaddr_in add;
		add = i->GetAddr();
		add.sin_port = htons(count);
		mSocket->Send(add, mServerState);
		count++;
	}
}

ServerToClientState UDPServerSocketManager::GetState()
{
	return mServerState;
}

void UDPServerSocketManager::SetState(const ServerToClientState & state)
{
	mServerState = state;
}

void UDPServerSocketManager::Close()
{
	mSocket->CloseSocket();
}
