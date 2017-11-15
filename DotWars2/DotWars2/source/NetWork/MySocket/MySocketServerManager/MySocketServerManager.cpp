#include "MySocketServerManager.h"
#include <winsock.h>
MySocketServerManager::MySocketServerManager()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	mMySocketServer = std::make_shared<MySocketServer>();
}

MySocketServerManager::~MySocketServerManager()
{
	for (const auto i : mMySocketServers) {
		closesocket(i->GetSocket());
	}
	closesocket(mMySocketServer->GetSocket());
	WSACleanup();
}

void MySocketServerManager::Initialize(const SOCKET_STATE & state)
{
	mMySocketServer->CreateSocket(state);
}

void MySocketServerManager::OpenServer(int port, const std::string& addr)
{
	mMySocketServer->BindSocket(port, addr);
	mMySocketServer->ListenSocket(5);
}

void MySocketServerManager::AcceptServer(int max)
{
	MySocketServerPtr socketPtr;
	if (!(mMySocketServer->AcceptSocket(socketPtr).isError)) {
		mMySocketServers.push_back(socketPtr);
	}
}

void MySocketServerManager::SendStateServerToClient()
{
	for (int i = 0; i <= mMySocketServers.size() - 1; i++) {
		mMySocketServer->SendSocket(mMySocketServers[i]->GetSocket(), mServerState);
	}
}

void MySocketServerManager::ReadStateServer()
{
	mServerState.states.clear();
	for (int i = 0; i <= mMySocketServers.size() - 1; i++) {
		DotWarsNet state;
		bool flag=mMySocketServer->ReadSocket(mMySocketServers[i]->GetSocket(), state).isError;
		if (!flag)
			mServerState.states.push_back(state);
	}
}
