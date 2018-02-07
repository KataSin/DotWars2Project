#pragma once
#include <winsock.h>
#include <vector>
#include "../Socket/UDPServerSocket.h"
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class UDPServerSocketManager {
public:
	UDPServerSocketManager();
	~UDPServerSocketManager();
	/// <summary>
	/// �o�C���h����
	/// </summary>
	/// <returns></returns>
	bool Bind();
	/// <summary>
	/// TCP�Ŏ擾�����N���C�A���g����ǉ�����
	/// </summary>
	/// <param name="add"></param>
	void AddClientAdd(TCPClientSocketPtr client);
	/// <summary>
	/// �����擾����
	/// </summary>
	void Read();
	/// <summary>
	/// ���𑗂�
	/// </summary>
	void Send();
	/// <summary>
	/// �����擾����
	/// </summary>
	/// <returns></returns>
	ServerToClientState GetState();
	/// <summary>
	/// �T�[�o�[�����Z�b�g����
	/// </summary>
	/// <param name="state">���</param>
	void SetState(const ServerToClientState& state);

	/// <summary>
	/// �\�P�b�g�����
	/// </summary>
	void Close();


private:
	UDPServerSocketPtr mSocket;
	//�T�[�o�[�������Ă�����
	ServerToClientState mServerState;
	std::vector<TCPClientSocketPtr> mClients;


};