#include "MySocketServer.h"

MySocketServer::MySocketServer()
{
}

MySocketServer::~MySocketServer()
{
}

SocketErrorReturn MySocketServer::CreateSocket(SOCKET_STATE state)
{
	SocketErrorReturn error;
	mSocket = socket(AF_INET, (int)state, 0);
	mSocketState = state;
	if (mSocket == INVALID_SOCKET) {
		error.errorText = "�\�P�b�g�̍쐬�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketServer::BindSocket(int port, const std::string & addres)
{
	SocketErrorReturn error;
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(port);
	mAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(mSocket, (struct sockaddr *)&mAddr, sizeof(addres)) != 0) {
		error.errorText = "�\�P�b�g�̃o�C���h�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketServer::ListenSocket(int maxListen)
{
	SocketErrorReturn error;
	if (listen(mSocket, maxListen) != 0) {
		error.errorText= "�\�P�b�g�̑ҋ@�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketServer::AcceptSocket(MySocketServerPtr& socketPtr)
{
	SocketErrorReturn error;
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
		error.errorText = "�A�N�Z�v�g�̃Z���N�g�G���[";
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
		error.errorText = "�\�P�b�g�A�N�Z�v�g�G���[";
		error.isError = true;
		return error;
	}
	auto socket = std::make_shared<MySocketServer>();
	socket->SetSocket(SOCKET_STATE::TCP_CLIENT_SOCKET, sock, addr);
	socketPtr = socket;

	error.isError = false;
	return error;
}
void MySocketServer::SetSocket(SOCKET_STATE state, const SOCKET & socket, const sockaddr_in & addr)
{
	mSocketState = state;
	mSocket = socket;
	mAddr = addr;
}

SocketErrorReturn MySocketServer::FirstSend(SOCKET socket, FirstToClientState state)
{
	SocketErrorReturn error;

	if (send(socket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.errorText = "�T�[�o�[����̑��M�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;

}

SocketErrorReturn MySocketServer::FirstRead(SOCKET socket, FirstToClientState & readState)
{
	SocketErrorReturn error;
	//�Z���N�g�Ńu���b�L���O�j�~
	fd_set set;
	//������
	FD_ZERO(&set);
	FD_SET(socket, &set);
	//�^�C���A�E�g���Ԑݒ�
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//�ǂݎ��o���邩�`�F�b�N
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//�G���[�̏ꍇ��null
		error.errorText = "�ǂݍ��݂̃Z���N�g�G���[";
		error.isError = true;
		return error;
	}
	//�ǂݍ��߂��Ԃ���Ȃ�������
	if (!FD_ISSET(socket, &set)) {
		error.isError = true;
		return error;
	}
	FirstToClientState state;
	if (recv(socket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.errorText = "�ǂݍ��݃G���[";
		error.isError = true;
		return error;
	}
	readState = state;
	error.isError = false;
	return error;

}

SocketErrorReturn MySocketServer::SendSocket(SOCKET socket, ServerToClientState state)
{
	SocketErrorReturn error;

	if (send(socket, reinterpret_cast<char*>(&state), sizeof(state), 0) == SOCKET_ERROR) {
		error.errorText = "�T�[�o�[����̑��M�Ɏ��s���܂���";
		error.isError = true;
		return error;
	}
	error.isError = false;
	return error;
}

SocketErrorReturn MySocketServer::ReadSocket(SOCKET socket,DotWarsNet & readState)
{
	SocketErrorReturn error;
	//�Z���N�g�Ńu���b�L���O�j�~
	fd_set set;
	//������
	FD_ZERO(&set);
	FD_SET(socket, &set);
	//�^�C���A�E�g���Ԑݒ�
	timeval time;
	time.tv_sec = 0.0f;
	time.tv_usec = 0.0f;
	//�ǂݎ��o���邩�`�F�b�N
	if (select(FD_SETSIZE, &set, 0, 0, &time) == SOCKET_ERROR) {
		//�G���[�̏ꍇ��null
		error.errorText = "�ǂݍ��݂̃Z���N�g�G���[";
		error.isError = true;
		return error;
	}
	//�ǂݍ��߂��Ԃ���Ȃ�������
	if (!FD_ISSET(socket, &set)) {
		error.isError = true;
		return error;
	}
	DotWarsNet state;
	if (recv(socket, reinterpret_cast<char*>(&state), sizeof(DotWarsNet), 0) == SOCKET_ERROR) {
		error.errorText = "�ǂݍ��݃G���[";
		error.isError = true;
		return error;
	}
	readState = state;



	error.isError = false;
	return error;
}

SOCKET_STATE MySocketServer::GetSocketState()
{
	return mSocketState;
}

SOCKET MySocketServer::GetSocket()
{
	return mSocket;
}

sockaddr_in MySocketServer::GetAddr()
{
	return mAddr;
}
