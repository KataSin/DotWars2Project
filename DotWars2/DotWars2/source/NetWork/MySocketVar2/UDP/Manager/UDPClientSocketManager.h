#pragma once
#pragma once
#include <winsock.h>
#include <vector>
#include "../Socket/UDPServerSocket.h"
#include "../../SocketPtr.h"
#include "../../../NetGameState.h"
class UDPClientSocketManager {
public:
	UDPClientSocketManager();
	~UDPClientSocketManager();
	/// <summary>
	/// �o�C���h����(port�ԍ������߂����̂Ńv���C���[�ԍ����K�v)
	/// </summary>
	/// <param name="state">�ŏ��ɂ���������</param>
	/// <returns></returns>
	bool Bind(const FirstToClientState& state);
	/// <summary>
	/// �����擾����
	/// </summary>
	void Read();
	/// <summary>
	/// ���𑗂�
	/// </summary>
	void Send();
	///// <summary>
	///// ������M
	///// </summary>
	///// <returns></returns>
	//ServerToClientState GetState();
	/// <summary>
	/// �\�P�b�g�����
	/// </summary>
	void Close();
	/// <summary>
	/// �T�[�o�[�̃A�h���X�ݒ�
	/// </summary>
	void SetServerAddr(const sockaddr_in& addr);
	/// <summary>
	/// ��������Z�b�g
	/// </summary>
	/// <param name="state"></param>
	void SetState(const DotWarsNet& state);
	/// <summary>
	/// �������炤
	/// </summary>
	/// <returns></returns>
	ServerToClientState GetServerState();
private:
	UDPClientSocketPtr mSocket;
	ServerToClientState mServerToState;
	DotWarsNet mDotNetState;
	//�T�[�o�[�̃A�h���X
	sockaddr_in mServerAddr;


};