#include "MySocketClientManager.h"

MySocketClientManager::MySocketClientManager()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	mMySocketClient = std::make_shared<MySocketClient>();
}

MySocketClientManager::~MySocketClientManager()
{
}

void MySocketClientManager::Initialize(const SOCKET_STATE & state)
{
	mMySocketClient->CreateSocket(state);
}
void MySocketClientManager::CloseSocket()
{
	mMySocketClient->CloseSocket();
}
bool MySocketClientManager::ConnectClient(const std::string & addr, int port)
{
	if (!mMySocketClient->ConnectSocket(addr, port).isError) {
		return true;
	}
	return false;
}
void MySocketClientManager::Send()
{
	mMySocketClient->SendUDP(mNetState);
}

bool MySocketClientManager::Read()
{
	return !(mMySocketClient->Read(mServerState).isError);
}

bool MySocketClientManager::FirstRead()
{
	return !(mMySocketClient->FirstRead(mFirstState).isError);
}

bool MySocketClientManager::Bind(int port)
{
	return !(mMySocketClient->BindSocket(port).isError);
}


void MySocketClientManager::SetState(const DotWarsNet & state)
{
	mNetState = state;
}

ServerToClientState MySocketClientManager::GetState()
{
	return mServerState;
}

FirstToClientState MySocketClientManager::GetFirstState()
{
	return mFirstState;
}
