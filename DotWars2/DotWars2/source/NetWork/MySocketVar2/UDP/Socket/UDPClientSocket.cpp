#include "UDPClientSocket.h"

UDPClientSocket::UDPClientSocket()
{
}

UDPClientSocket::~UDPClientSocket()
{
}

UDPClientSocket::SocketError UDPClientSocket::CreateSocket()
{
	SocketError error;
	mSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (mSocket == INVALID_SOCKET) {
		error.text = "�\�P�b�g�̍쐬�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

UDPClientSocket::SocketError UDPClientSocket::BindSocket(int port)
{
	SocketError error;
	struct sockaddr_in add;
	add.sin_family = AF_INET;


	//�����̃|�[�g��ς���
	add.sin_port = htons(port);
	add.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(mSocket, (struct sockaddr*)&add, sizeof(add)) != 0) {
		error.text = "�\�P�b�g�̃o�C���h�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	return error;
}

UDPClientSocket::SocketError UDPClientSocket::Send(sockaddr_in addr, DotWarsNet & state)
{
	sendto(mSocket, reinterpret_cast<char*>(&state), sizeof(state), 0, (struct sockaddr*)&addr, sizeof(addr));
	SocketError error;
	error.isError = false;
	return error;
}

UDPClientSocket::SocketError UDPClientSocket::Read(ServerToClientState & state)
{
	SocketError error;
	//�Z���N�g�Ńu���b�L���O�j�~
	fd_set set;
	//������
	FD_ZERO(&set);
	FD_SET(mSocket, &set);
	//�^�C���A�E�g���Ԑݒ�
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//�ǂݎ��o���邩�`�F�b�N
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//�G���[�̏ꍇ��null
		error.text = "�ǂݍ��݂̃Z���N�g�G���[";
		error.isError = true;
		return error;
	}
	//�ǂݍ��߂��Ԃ���Ȃ�������
	if (!FD_ISSET(mSocket, &set)) {
		error.isError = true;
		return error;
	}
	ServerToClientState net;
	if (recvfrom(mSocket, reinterpret_cast<char*>(&net), sizeof(net), 0, NULL, NULL) == SOCKET_ERROR) {
		error.text = "�ǂݍ��݃G���[";
		error.isError = true;
		return error;
	}
	state = net;
	error.isError = false;
	return error;

}

void UDPClientSocket::CloseSocket()
{
	closesocket(mSocket);
}
