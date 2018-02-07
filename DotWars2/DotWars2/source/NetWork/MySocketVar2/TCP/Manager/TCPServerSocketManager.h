#pragma once
#include "../../../NetGameState.h"
#include "../Socket/TCPServerSocket.h"
#include "../../SocketPtr.h"
#include <vector>
class TCPServerSocketManager
{
public:
	TCPServerSocketManager();
	~TCPServerSocketManager();
	//�ڑ��҂�������(listenNum:��t�l��)
	bool Listen(int listenNum);
	//�N���C�A���g�̐ڑ���҂�(�l���ɒB������true)
	bool Accept();
	//�o�C���h����
	bool Bind();
	//���𑗂�
	bool Send();
	//�\�P�b�g�����
	bool Close();
	//�ڑ����Ă����\�P�b�g�������擾
	std::vector<TCPClientSocketPtr>GetConnectSockets();
	//�ŏ��̏���ServerToClientState�Ŏ����Ă���
	ServerToClientState GetFirstState();
private:
	//�ڑ��҂�����l��
	int mPlayerNum;
	//�ŏ��ɃT�[�o�[�ɑ�����
	std::vector<FirstToClientState>mToClientState;
	//�N���C�A���g�\�P�b�g����
	std::vector<TCPClientSocketPtr> mClientSockets;

	TCPServerSocketPtr mSocket;

	//�N���C�A���g�ɑ���T�[�o�[���
	ServerToClientState mServerToState;
};