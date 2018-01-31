#include "TCPClientSocketManager.h"
#include "../Socket/TCPClientSocket.h"
TCPClientSocketManager::TCPClientSocketManager()
{
	mSocket = std::make_shared<TCPClientSocket>();
	mSocket->CreateSocket();
}

TCPClientSocketManager::~TCPClientSocketManager()
{
}

bool TCPClientSocketManager::Connect(std::string addr,int port)
{
	if (!mSocket->ConnectSocket(addr, port).isError) {
		//接続先のサーバーアドレスを設定
		mServerAddr.sin_addr.S_un.S_addr = inet_addr(addr.c_str());
		mServerAddr.sin_port = htons(12345);
		return true;
	}
	return false;
}

bool TCPClientSocketManager::Read(FirstToClientState & state)
{
	return !(mSocket->Read(state).isError);
}

bool TCPClientSocketManager::Close()
{
	mSocket->CloseSocket();
	return true;
}

sockaddr_in TCPClientSocketManager::GetServerAddr()
{
	return mServerAddr;
}
