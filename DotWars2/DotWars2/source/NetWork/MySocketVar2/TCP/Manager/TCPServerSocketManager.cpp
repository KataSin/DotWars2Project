#include "TCPServerSocketManager.h"
#include "../Socket/TCPClientSocket.h"
TCPServerSocketManager::TCPServerSocketManager()
{
	mSocket = std::make_shared<TCPServerSocket>();
	mSocket->CreateSocket();
	mSocket->BindSocket("127.0.0.1", 1234567);

	//送る情報を設定
	{
		FirstToClientState state;
		state.playerNum = 1;
		state.position = NetVec3::ToNetVec3(Vector3(100, 100, 100));
		mToClientState.push_back(state);
	}
	{
		FirstToClientState state;
		state.playerNum = 2;
		state.position = NetVec3::ToNetVec3(Vector3(200, 200, 200));
		mToClientState.push_back(state);
	}
}

TCPServerSocketManager::~TCPServerSocketManager()
{
}

bool TCPServerSocketManager::Listen(int listenNum)
{
	if (!mSocket->ListenSocket(listenNum).isError) {
		mPlayerNum = listenNum;
		return true;
	}
	return false;
}

bool TCPServerSocketManager::Accept()
{
	//デバッグ用
	std::string text = "人数:" + std::to_string(mClientSockets.size());
	DrawString(0, 128, text.c_str(), GetColor(255, 255, 255));

	if (mClientSockets.size() >= mPlayerNum) {
		return true;
	}
	TCPClientSocketPtr sockPtr;
	if (!mSocket->AcceptSocket(sockPtr).isError) {
		mClientSockets.push_back(sockPtr);
	}
	return false;
}

bool TCPServerSocketManager::Bind()
{

	return true;
}

bool TCPServerSocketManager::Send()
{
	for (int i = 0; i <= mClientSockets.size() - 1; i++) {
		const SOCKET clientSocket = mClientSockets[i]->GetSocket();
		FirstToClientState state = mToClientState[i];

		mServerToState.states[i].playerNum = mToClientState[i].playerNum;
		mServerToState.states[i].position = mToClientState[i].position;

		if (mSocket->Send(clientSocket, state).isError) {
			return false;
		}
	}
	return true;
}

bool TCPServerSocketManager::Close()
{
	mSocket->CloseSocket();
	return true;
}

std::vector<TCPClientSocketPtr> TCPServerSocketManager::GetConnectSockets()
{
	return mClientSockets;
}

ServerToClientState TCPServerSocketManager::GetFirstState()
{
	return mServerToState;
}
