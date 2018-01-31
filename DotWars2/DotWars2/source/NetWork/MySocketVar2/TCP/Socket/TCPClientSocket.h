#pragma once
#include <string>
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class TCPClientSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	TCPClientSocket();
	~TCPClientSocket();
	/// <summary>
	/// ソケットを作成する
	/// </summary>
	/// <returns>エラー内容</returns>
	SocketError CreateSocket();
	/// <summary>
	/// データを受信する
	/// </summary>
	/// <param name="socket">受信したいソケット</param>
	/// <param name="readState">読み込みたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketError Read(FirstToClientState & readState);
	/// <summary>
	/// サーバーに接続する
	/// </summary>
	/// <param name="add">接続するアドレス</param>
	/// <param name="port">接続するポート番号</param>
	/// <returns>エラー内容</returns>
	SocketError ConnectSocket(std::string add, int port);
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
	/// <summary>
	/// ソケットをMySocketServerにする
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <param name="socket">ソケット</param>
	/// <param name="addr">アドレス</param>
	void SetSocket(const SOCKET& socket, const sockaddr_in& addr);
	/// <summary>
	/// ソケットを閉じる
	/// </summary>
	void CloseSocket();

private:
	//ソケット
	SOCKET mSocket;
	//アドレス情報
	sockaddr_in mAddr;

};