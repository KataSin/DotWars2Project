#pragma once
#include <string>
#include <WinSock2.h>
class MySocket {
public:
	enum UDP_OR_TCP
	{
		UDP_NETWORK,
		TCP_NETWORK
	};
public:
	MySocket();
	~MySocket();
	void CreateSocket(const UDP_OR_TCP& net,const std::string& addres);

private:
	//�G���[���ǂ���
	bool mIsError;
	//�G���[���e
	std::string mErrorText;
	sockaddr_in server;
};