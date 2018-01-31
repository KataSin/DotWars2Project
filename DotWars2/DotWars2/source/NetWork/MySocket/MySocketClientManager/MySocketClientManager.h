#pragma once
#include "../MySocketPtr.h"
#include "../MySocketServer/MySocketServer.h"
#include "../MySocketClient/MySocketClient.h"
#include "../../NetGameState.h"
#include <string>
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
	/// �\�P�b�g�����
	/// </summary>
	void CloseSocket();

	/// <summary>
	/// �T�[�o�[�ɐڑ�����
	/// </summary>
	/// <param name="addr">�A�h���X</param>
	/// <param name="port">�|�[�g</param>
	bool ConnectClient(const std::string& addr,int port);
	/// <summary>
	/// �����T�[�o�[�ɑ���
	/// </summary>
	void Send();
	/// <summary>
	/// �����T�[�o�[����󂯎��
	/// </summary>
	bool Read();
	/// <summary>
	/// �ŏ��̏����󂯎��
	/// </summary>
	bool FirstRead();
	/// <summary>
	/// �\�P�b�g���o�C���h����
	/// </summary>
	bool Bind(int port);
	/// <summary>
	/// �������ݒ�
	/// </summary>
	/// <param name="state">���</param>
	void SetState(const DotWarsNet& state);
	/// <summary>
	/// �����擾
	/// </summary>
	/// <returns>���</returns>
	ServerToClientState GetState();
	/// <summary>
	/// �ŏ��̏����擾
	/// </summary>
	/// <returns></returns>
	FirstToClientState GetFirstState();
private:
	//���g�̃\�P�b�g
	MySocketClientPtr mMySocketClient;
	//���g�̏��
	DotWarsNet mNetState;
	//�T�[�o�[�̏��
	ServerToClientState mServerState;
	//�ŏ��̏��
	FirstToClientState mFirstState;

};