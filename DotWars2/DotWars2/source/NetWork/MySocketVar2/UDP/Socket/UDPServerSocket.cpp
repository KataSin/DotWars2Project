#include "UDPServerSocket.h"

UDPServerSocket::UDPServerSocket()
{

}

UDPServerSocket::~UDPServerSocket()
{
}

UDPServerSocket::SocketError UDPServerSocket::CreateSocket()
{
	SocketError error;
	mSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (mSocket == INVALID_SOCKET) {
		error.text = "ソケットの作成に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

UDPServerSocket::SocketError UDPServerSocket::BindSocket(const std::string & addres, int port)
{
	SocketError error;
	struct sockaddr_in add;
	add.sin_family = AF_INET;
	add.sin_port = htons(port);
	add.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(mSocket, (struct sockaddr*)&add, sizeof(add)) != 0) {
		error.text = "ソケットのバインドに失敗しました";
		error.isError = true;
		return error;
	}
	return error;

}

UDPServerSocket::SocketError UDPServerSocket::Send(SOCKET socket, ServerToClientState & state)
{
	return SocketError();
}

UDPServerSocket::SocketError UDPServerSocket::Read(DotWarsNet & state)
{
	return SocketError();
}

void UDPServerSocket::CloseSocket()
{
}
