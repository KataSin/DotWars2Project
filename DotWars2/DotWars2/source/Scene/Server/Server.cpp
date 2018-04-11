#include "Server.h"

#include "../../Actor/Player/Player.h"
#include "../../Actor/CameraActor/CameraActor.h"
#include "../../Actor/Stage/Stage.h"

#include "../../Utility/Input/Keyboard/Keyboard.h"

#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Camera/Camera.h"

#include "../../Graphic/Model/Model.h"
Server::Server(WorldManagerPtr manager) :
	mWorldManager(manager)
{
	mIsEnd = false;
	mNextScene = SceneID::GAME_PLAY_SCENE;
}

Server::~Server()
{
}

void Server::Start()
{
	mMyScene = SceneID::TITLE_SCENE;
	mIsEnd = false;

	//ステージ番号設定
	mStageNum = 0;

	//マネージャー生成
	mTCPManager = new TCPServerSocketManager();

	serverCount = 0;
}

void Server::Update()
{
	serverCount++;
	switch (mStageNum)
	{
	case 0: {
		debug = "プレイヤーの受付準備中";
		if (mTCPManager->Listen(2))
			mStageNum++;
		break;
	}
	case 1: {
		debug = "プレイヤー受付中";
		if (mTCPManager->Accept())
			mStageNum++;
		break;
	}
	case 2: {
		debug = "プレイヤーに情報を送り中";
		if (mTCPManager->Send())
			mStageNum++;
		break;
	}
	case 3: {
		debug = "TCP終了";
		mTCPManager->Close();
		//UDP通信開始
		mUDPManager = new UDPServerSocketManager();
		//TCPで取ったクライアントの情報をUDPに渡す
		for (const auto& i : mTCPManager->GetConnectSockets()) {
			mUDPManager->AddClientAdd(i);
		}
		//状態を初期化
		mUDPManager->SetState(mTCPManager->GetFirstState());
		mStageNum++;
		break;
	}
	case 4: {
		mUDPManager->Read();
		ServerToClientState s = mUDPManager->GetState();
		debug = "Player1 PosX:" + std::to_string(s.states[0].position.x) + "PosY" + std::to_string(s.states[0].position.y) +
			"Player2 PosX:" + std::to_string(s.states[1].position.x) + "PosY" + std::to_string(s.states[1].position.y);
		if (serverCount % 15 == 0)
			mUDPManager->Send();
		break;
	}
	}
}

void Server::Draw() const
{
	DrawString(0, 0, "サーバーシーン", GetColor(255, 255, 255));

	DrawString(0, 64, debug.c_str(), GetColor(255, 255, 255), GetColor(255, 255, 255));
}

void Server::End()
{
	delete mUDPManager;
	delete mTCPManager;
}
