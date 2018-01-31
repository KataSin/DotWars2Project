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
	/// ���g�̃\�P�b�g������
	/// </summary>
	void CloseSocket();
	/// <summary>
	/// �o�C���h����
	/// </summary>
	void Bind(int port);

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
	bool AcceptServer(int max);
	/// <summary>
	/// �N���C�A���g��������擾����
	/// </summary>
	void Read();
	/// <summary>
	/// �N���C�A���g�ɏ��𑗂�
	/// </summary>
	void Send();
	/// <summary>
	/// �ŏ��̏��𑗂�
	/// </summary>
	/// <param name="sock">�\�P�b�g</param>
	/// <param name="state">���</param>
	void FirstSend(SOCKET sock,FirstToClientState state);

	/// <summary>
	/// �T�[�o�[�̏����擾����
	/// </summary>
	/// <returns>���</returns>
	ServerToClientState GetServerState();

private:
	//���g�̃\�P�b�g
	MySocketServerPtr mMySocketServer;
	//�T�[�o�[�������Ă���\�P�b�g�W
	std::vector<MySocketServerPtr>mMySocketServers;
	//�T�[�o�[�������Ă�����
	ServerToClientState mServerState;
	//�T�[�o�[�ڑ��l��
	int mAcceptNum;

	//�ԍ���U��ۂ̃t���O
	bool mNumFlag;

	//�O�̃f�[�^��ۑ�(�p�P�b�g���X�p)
	ServerToClientState mSeveState;
	//�p�P�b�g���X���G���[���Ă��邩�ǂ����̔��f
	std::vector<bool> m_PacketLoss;

	//�ŏ��̏��
	FirstToClientState mFirstState;
};