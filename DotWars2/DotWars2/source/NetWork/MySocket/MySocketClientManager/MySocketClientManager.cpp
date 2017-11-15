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
void MySocketClientManager::ConnectClient(const std::string & addr, int port)
{
	mMySocketClient->ConnectSocket(addr, port);
}
void MySocketClientManager::SendClient()
{
	mMySocketClient->SendSocket(mNetState);
}

void MySocketClientManager::ReadClient()
{
	mMySocketClient->ReadSocket(mServerState);
}
