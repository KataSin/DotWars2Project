#pragma once
#include <winsock.h>
#include <string>

#include "../../../NetGameState.h"
class UDPServerSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	UDPServerSocket();
	~UDPServerSocket();
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
	/// ���𑗂�
	/// </summary>
	/// <param name="state">���</param>
	SocketError Send(SOCKET socket, ServerToClientState& state);
	/// <summary>
	/// �������炤
	/// </summary>
	/// <param name="state"></param>
	/// <returns></returns>
	SocketError Read(DotWarsNet& state);
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