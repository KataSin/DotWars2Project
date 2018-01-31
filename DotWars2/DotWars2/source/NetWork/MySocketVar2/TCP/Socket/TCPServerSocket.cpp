#include "TCPServerSocket.h"
#include "TCPClientSocket.h"
TCPServerSocket::TCPServerSocket()
{
}

TCPServerSocket::~TCPServerSocket()
{
}

TCPServerSocket::SocketError TCPServerSocket::CreateSocket()
{
	SocketError error;
	mSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (mSocket == INVALID_SOCKET) {
		error.text = "�\�P�b�g�̍쐬�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

TCPServerSocket::SocketError TCPServerSocket::BindSocket(const std::string&  addres, int port)
{
	SocketError error;
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(port);
	mAddr.sin_addr.S_un.S_addr = inet_addr(addres.c_str());
	if (bind(mSocket, (struct sockaddr *)&mAddr, sizeof(mAddr)) != 0) {
		error.text = "�\�P�b�g�̃o�C���h�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;

}

TCPServerSocket::SocketError TCPServerSocket::ListenSocket(int maxListen)
{
	SocketError error;
	if (listen(mSocket, maxListen) != 0) {
		error.text = "�\�P�b�g�̑ҋ@�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

TCPServerSocket::SocketError TCPServerSocket::AcceptSocket(TCPClientSocketPtr& socketPtr)
{
	SocketError error;
	sockaddr_in addr;
	SOCKET sock;
	int len;
	//�Z���N�g�Ńu���b�L���O�j�~
	fd_set set;
	//������
	FD_ZERO(&set);
	FD_SET(mSocket, &set);
	//�^�C���A�E�g���Ԑݒ�
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//�A�N�Z�v�g�o���邩�`�F�b�N
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//�G���[�̏ꍇ��null
		error.text = "�A�N�Z�v�g�̃Z���N�g�G���[";
		error.isError = true;
		return error;
	}
	//�����A�N�Z�v�g���ł����Ԃ���Ȃ�������null��Ԃ�
	if (!(FD_ISSET(mSocket, &set))) {
		error.isError = true;
		return error;
	}
	len = sizeof(addr);
	sock = accept(mSocket, (struct sockaddr*)&addr, &len);
	if (sock < 0) {
		error.text = "�\�P�b�g�A�N�Z�v�g�G���[";
		error.isError = true;
		return error;
	}
	//�N���C�A���g�\�P�b�g�ݒ�
	socketPtr = std::make_shared<TCPClientSocket>();
	socketPtr->SetSocket(sock, addr);

	error.isError = false;
	return error;

}

TCPServerSocket::SocketError TCPServerSocket::Send(SOCKET socket,FirstToClientState & state)
{
	SocketError error;
	if (send(socket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.text = "�T�[�o�[����̑��M�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;

}

void TCPServerSocket::CloseSocket()
{
	closesocket(mSocket);
}
