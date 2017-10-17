//#pragma once
//#include <string>
//#include <WinSock2.h>
//class MySocket {
//public:
//	enum UDP_OR_TCP
//	{
//		UDP_NETWORK= SOCK_DGRAM,
//		TCP_NETWORK=SOCK_STREAM
//	};
//public:
//	MySocket();
//	~MySocket();
//	void CreateSocket(const UDP_OR_TCP& net,const std::string& addres,int port);
//	void CreateServerSocket(const UDP_OR_TCP& net);
//
//
//private:
//	//ソケット
//	SOCKET mSocket;
//	//エラーかどうか
//	bool mIsError;
//	//エラー内容
//	std::string mErrorText;
//	sockaddr_in server;
//};