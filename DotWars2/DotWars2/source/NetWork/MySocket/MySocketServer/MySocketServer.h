#pragma once
#include <string>
#include <vector>
#include <winsock.h>
#include "../MySocketPtr.h"
#include "../../NetGameState.h"
enum SOCKET_STATE {
	UDP_SERVER_SOCKET = SOCK_DGRAM,
	UDP_CLIENT_SOCKET = SOCK_DGRAM,
	TCP_SERVER_SOCKET = SOCK_STREAM,
	TCP_CLIENT_SOCKET = SOCK_STREAM
};
struct SocketErrorReturn {
	bool isError;   //�G���[���ǂ���True:�G���[False:����
	std::string errorText; //�G���[��
};
class MySocketServer {
public:
	MySocketServer();
	~MySocketServer();
	/// <summary>
	/// �\�P�b�g���쐬����
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn CreateSocket(SOCKET_STATE state);
	/// <summary>
	/// �\�P�b�g�Ƀo�C���h����
	/// </summary>
	/// <param name="port">�|�[�g�ԍ�</param>
	/// <param name="addres">�A�h���X</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn BindSocket(int port, const std::string & addres = INADDR_ANY);
	/// <summary>
	/// �\�P�b�g����t�̏�Ԃɂ���(TCP�T�[�o�[�\�P�b�g����)
	/// </summary>
	/// <param name="maxListen">�ő��t��</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn ListenSocket(int maxListen = 20);
	/// <summary>
	///�@�ڑ��҂�����
	/// </summary>
	/// <param name="socketPtr">�ڑ����ꂽ�炱���ɓ���</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn  AcceptSocket(MySocketServerPtr& socketPtr);
	/// <summary>
	/// �\�P�b�g��MySocketServer�ɂ���
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <param name="socket">�\�P�b�g</param>
	/// <param name="addr">�A�h���X</param>
	void SetSocket(SOCKET_STATE state, const SOCKET& socket, const sockaddr_in& addr);


	/// <summary>
	/// �ŏ��Ɏg���f�[�^�𑗂�
	/// </summary>
	/// <param name="socket">�\�P�b�g</param>
	/// <param name="state">���肽���f�[�^</param>
	SocketErrorReturn FirstSend(SOCKET socket, FirstToClientState state);

	/// <summary>
	/// �ŏ��̃f�[�^����M����(TCP�T�[�o�[�\�P�b�g�p)
	/// </summary>
	/// <param name="socket">��M�������\�P�b�g</param>
	/// <param name="readState">�ǂݍ��݂����f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn FirstRead(SOCKET socket, FirstToClientState& readState);
	/// <summary>
	/// �f�[�^�𑗂�(TCP�\�P�b�g�T�[�o�[�p)
	/// </summary>
	/// <param name="socket">���肽���\�P�b�g</param>
	/// <param name="state">���肽���f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn SendSocket(SOCKET socket, ServerToClientState state);

	/// <summary>
	/// �f�[�^�𑗂�(UDP�\�P�b�g�T�[�o�[�p)
	/// </summary>
	/// <param name="socket">���肽���\�P�b�g</param>
	/// <param name="state">���肽���f�[�^</param>
	/// <returns>�G���[���e</returns>
	void SendSocketUDP(ServerToClientState state);


	/// <summary>
	/// �f�[�^����M����(TCP�T�[�o�[�\�P�b�g�p)
	/// </summary>
	/// <param name="socket">��M�������\�P�b�g</param>
	/// <param name="readState">�ǂݍ��݂����f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketErrorReturn ReadSocket(SOCKET socket, DotWarsNet& readState);
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

	/// <summary>
	/// �\�P�b�g���폜����
	/// </summary>
	void CloseSocket();

private:
	//���ݐڑ�����Ă���N���C�A���g�̃A�h���X
	std::vector<sockaddr_in>mClientAddrs;

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
};