//#include "MySocket.h"
//
//MySocket::MySocket()
//{
//}
//
//MySocket::~MySocket()
//{
//}
//
//void MySocket::CreateSocket(const UDP_OR_TCP & net, const std::string & addres, int port)
//{
//	mSocket = socket(AF_INET, net, 0);
//	if (mSocket == INVALID_SOCKET) {
//		mErrorText = "�\�P�b�g�̍쐬�Ɏ��s���܂���";
//		mIsError = true;
//		return;
//	}
//	//�A�h���X�w��
//	sockaddr_in addr;
//	addr.sin_family = AF_INET;
//	//�|�[�g�ԍ�
//	addr.sin_port = htons(port);
//	//�A�h���X(�S�ẴA�h���X���󂯕t����)
//	addr.sin_addr.S_un.S_addr = INADDR_ANY;
//	//�\�P�b�g�ƃA�h���X�����т���
//	int bindError = bind(mSocket, (struct sockaddr *)&addr, sizeof(addr));
//	if (bindError != 0) {
//		mErrorText = "�o�C�g�ŃG���[���������܂���";
//		mIsError = true;
//		return;
//	}
//}
//
//void MySocket::CreateServerSocket(const UDP_OR_TCP & net)
//{
//}
