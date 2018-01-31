#include "TCPClientSocket.h"

TCPClientSocket::TCPClientSocket()
{
}

TCPClientSocket::~TCPClientSocket()
{
}

TCPClientSocket::SocketError TCPClientSocket::CreateSocket()
{
	SocketError error;
	mSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (mSocket == INVALID_SOCKET) {
		error.text = "ソケットの作成に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

TCPClientSocket::SocketError TCPClientSocket::Read(FirstToClientState & readState)
{
	SocketError error;
	//セレクトでブロッキング阻止
	fd_set set;
	//初期化
	FD_ZERO(&set);
	FD_SET(mSocket, &set);
	//タイムアウト時間設定
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//読み取り出来るかチェック
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//エラーの場合もnull
		error.text = "読み込みのセレクトエラー";
		error.isError = true;
		return error;
	}
	//読み込める状態じゃなかったら
	if (!FD_ISSET(mSocket, &set)) {
		error.isError = true;
		return error;
	}
	FirstToClientState state;
	if (recv(mSocket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.text = "読み込みエラー";
		error.isError = true;
		return error;
	}
	readState = state;
	error.isError = false;
	return error;

}

TCPClientSocket::SocketError TCPClientSocket::ConnectSocket(std::string add, int port)
{
	SocketError error;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.S_un.S_addr = inet_addr(add.c_str());
	auto a = connect(mSocket, (struct sockaddr*)&server, sizeof(server));
	if (connect(mSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		error.text = "コネクトエラー";
		error.isError = true;
		return error;
	}
	//アドレス登録

	error.isError = false;
	return error;

}

SOCKET TCPClientSocket::GetSocket()
{
	return mSocket;
}

sockaddr_in TCPClientSocket::GetAddr()
{
	return mAddr;
}

void TCPClientSocket::SetSocket(const SOCKET & socket, const sockaddr_in & addr)
{
	mSocket = socket;
	mAddr = addr;
}

void TCPClientSocket::CloseSocket()
{
	closesocket(mSocket);
}
