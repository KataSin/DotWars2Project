#pragma once
#include "../../../NetGameState.h"
#include "../Socket/TCPServerSocket.h"
#include "../../SocketPtr.h"
#include <vector>
class TCPServerSocketManager
{
public:
	TCPServerSocketManager();
	~TCPServerSocketManager();
	//接続待ちをする(listenNum:受付人数)
	bool Listen(int listenNum);
	//クライアントの接続を待つ(人数に達したらtrue)
	bool Accept();
	//バインドする
	bool Bind();
	//情報を送る
	bool Send();
	//ソケットを閉じる
	bool Close();
	//接続してきたソケットたちを取得
	std::vector<TCPClientSocketPtr>GetConnectSockets();
	//最初の情報をServerToClientStateで持ってくる
	ServerToClientState GetFirstState();
private:
	//接続待ちする人数
	int mPlayerNum;
	//最初にサーバーに送る情報
	std::vector<FirstToClientState>mToClientState;
	//クライアントソケットたち
	std::vector<TCPClientSocketPtr> mClientSockets;

	TCPServerSocketPtr mSocket;

	//クライアントに送るサーバー情報
	ServerToClientState mServerToState;
};