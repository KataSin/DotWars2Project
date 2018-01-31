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
	/// 自身のソケットを消す
	/// </summary>
	void CloseSocket();
	/// <summary>
	/// バインドする
	/// </summary>
	void Bind(int port);

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
	bool AcceptServer(int max);
	/// <summary>
	/// クライアントから情報を取得する
	/// </summary>
	void Read();
	/// <summary>
	/// クライアントに情報を送る
	/// </summary>
	void Send();
	/// <summary>
	/// 最初の情報を送る
	/// </summary>
	/// <param name="sock">ソケット</param>
	/// <param name="state">情報</param>
	void FirstSend(SOCKET sock,FirstToClientState state);

	/// <summary>
	/// サーバーの情報を取得する
	/// </summary>
	/// <returns>情報</returns>
	ServerToClientState GetServerState();

private:
	//自身のソケット
	MySocketServerPtr mMySocketServer;
	//サーバーが持っているソケット集
	std::vector<MySocketServerPtr>mMySocketServers;
	//サーバーが持っている情報
	ServerToClientState mServerState;
	//サーバー接続人数
	int mAcceptNum;

	//番号を振る際のフラグ
	bool mNumFlag;

	//前のデータを保存(パケットロス用)
	ServerToClientState mSeveState;
	//パケットロスかエラーしているかどうかの判断
	std::vector<bool> m_PacketLoss;

	//最初の情報
	FirstToClientState mFirstState;
};