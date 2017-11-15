#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../../NetGameState.h"
#include <string>
#include <winsock.h>
#include <vector>
class MySocketServerManager {
public:
	MySocketServerManager();
	~MySocketServerManager();
	
	/// <summary>
	/// �\�P�b�g�������ݒ�
	/// </summary>
	/// <param name="state"></param>
	void Initialize(const SOCKET_STATE& state);
	/// <summary>
	/// �T�[�o�[���J����(TCP�T�[�o�[�\�P�b�g����)
	/// </summary>
	/// <param name="port">�|�[�g�ԍ�</param>
	/// <param name="addr">�A�h���X</param>
	void OpenServer(int port,const std::string& addr);
	/// <summary>
	/// �ڑ��҂�������(TCP�T�[�o�[�\�P�b�g����)
	/// </summary>
	/// <param name="max">�ő�ڑ��l��</param>
	void AcceptServer(int max);
	/// <summary>
	/// �����T�[�o�[����S�N���C�A���g�ɑ���
	/// </summary>
	void SendStateServerToClient();
	/// <summary>
	/// �����N���C�A���g����󂯎��
	/// </summary>
	void ReadStateServer();
private:
	//���g�̃\�P�b�g
	MySocketServerPtr mMySocketServer;
	//�T�[�o�[�������Ă���\�P�b�g�W
	std::vector<MySocketServerPtr>mMySocketServers;
	//�T�[�o�[�������Ă�����
	ServerToClientState mServerState;
};