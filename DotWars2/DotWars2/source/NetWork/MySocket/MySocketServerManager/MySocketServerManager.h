#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../../NetGameState.h"
#include <string>
#include <winsock.h>
#include <vector>
class MySocketServerManager {
public:
	MySocketServerManager();
	~MySocketServerManager();
	
	/// <summary>
	/// ソケット初期化設定
	/// </summary>
	/// <param name="state"></param>
	void Initialize(const SOCKET_STATE& state);
	/// <summary>
	/// サーバーを開ける(TCPサーバーソケット限定)
	/// </summary>
	/// <param name="port">ポート番号</param>
	/// <param name="addr">アドレス</param>
	void OpenServer(int port,const std::string& addr);
	/// <summary>
	/// 接続待ちをする(TCPサーバーソケット限定)
	/// </summary>
	/// <param name="max">最大接続人数</param>
	void AcceptServer(int max);
	/// <summary>
	/// 情報をサーバーから全クライアントに送る
	/// </summary>
	void SendStateServerToClient();
	/// <summary>
	/// 情報をクライアントから受け取る
	/// </summary>
	void ReadStateServer();
private:
	//自身のソケット
	MySocketServerPtr mMySocketServer;
	//サーバーが持っているソケット集
	std::vector<MySocketServerPtr>mMySocketServers;
	//サーバーが持っている情報
	ServerToClientState mServerState;
};