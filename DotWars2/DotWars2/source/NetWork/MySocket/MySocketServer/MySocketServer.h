#pragma once
#include <string>
#include <vector>
#include <winsock.h>
#include "../MySocketPtr.h"
#include "../../NetGameState.h"
enum SOCKET_STATE {
	UDP_SERVER_SOCKET = SOCK_DGRAM,
	UDP_CLIENT_SOCKET = SOCK_DGRAM,
	TCP_SERVER_SOCKET = SOCK_STREAM,
	TCP_CLIENT_SOCKET = SOCK_STREAM
};
struct SocketErrorReturn {
	bool isError;   //エラーかどうかTrue:エラーFalse:正常
	std::string errorText; //エラー文
};
class MySocketServer {
public:
	MySocketServer();
	~MySocketServer();
	/// <summary>
	/// ソケットを作成する
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn CreateSocket(SOCKET_STATE state);
	/// <summary>
	/// ソケットにバインドする
	/// </summary>
	/// <param name="port">ポート番号</param>
	/// <param name="addres">アドレス</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn BindSocket(int port, const std::string & addres = INADDR_ANY);
	/// <summary>
	/// ソケットを受付の状態にする(TCPサーバーソケット限定)
	/// </summary>
	/// <param name="maxListen">最大受付数</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn ListenSocket(int maxListen = 20);
	/// <summary>
	///　接続待ちする
	/// </summary>
	/// <param name="socketPtr">接続されたらここに入る</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn  AcceptSocket(MySocketServerPtr& socketPtr);
	/// <summary>
	/// ソケットをMySocketServerにする
	/// </summary>
	/// <param name="state">ソケットの種類</param>
	/// <param name="socket">ソケット</param>
	/// <param name="addr">アドレス</param>
	void SetSocket(SOCKET_STATE state, const SOCKET& socket, const sockaddr_in& addr);


	/// <summary>
	/// 最初に使うデータを送る
	/// </summary>
	/// <param name="socket">ソケット</param>
	/// <param name="state">送りたいデータ</param>
	SocketErrorReturn FirstSend(SOCKET socket, FirstToClientState state);

	/// <summary>
	/// 最初のデータを受信する(TCPサーバーソケット用)
	/// </summary>
	/// <param name="socket">受信したいソケット</param>
	/// <param name="readState">読み込みたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn FirstRead(SOCKET socket, FirstToClientState& readState);
	/// <summary>
	/// データを送る(TCPソケットサーバー用)
	/// </summary>
	/// <param name="socket">送りたいソケット</param>
	/// <param name="state">送りたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn SendSocket(SOCKET socket, ServerToClientState state);

	/// <summary>
	/// データを送る(UDPソケットサーバー用)
	/// </summary>
	/// <param name="socket">送りたいソケット</param>
	/// <param name="state">送りたいデータ</param>
	/// <returns>エラー内容</returns>
	void SendSocketUDP(ServerToClientState state);


	/// <summary>
	/// データを受信する(TCPサーバーソケット用)
	/// </summary>
	/// <param name="socket">受信したいソケット</param>
	/// <param name="readState">読み込みたいデータ</param>
	/// <returns>エラー内容</returns>
	SocketErrorReturn ReadSocket(SOCKET socket, DotWarsNet& readState);
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

	/// <summary>
	/// ソケットを削除する
	/// </summary>
	void CloseSocket();

private:
	//現在接続されているクライアントのアドレス
	std::vector<sockaddr_in>mClientAddrs;

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