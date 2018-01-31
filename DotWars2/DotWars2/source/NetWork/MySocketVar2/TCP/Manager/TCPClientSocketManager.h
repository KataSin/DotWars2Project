#pragma once
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
#include <winsock.h>
class TCPClientSocketManager {
public:
	TCPClientSocketManager();
	~TCPClientSocketManager();
	//サーバーに接続する
	bool Connect(std::string addr,int port);
	//サーバーから情報を取得(return:成功したかどうか state:読み取った情報)
	bool Read(FirstToClientState& state);
	//ソケットを閉じる
	bool Close();
	//接続したサーバーのアドレスを取得
	sockaddr_in GetServerAddr();
private:
	TCPClientSocketPtr mSocket;
	//サーバーのアドレス
	sockaddr_in mServerAddr;
};