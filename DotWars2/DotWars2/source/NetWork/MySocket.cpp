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
//		mErrorText = "ソケットの作成に失敗しました";
//		mIsError = true;
//		return;
//	}
//	//アドレス指定
//	sockaddr_in addr;
//	addr.sin_family = AF_INET;
//	//ポート番号
//	addr.sin_port = htons(port);
//	//アドレス(全てのアドレスを受け付ける)
//	addr.sin_addr.S_un.S_addr = INADDR_ANY;
//	//ソケットとアドレスを結びつける
//	int bindError = bind(mSocket, (struct sockaddr *)&addr, sizeof(addr));
//	if (bindError != 0) {
//		mErrorText = "バイトでエラーが発生しました";
//		mIsError = true;
//		return;
//	}
//}
//
//void MySocket::CreateServerSocket(const UDP_OR_TCP & net)
//{
//}
