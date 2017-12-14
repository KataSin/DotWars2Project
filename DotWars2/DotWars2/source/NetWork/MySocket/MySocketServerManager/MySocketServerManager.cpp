#include "MySocketServerManager.h"
#include <winsock.h>
#include <algorithm>
MySocketServerManager::MySocketServerManager()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	mMySocketServer = std::make_shared<MySocketServer>();

	mNumFlag = false;
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

bool MySocketServerManager::AcceptServer(int max)
{
	MySocketServerPtr socketPtr;
	//受付人数になったら
	if (mMySocketServers.size() >= max) {
		return true;
	}
	if (!(mMySocketServer->AcceptSocket(socketPtr).isError)) {
		mMySocketServers.push_back(socketPtr);
		//最初の情報を送る
		FirstToClientState state;
		state.playerNum = mMySocketServers.size();
		FirstSend(socketPtr->GetSocket(), state);
	}
	return false;
}
void MySocketServerManager::Read()
{
	for (int i = 0; i <= mMySocketServers.size() - 1; i++) {
		DotWarsNet state;
		if (!mMySocketServer->ReadSocket(mMySocketServers[i]->GetSocket(), state).isError) {
			//データを受け取れたらそのまま入れる
			mServerState.states[state.playerNum - 1] = state;
		}
		//失敗の場合なにもしない
	}
}

void MySocketServerManager::Send()
{
	for (int i = 0; i <= mMySocketServers.size() - 1; i++) {
		mMySocketServer->SendSocket(mMySocketServers[i]->GetSocket(), mServerState);
	}

}

void MySocketServerManager::FirstSend(SOCKET sock, FirstToClientState state)
{
	mMySocketServer->FirstSend(sock, state);
	DotWarsNet netState;
	netState.position = state.position;
	netState.playerNum = state.playerNum;
	mServerState.states[state.playerNum - 1] = netState;;
}

ServerToClientState MySocketServerManager::GetServerState()
{
	return mServerState;
}


