#pragma once
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
#include <winsock.h>
class TCPClientSocketManager {
public:
	TCPClientSocketManager();
	~TCPClientSocketManager();
	//�T�[�o�[�ɐڑ�����
	bool Connect(std::string addr,int port);
	//�T�[�o�[��������擾(return:�����������ǂ��� state:�ǂݎ�������)
	bool Read(FirstToClientState& state);
	//�\�P�b�g�����
	bool Close();
	//�ڑ������T�[�o�[�̃A�h���X���擾
	sockaddr_in GetServerAddr();
private:
	TCPClientSocketPtr mSocket;
	//�T�[�o�[�̃A�h���X
	sockaddr_in mServerAddr;
};