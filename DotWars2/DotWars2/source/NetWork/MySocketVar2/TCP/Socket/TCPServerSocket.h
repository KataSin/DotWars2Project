#pragma once
#include <string>
#include <vector>
#include <winsock.h>
#include "../../../NetGameState.h"
#include "../../SocketPtr.h"

class TCPServerSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	TCPServerSocket();
	~TCPServerSocket();
	/// <summary>
	/// ソケットを作成する
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <returns>エラー内容</returns>
	SocketError CreateSocket();
	/// <summary>
	/// ソケットにバインドする
	/// </summary>
	/// <param name="port">ポート番号</param>
	/// <param name="addres">アドレス</param>
	/// <returns>エラー内容</returns>
	SocketError BindSocket(const std::string&  addres, int port);
	/// <summary>
	/// ソケットを受付の状態にする(TCPサーバーソケット限定)
	/// </summary>
	/// <param name="maxListen">最大受付数</param>
	/// <returns>エラー内容</returns>
	SocketError ListenSocket(int maxListen = 20);
	/// <summary>
	///　接続待ちする
	/// </summary>
	/// <param name="socketPtr">接続されたらここに入る</param>
	/// <returns>エラー内容</returns>
	SocketError  AcceptSocket(TCPClientSocketPtr& socketPtr);
	/// <summary>
	/// 情報を送る
	/// </summary>
	/// <param name="state">情報</param>
	SocketError Send(SOCKET socket, FirstToClientState& state);

	/// <summary>
	/// ソケットを削除する
	/// </summary>
	void CloseSocket();

private:
	//ソケット
	SOCKET mSocket;
	//アドレス情報
	sockaddr_in mAddr;
};