#pragma once
#include <winsock.h>
#include <string>

#include "../../../NetGameState.h"
class UDPClientSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	UDPClientSocket();
	~UDPClientSocket();
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
	SocketError BindSocket(int port);
	/// <summary>
	/// ���𑗂�
	/// </summary>
	/// <param name="addr">���肽���A�h���X</param>
	/// <param name="state">���肽�����</param>
	/// <returns></returns>
	SocketError Send(sockaddr_in addr, DotWarsNet& state);
	/// <summary>
	/// �������炤
	/// </summary>
	/// <param name="state"></param>
	/// <returns></returns>
	SocketError Read(ServerToClientState& state);
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