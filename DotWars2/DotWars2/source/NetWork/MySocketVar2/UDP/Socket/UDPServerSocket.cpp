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

UDPServerSocket::SocketError UDPServerSocket::BindSocket(int port)
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

UDPServerSocket::SocketError UDPServerSocket::Send(sockaddr_in addr, ServerToClientState & state)
{
	sendto(mSocket, reinterpret_cast<char*>(&state), sizeof(state), 0, (struct sockaddr *)&addr, sizeof(addr));
	SocketError error;
	error.isError = false;
	return error;
}

UDPServerSocket::SocketError UDPServerSocket::Read(DotWarsNet & state)
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
	DotWarsNet net;
	if (recvfrom(mSocket, reinterpret_cast<char*>(&net), sizeof(net), 0, NULL, NULL) == SOCKET_ERROR) {
		error.text = "読み込みエラー";
		error.isError = true;
		return error;
	}
	state = net;
	error.isError = false;
	return error;
}

void UDPServerSocket::CloseSocket()
{
	closesocket(mSocket);
}
