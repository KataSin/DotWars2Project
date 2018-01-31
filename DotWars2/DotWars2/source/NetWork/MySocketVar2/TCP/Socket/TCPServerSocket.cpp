#include "TCPServerSocket.h"
#include "TCPClientSocket.h"
TCPServerSocket::TCPServerSocket()
{
}

TCPServerSocket::~TCPServerSocket()
{
}

TCPServerSocket::SocketError TCPServerSocket::CreateSocket()
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

TCPServerSocket::SocketError TCPServerSocket::BindSocket(const std::string&  addres, int port)
{
	SocketError error;
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(port);
	mAddr.sin_addr.S_un.S_addr = inet_addr(addres.c_str());
	if (bind(mSocket, (struct sockaddr *)&mAddr, sizeof(mAddr)) != 0) {
		error.text = "ソケットのバインドに失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;

}

TCPServerSocket::SocketError TCPServerSocket::ListenSocket(int maxListen)
{
	SocketError error;
	if (listen(mSocket, maxListen) != 0) {
		error.text = "ソケットの待機に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

TCPServerSocket::SocketError TCPServerSocket::AcceptSocket(TCPClientSocketPtr& socketPtr)
{
	SocketError error;
	sockaddr_in addr;
	SOCKET sock;
	int len;
	//セレクトでブロッキング阻止
	fd_set set;
	//初期化
	FD_ZERO(&set);
	FD_SET(mSocket, &set);
	//タイムアウト時間設定
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//アクセプト出来るかチェック
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//エラーの場合もnull
		error.text = "アクセプトのセレクトエラー";
		error.isError = true;
		return error;
	}
	//もしアクセプトができる状態じゃなかったらnullを返す
	if (!(FD_ISSET(mSocket, &set))) {
		error.isError = true;
		return error;
	}
	len = sizeof(addr);
	sock = accept(mSocket, (struct sockaddr*)&addr, &len);
	if (sock < 0) {
		error.text = "ソケットアクセプトエラー";
		error.isError = true;
		return error;
	}
	//クライアントソケット設定
	socketPtr = std::make_shared<TCPClientSocket>();
	socketPtr->SetSocket(sock, addr);

	error.isError = false;
	return error;

}

TCPServerSocket::SocketError TCPServerSocket::Send(SOCKET socket,FirstToClientState & state)
{
	SocketError error;
	if (send(socket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.text = "サーバーからの送信に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;

}

void TCPServerSocket::CloseSocket()
{
	closesocket(mSocket);
}
