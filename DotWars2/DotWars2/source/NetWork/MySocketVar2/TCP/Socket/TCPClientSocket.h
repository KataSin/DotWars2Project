#pragma once
#include <string>
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class TCPClientSocket {
public:
	struct SocketError {
		bool isError = false;
		std::string text;
	};
public:
	TCPClientSocket();
	~TCPClientSocket();
	/// <summary>
	/// �\�P�b�g���쐬����
	/// </summary>
	/// <returns>�G���[���e</returns>
	SocketError CreateSocket();
	/// <summary>
	/// �f�[�^����M����
	/// </summary>
	/// <param name="socket">��M�������\�P�b�g</param>
	/// <param name="readState">�ǂݍ��݂����f�[�^</param>
	/// <returns>�G���[���e</returns>
	SocketError Read(FirstToClientState & readState);
	/// <summary>
	/// �T�[�o�[�ɐڑ�����
	/// </summary>
	/// <param name="add">�ڑ�����A�h���X</param>
	/// <param name="port">�ڑ�����|�[�g�ԍ�</param>
	/// <returns>�G���[���e</returns>
	SocketError ConnectSocket(std::string add, int port);
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
	/// �\�P�b�g��MySocketServer�ɂ���
	/// </summary>
	/// <param name="state">�\�P�b�g�̎��</param>
	/// <param name="socket">�\�P�b�g</param>
	/// <param name="addr">�A�h���X</param>
	void SetSocket(const SOCKET& socket, const sockaddr_in& addr);
	/// <summary>
	/// �\�P�b�g�����
	/// </summary>
	void CloseSocket();

private:
	//�\�P�b�g
	SOCKET mSocket;
	//�A�h���X���
	sockaddr_in mAddr;

};