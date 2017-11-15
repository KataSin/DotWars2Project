#pragma once
#include <string>
#include <WinSock2.h>
#include "../MySocketPtr.h"
#include "../../NetGameState.h"
#include "../MySocketServer/MySocketServer.h"
class MySocketClient {
public:
	MySocketClient();
	~MySocketClient();
	/// <summary>
	/// ソケットを作成する
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn CreateSocket(SOCKET_STATE state);
	/// <summary>
	/// ソケットをMySocketServerにする
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <param name="socket">ソケット</param>
	/// <param name="addr">アドレス</param>
	void SetSocket(SOCKET_STATE state, const SOCKET& socket, const sockaddr_in& addr);
	/// <summary>
	/// データを送る(TCPソケットクライアント用)
	/// </summary>
	/// <param name="socket">送りたいソケット</param>
	/// <param name="state">送りたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn SendSocket(DotWarsNet state);
	/// <summary>
	/// データを受信する(TCPクライアントソケット用)
	/// </summary>
	/// <param name="socket">受信したいソケット</param>
	/// <param name="readState">読み込みたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn ReadSocket(ServerToClientState& readState);
	/// <summary>
	/// サーバーに接続する(TCPクライアント用)
	/// </summary>
	/// <param name="add">接続するアドレス</param>
	/// <param name="port">接続するポート番号</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn ConnectSocket(std::string add, int port);
	/// <summary>
	/// ソケットの種類を取得
	/// </summary>
	/// <returns>ソケットの種類</returns>
	SOCKET_STATE GetSocketState();
	/// <summary>
	/// ソケットを取得
	/// </summary>
	/// <returns>ソケット</returns>
	SOCKET GetSocket();
	/// <summary>
	/// アドレスを取得
	/// </summary>
	/// <returns>アドレス</returns>
	sockaddr_in GetAddr();

private:
	//ソケット
	SOCKET mSocket;
	//ソケットの種類
	SOCKET_STATE mSocketState;
	//エラーかどうか
	bool mIsError;
	//エラー内容
	std::string mErrorText;
	//アドレス情報
	sockaddr_in mAddr;
};