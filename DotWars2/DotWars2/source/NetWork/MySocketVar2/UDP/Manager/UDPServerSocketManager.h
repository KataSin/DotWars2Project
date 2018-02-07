#pragma once
#include <winsock.h>
#include <vector>
#include "../Socket/UDPServerSocket.h"
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class UDPServerSocketManager {
public:
	UDPServerSocketManager();
	~UDPServerSocketManager();
	/// <summary>
	/// バインドする
	/// </summary>
	/// <returns></returns>
	bool Bind();
	/// <summary>
	/// TCPで取得したクライアント情報を追加する
	/// </summary>
	/// <param name="add"></param>
	void AddClientAdd(TCPClientSocketPtr client);
	/// <summary>
	/// 情報を取得する
	/// </summary>
	void Read();
	/// <summary>
	/// 情報を送る
	/// </summary>
	void Send();
	/// <summary>
	/// 情報を取得する
	/// </summary>
	/// <returns></returns>
	ServerToClientState GetState();
	/// <summary>
	/// サーバー情報をセットする
	/// </summary>
	/// <param name="state">情報</param>
	void SetState(const ServerToClientState& state);

	/// <summary>
	/// ソケットを閉じる
	/// </summary>
	void Close();


private:
	UDPServerSocketPtr mSocket;
	//サーバーが持っている情報
	ServerToClientState mServerState;
	std::vector<TCPClientSocketPtr> mClients;


};