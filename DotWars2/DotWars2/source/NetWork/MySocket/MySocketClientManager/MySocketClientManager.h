#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../MySocketClient/MySocketClient.h"
#include "../../NetGameState.h"
#include <string>
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
	/// ソケットを閉じる
	/// </summary>
	void CloseSocket();

	/// <summary>
	/// サーバーに接続する
	/// </summary>
	/// <param name="addr">アドレス</param>
	/// <param name="port">ポート</param>
	bool ConnectClient(const std::string& addr,int port);
	/// <summary>
	/// 情報をサーバーに送る
	/// </summary>
	void Send();
	/// <summary>
	/// 情報をサーバーから受け取る
	/// </summary>
	bool Read();
	/// <summary>
	/// 最初の情報を受け取る
	/// </summary>
	bool FirstRead();
	/// <summary>
	/// ソケットをバインドする
	/// </summary>
	bool Bind(int port);
	/// <summary>
	/// 送る情報を設定
	/// </summary>
	/// <param name="state">情報</param>
	void SetState(const DotWarsNet& state);
	/// <summary>
	/// 情報を取得
	/// </summary>
	/// <returns>情報</returns>
	ServerToClientState GetState();
	/// <summary>
	/// 最初の情報を取得
	/// </summary>
	/// <returns></returns>
	FirstToClientState GetFirstState();
private:
	//自身のソケット
	MySocketClientPtr mMySocketClient;
	//自身の情報
	DotWarsNet mNetState;
	//サーバーの情報
	ServerToClientState mServerState;
	//最初の情報
	FirstToClientState mFirstState;

};