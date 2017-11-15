#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../MySocketClient/MySocketClient.h"
#include "../../NetGameState.h"
#include <string>
#include <winsock.h>
#include <vector>
class MySocketClientManager {
public:
	MySocketClientManager();
	~MySocketClientManager();

	/// <summary>
	/// �\�P�b�g�������ݒ�
	/// </summary>
	/// <param name="state"></param>
	void Initialize(const SOCKET_STATE& state);
	/// <summary>
	/// �T�[�o�[�ɐڑ�����
	/// </summary>
	/// <param name="addr">�A�h���X</param>
	/// <param name="port">�|�[�g</param>
	void ConnectClient(const std::string& addr,int port);
	/// <summary>
	/// �����T�[�o�[�ɑ���
	/// </summary>
	void SendClient();
	/// <summary>
	/// �����N���C�A���g����󂯎��
	/// </summary>
	void ReadClient();

private:
	//���g�̃\�P�b�g
	MySocketClientPtr mMySocketClient;
	//���g�̏��
	DotWarsNet mNetState;
	//�T�[�o�[�̏��
	ServerToClientState mServerState;
};