#pragma once
#pragma once
#include <winsock.h>
#include <vector>
#include "../Socket/UDPServerSocket.h"
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class UDPClientSocketManager {
public:
	UDPClientSocketManager();
	~UDPClientSocketManager();
	/// <summary>
	/// バインドする(port番号を決めたいのでプレイヤー番号が必要)
	/// </summary>
	/// <param name="state">最初にもらった情報</param>
	/// <returns></returns>
	bool Bind(const FirstToClientState& state);
	/// <summary>
	/// 情報を取得する
	/// </summary>
	void Read();
	/// <summary>
	/// 情報を送る
	/// </summary>
	void Send();
	///// <summary>
	///// 情報を受信
	///// </summary>
	///// <returns></returns>
	//ServerToClientState GetState();
	/// <summary>
	/// ソケットを閉じる
	/// </summary>
	void Close();
	/// <summary>
	/// サーバーのアドレス設定
	/// </summary>
	void SetServerAddr(const sockaddr_in& addr);
	/// <summary>
	/// 送る情報をセット
	/// </summary>
	/// <param name="state"></param>
	void SetState(const DotWarsNet& state);
	/// <summary>
	/// 情報をもらう
	/// </summary>
	/// <returns></returns>
	ServerToClientState GetServerState();
private:
	UDPClientSocketPtr mSocket;
	ServerToClientState mServerToState;
	DotWarsNet mDotNetState;
	//サーバーのアドレス
	sockaddr_in mServerAddr;


};