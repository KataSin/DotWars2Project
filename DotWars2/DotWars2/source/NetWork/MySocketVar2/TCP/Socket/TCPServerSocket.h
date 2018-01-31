#pragma once
#include <string>
#include <vector>
#include <winsock.h>
#include "../../../NetGameState.h"
#include "../../SocketPtr.h"

class TCPServerSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	TCPServerSocket();
	~TCPServerSocket();
	/// <summary>
	/// �\�P�b�g���쐬����
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <returns>�G���[���e</returns>
	SocketError CreateSocket();
	/// <summary>
	/// �\�P�b�g�Ƀo�C���h����
	/// </summary>
	/// <param name="port">�|�[�g�ԍ�</param>
	/// <param name="addres">�A�h���X</param>
	/// <returns>�G���[���e</returns>
	SocketError BindSocket(const std::string&  addres, int port);
	/// <summary>
	/// �\�P�b�g����t�̏�Ԃɂ���(TCP�T�[�o�[�\�P�b�g����)
	/// </summary>
	/// <param name="maxListen">�ő��t��</param>
	/// <returns>�G���[���e</returns>
	SocketError ListenSocket(int maxListen = 20);
	/// <summary>
	///�@�ڑ��҂�����
	/// </summary>
	/// <param name="socketPtr">�ڑ����ꂽ�炱���ɓ���</param>
	/// <returns>�G���[���e</returns>
	SocketError  AcceptSocket(TCPClientSocketPtr& socketPtr);
	/// <summary>
	/// ���𑗂�
	/// </summary>
	/// <param name="state">���</param>
	SocketError Send(SOCKET socket, FirstToClientState& state);

	/// <summary>
	/// �\�P�b�g���폜����
	/// </summary>
	void CloseSocket();

private:
	//�\�P�b�g
	SOCKET mSocket;
	//�A�h���X���
	sockaddr_in mAddr;
};