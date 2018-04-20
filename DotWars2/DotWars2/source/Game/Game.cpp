#include "Game.h"
#include <DxLib.h>
//���[���h
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
//�V�[��
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Title/Title.h"
#include "../Scene/GamePlay/GamePlay.h"
#include "../Scene/Matching/Matching.h"
#include "../Scene/Server/Server.h"
#include "../Scene/GamePlayServer/GamePlayServer.h"
//���̑�
#include "../Time/Time.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
#include "../Graphic/ModelAnim/ModelAnim.h"
Game::Game(int windowWight, int windowHeght, bool fullScene)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(windowWight, windowHeght, 16);
	//�E�B���h�E���[�h��
	ChangeWindowMode(fullScene ? FALSE : TRUE);
	//���[���h�}�l�[�W���[
	mWorldManager = std::make_shared<WorldManager>();
	mWorldManager->Add(WORLD_ID::GAME_WORLD, std::make_shared<World>(mWorldManager));

	//�V�[���}�l�[�W���[
	mSceneManager = std::make_shared<SceneManager>();



}

Game::~Game()
{
}

void Game::Start()
{
	WSADATA wsaData;
	//winsock������
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	//�T�[�o�[�ł�
	mSceneManager->sceneStart();
	//�V�[���ǉ�
	mSceneManager->AddScene(SceneID::TITLE_SCENE, std::make_shared<Title>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SCENE, std::make_shared<GamePlay>(mWorldManager));
	mSceneManager->AddScene(SceneID::MATCHING_SCENE, std::make_shared<Matching>(mWorldManager));
	mSceneManager->AddScene(SceneID::SERVER_SCENE, std::make_shared<Server>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SERVER_SCENE, std::make_shared<GamePlayServer>(mWorldManager));

	
	//�ŏ��̃V�[��
	mSceneManager->StartScene(SceneID::TITLE_SCENE);
}

void Game::Update()
{
	//serverCount++;
	//if (serverFlag) {
	//	switch (stageNum)
	//	{
	//	case 0: {
	//		debug = "�v���C���[�̎�t������";
	//		if (mServerManager->Listen(2))
	//			stageNum++;
	//		break;
	//	}
	//	case 1: {
	//		debug = "�v���C���[��t��";
	//		if (mServerManager->Accept())
	//			stageNum++;
	//		break;
	//	}
	//	case 2: {
	//		debug = "�v���C���[�ɏ��𑗂蒆";
	//		if (mServerManager->Send())
	//			stageNum++;
	//		break;
	//	}
	//	case 3: {
	//		debug = "TCP�I��";
	//		mServerManager->Close();
	//		//UDP�ʐM�J�n
	//		mUdpServerManager = new UDPServerSocketManager();
	//		//TCP�Ŏ�����N���C�A���g�̏���UDP�ɓn��
	//		for (const auto& i : mServerManager->GetConnectSockets()) {
	//			mUdpServerManager->AddClientAdd(i);
	//		}
	//		//��Ԃ�������
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
	//		debug = "�T�[�o�[�ɐڑ���";
	//		if (mClientManager->Connect("192.168.100.144", 1234567))
	//			stageNum++;
	//		break;
	//	}
	//	case 1: {
	//		debug = "���擾��";

	//		if (mClientManager->Read(mFirstState)) {
	//			std::string text;
	//			//�f�o�b�O�p
	//			debug = "playerNum:" + std::to_string(mFirstState.playerNum) + "PositionX:" + std::to_string(mFirstState.position.x) + "PositionY:" + std::to_string(mFirstState.position.y);
	//			//�󂯎�����������炤
	//			mClientState.playerNum = mFirstState.playerNum;
	//			mClientState.position = mFirstState.position;
	//			stageNum++;
	//		}
	//		break;
	//	}
	//	case 2: {
	//		mClientManager->Close();
	//		//UDP�J�n
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


	
	//�L�[�{�[�h�A�b�v�f�[�g
	Keyboard::GetInstance().Update();
	//�^�C���A�b�v�f�[�g
	Time::GetInstance().Update();
	//���f���A�j���[�V�����A�b�v�f�[�g
	ModelAnim::GetInstance().Update();

	//�V�[���}�l�[�W���[�A�b�v�f�[�g
	mSceneManager->sceneUpdate();
}

void Game::Draw() const
{

	//DrawString(0, 0, debug.c_str(), GetColor(255, 255, 255));
	//�V�[���}�l�[�W���[�`��
	mSceneManager->sceneDraw();
}

void Game::End()
{
	mSceneManager->sceneEnd();
	mWorldManager->ManagerClear();
}
