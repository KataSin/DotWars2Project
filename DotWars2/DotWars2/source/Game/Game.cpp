#include "Game.h"
#include <DxLib.h>
//ワールド
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
//シーン
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Title/Title.h"
#include "../Scene/GamePlay/GamePlay.h"
#include "../Scene/Matching/Matching.h"
#include "../Scene/Server/Server.h"
#include "../Scene/GamePlayServer/GamePlayServer.h"
//その他
#include "../Time/Time.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
#include "../Graphic/ModelAnim/ModelAnim.h"
Game::Game(int windowWight, int windowHeght, bool fullScene)
{
	// 画面モードのセット
	SetGraphMode(windowWight, windowHeght, 16);
	//ウィンドウモードに
	ChangeWindowMode(fullScene ? FALSE : TRUE);
	//ワールドマネージャー
	mWorldManager = std::make_shared<WorldManager>();
	mWorldManager->Add(WORLD_ID::GAME_WORLD, std::make_shared<World>(mWorldManager));

	//シーンマネージャー
	mSceneManager = std::make_shared<SceneManager>();



}

Game::~Game()
{
}

void Game::Start()
{
	WSADATA wsaData;
	//winsock初期化
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	//サーバーです
	mSceneManager->sceneStart();
	//シーン追加
	mSceneManager->AddScene(SceneID::TITLE_SCENE, std::make_shared<Title>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SCENE, std::make_shared<GamePlay>(mWorldManager));
	mSceneManager->AddScene(SceneID::MATCHING_SCENE, std::make_shared<Matching>(mWorldManager));
	mSceneManager->AddScene(SceneID::SERVER_SCENE, std::make_shared<Server>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SERVER_SCENE, std::make_shared<GamePlayServer>(mWorldManager));

	
	//最初のシーン
	mSceneManager->StartScene(SceneID::TITLE_SCENE);
}

void Game::Update()
{
	//serverCount++;
	//if (serverFlag) {
	//	switch (stageNum)
	//	{
	//	case 0: {
	//		debug = "プレイヤーの受付準備中";
	//		if (mServerManager->Listen(2))
	//			stageNum++;
	//		break;
	//	}
	//	case 1: {
	//		debug = "プレイヤー受付中";
	//		if (mServerManager->Accept())
	//			stageNum++;
	//		break;
	//	}
	//	case 2: {
	//		debug = "プレイヤーに情報を送り中";
	//		if (mServerManager->Send())
	//			stageNum++;
	//		break;
	//	}
	//	case 3: {
	//		debug = "TCP終了";
	//		mServerManager->Close();
	//		//UDP通信開始
	//		mUdpServerManager = new UDPServerSocketManager();
	//		//TCPで取ったクライアントの情報をUDPに渡す
	//		for (const auto& i : mServerManager->GetConnectSockets()) {
	//			mUdpServerManager->AddClientAdd(i);
	//		}
	//		//状態を初期化
	//		mUdpServerManager->SetState(mServerManager->GetFirstState());
	//		stageNum++;
	//		break;
	//	}
	//	case 4: {
	//		mUdpServerManager->Read();
	//		ServerToClientState s = mUdpServerManager->GetState();
	//		debug = "Player1 PosX:" + std::to_string(s.states[0].position.x) + "PosY" + std::to_string(s.states[0].position.y)+
	//			"Player2 PosX:" + std::to_string(s.states[1].position.x) + "PosY" + std::to_string(s.states[1].position.y);
	//		if(serverCount%15==0)
	//		mUdpServerManager->Send();
	//		break;
	//	}
	//	}
	//}
	//else
	//{
	//	switch (stageNum)
	//	{
	//	case 0: {
	//		debug = "サーバーに接続中";
	//		if (mClientManager->Connect("192.168.100.144", 1234567))
	//			stageNum++;
	//		break;
	//	}
	//	case 1: {
	//		debug = "情報取得中";

	//		if (mClientManager->Read(mFirstState)) {
	//			std::string text;
	//			//デバッグ用
	//			debug = "playerNum:" + std::to_string(mFirstState.playerNum) + "PositionX:" + std::to_string(mFirstState.position.x) + "PositionY:" + std::to_string(mFirstState.position.y);
	//			//受け取った情報をもらう
	//			mClientState.playerNum = mFirstState.playerNum;
	//			mClientState.position = mFirstState.position;
	//			stageNum++;
	//		}
	//		break;
	//	}
	//	case 2: {
	//		mClientManager->Close();
	//		//UDP開始
	//		mUdpClientManager = new UDPClientSocketManager();
	//		mUdpClientManager->Bind(mFirstState);
	//		mUdpClientManager->SetServerAddr(mClientManager->GetServerAddr());
	//		stageNum++;
	//		break;
	//	}
	//	case 3:
	//	{
	//		
	//		if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
	//			mClientState.position.x -= 1.0f*Time::GetInstance().DeltaTime();
	//		}
	//		if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
	//			mClientState.position.y -= 1.0f*Time::GetInstance().DeltaTime();
	//		}
	//		if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
	//			mClientState.position.x += 1.0f*Time::GetInstance().DeltaTime();
	//		}
	//		if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
	//			mClientState.position.y += 1.0f*Time::GetInstance().DeltaTime();
	//		}
	//		
	//		debug = "PosX:" + std::to_string(mClientState.position.x) + "PosY:" + std::to_string(mClientState.position.y);
	//		
	//		mUdpClientManager->SetState(mClientState);
	//		if (serverCount % 15 == 0)
	//		mUdpClientManager->Send();
	//		mUdpClientManager->Read();

	//		break;
	//	}
	//	}
	//}


	
	//キーボードアップデート
	Keyboard::GetInstance().Update();
	//タイムアップデート
	Time::GetInstance().Update();
	//モデルアニメーションアップデート
	ModelAnim::GetInstance().Update();

	//シーンマネージャーアップデート
	mSceneManager->sceneUpdate();
}

void Game::Draw() const
{

	//DrawString(0, 0, debug.c_str(), GetColor(255, 255, 255));
	//シーンマネージャー描写
	mSceneManager->sceneDraw();
}

void Game::End()
{
	mSceneManager->sceneEnd();
	mWorldManager->ManagerClear();
}
