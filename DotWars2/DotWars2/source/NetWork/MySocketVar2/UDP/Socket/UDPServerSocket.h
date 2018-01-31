#pragma once
#include <winsock.h>
#include <string>

#include "../../../NetGameState.h"
class UDPServerSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	UDPServerSocket();
	~UDPServerSocket();
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
	/// 情報を送る
	/// </summary>
	/// <param name="state">情報</param>
	SocketError Send(SOCKET socket, ServerToClientState& state);
	/// <summary>
	/// 情報をもらう
	/// </summary>
	/// <param name="state"></param>
	/// <returns></returns>
	SocketError Read(DotWarsNet& state);
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