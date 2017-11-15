#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../MySocketClient/MySocketClient.h"
#include "../../NetGameState.h"
#include <string>
#include <winsock.h>
#include <vector>
class MySocketClientManager {
public:
	MySocketClientManager();
	~MySocketClientManager();

	/// <summary>
	/// ソケット初期化設定
	/// </summary>
	/// <param name="state"></param>
	void Initialize(const SOCKET_STATE& state);
	/// <summary>
	/// サーバーに接続する
	/// </summary>
	/// <param name="addr">アドレス</param>
	/// <param name="port">ポート</param>
	void ConnectClient(const std::string& addr,int port);
	/// <summary>
	/// 情報をサーバーに送る
	/// </summary>
	void SendClient();
	/// <summary>
	/// 情報をクライアントから受け取る
	/// </summary>
	void ReadClient();

private:
	//自身のソケット
	MySocketClientPtr mMySocketClient;
	//自身の情報
	DotWarsNet mNetState;
	//サーバーの情報
	ServerToClientState mServerState;
};