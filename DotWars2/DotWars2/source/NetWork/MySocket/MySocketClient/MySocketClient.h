#pragma once
#include <string>
#include "../MySocketPtr.h"
#include "../../NetGameState.h"
#include "../MySocketServer/MySocketServer.h"
class MySocketClient {
public:
	MySocketClient();
	~MySocketClient();
	/// <summary>
	/// �\�P�b�g���쐬����
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn CreateSocket(SOCKET_STATE state);
	/// <summary>
	/// �\�P�b�g��MySocketServer�ɂ���
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <param name="socket">�\�P�b�g</param>
	/// <param name="addr">�A�h���X</param>
	void SetSocket(SOCKET_STATE state, const SOCKET& socket, const sockaddr_in& addr);
	/// <summary>
	/// �f�[�^�𑗂�(TCP�\�P�b�g�N���C�A���g�p)
	/// </summary>
	/// <param name="state">���肽���f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn Send(DotWarsNet state);
	/// <summary>
	/// �f�[�^�𑗂�(TCP�\�P�b�g�N���C�A���g�p)
	/// </summary>
	/// <param name="state">���肽���f�[�^</param>
	/// <returns>�G���[���e</returns>
	void SendUDP(DotWarsNet state);
	/// <summary>
	/// �o�C���h���� �A�h���X��INADDR_ANY(UDP�p)
	/// </summary>
	/// <param name="port">�|�[�g�ԍ�</param>
	SocketErrorReturn BindSocket(int port);



	/// <summary>
	/// �ŏ��̃f�[�^�𑗂�(TCP�\�P�b�g�N���C�A���g�p)
	/// </summary>
	/// <param name="state">���肽���f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn FirstSend();
	/// <summary>
	/// �ŏ��̃f�[�^����M����(TCP�N���C�A���g�\�P�b�g�p)
	/// </summary>
	/// <param name="socket">��M�������\�P�b�g</param>
	/// <param name="readState">�ǂݍ��݂����f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn FirstRead(FirstToClientState & readState);

	/// <summary>
	/// �f�[�^����M����(TCP�N���C�A���g�\�P�b�g�p)
	/// </summary>
	/// <param name="socket">��M�������\�P�b�g</param>
	/// <param name="readState">�ǂݍ��݂����f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn Read(ServerToClientState& readState);
	/// <summary>
	/// �T�[�o�[�ɐڑ�����(TCP�N���C�A���g�p)
	/// </summary>
	/// <param name="add">�ڑ�����A�h���X</param>
	/// <param name="port">�ڑ�����|�[�g�ԍ�</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn ConnectSocket(std::string add, int port);
	/// <summary>
	/// �\�P�b�g�̎�ނ��擾
	/// </summary>
	/// <returns>�\�P�b�g�̎��</returns>
	SOCKET_STATE GetSocketState();
	/// <summary>
	/// �\�P�b�g���擾
	/// </summary>
	/// <returns>�\�P�b�g</returns>
	SOCKET GetSocket();
	/// <summary>
	/// �A�h���X���擾
	/// </summary>
	/// <returns>�A�h���X</returns>
	sockaddr_in GetAddr();


	void CloseSocket();

private:
	//�\�P�b�g
	SOCKET mSocket;
	//�\�P�b�g�̎��
	SOCKET_STATE mSocketState;
	//�G���[���ǂ���
	bool mIsError;
	//�G���[���e
	std::string mErrorText;
	//�A�h���X���
	sockaddr_in mAddr;
	//�ڑ����Ă�T�[�o�[�̃A�h���X
	sockaddr_in mServerAddr;
};