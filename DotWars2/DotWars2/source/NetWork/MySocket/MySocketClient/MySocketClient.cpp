#include "MySocketClient.h"


MySocketClient::MySocketClient()
{

}

MySocketClient::~MySocketClient()
{
}

SocketErrorReturn MySocketClient::CreateSocket(SOCKET_STATE state)
{
	SocketErrorReturn error;
	mSocket = socket(AF_INET, state, 0);
	mSocketState = state;
	if (mSocket == INVALID_SOCKET) {
		error.errorText = "ソケットの作成に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketClient::SendSocket(DotWarsNet state)
{
	SocketErrorReturn error;
	if (send(mSocket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.errorText = "クライアントからのからの送信に失敗しました";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketClient::ReadSocket(ServerToClientState & readState)
{
	SocketErrorReturn error;
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
		error.errorText = "読み込みのセレクトエラー";
		error.isError = true;
		return error;
	}
	//読み込める状態じゃなかったら
	if (!FD_ISSET(socket, &set)) {
		error.isError = true;
		return error;
	}
	ServerToClientState state;
	if (recv(mSocket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.errorText = "読み込みエラー";
		error.isError = true;
		return error;
	}
	readState = state;
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketClient::ConnectSocket(std::string add, int port)
{
	SocketErrorReturn error;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.S_un.S_addr = inet_addr(add.c_str());
	if (connect(mSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		error.errorText = "コネクトエラー";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SOCKET_STATE MySocketClient::GetSocketState()
{
	return mSocketState;
}

SOCKET MySocketClient::GetSocket()
{
	return mSocket;
}
sockaddr_in MySocketClient::GetAddr()
{
	return mAddr;
}
void MySocketClient::SetSocket(SOCKET_STATE state, const SOCKET & socket, const sockaddr_in & addr)
{
	mSocketState = state;
	mSocket = socket;
	mAddr = addr;
}