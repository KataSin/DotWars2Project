#include "Game.h"
#include <DxLib.h>
//���[���h
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
//�V�[��
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Title/Title.h"
#include "../Scene/GamePlay/GamePlay.h"
//���̑�
#include "../Time/Time.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
Game::Game(int windowWight, int windowHeght, bool fullScene)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(windowWight, windowHeght, 16);
	//�E�B���h�E���[�h��
	ChangeWindowMode(fullScene ? FALSE : TRUE);
	////���[���h�}�l�[�W���[
	//mWorldManager = std::make_shared<WorldManager>();
	//mWorldManager->Add(WORLD_ID::GAME_WORLD, std::make_shared<World>(mWorldManager));

	////�V�[���}�l�[�W���[
	//mSceneManager = std::make_shared<SceneManager>();



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
	serverFlag = true;
	if (serverFlag) {
		mServerManager = new TCPServerSocketManager();
	}
	else
	{
		mClientManager = new TCPClientSocketManager();
	}


	stageNum = 0;
	//mSceneManager->sceneStart();
	////�V�[���ǉ�
	//mSceneManager->AddScene(SceneID::TITLE_SCENE, std::make_shared<Title>(mWorldManager));
	//mSceneManager->AddScene(SceneID::GAME_PLAY_SCENE, std::make_shared<GamePlay>(mWorldManager));
	////�ŏ��̃V�[��
	//mSceneManager->StartScene(SceneID::TITLE_SCENE);
}

void Game::Update()
{
	if (serverFlag) {
		switch (stageNum)
		{
		case 0: {
			debug = "�v���C���[�̎�t������";
			if (mServerManager->Listen(2))
				stageNum++;
			break;
		}
		case 1: {
			debug = "�v���C���[��t��";
			if (mServerManager->Accept())
				stageNum++;
			break;
		}
		case 2: {
			debug = "�v���C���[�ɏ��𑗂蒆";
			if (mServerManager->Send())
				stageNum++;
			break;
		}
		case 3: {
			debug = "TCP�I��";
			mServerManager->Close();
			break;
		}
		}
	}
	else
	{
		switch (stageNum)
		{
		case 0: {
			debug = "�T�[�o�[�ɐڑ���";
			if (mClientManager->Connect("127.0.0.1", 12345))
				stageNum++;
			break;
		}
		case 1: {
			debug = "���擾��";
			FirstToClientState state;
			if (mClientManager->Read(state)) {
				std::string text;
				//�f�o�b�O�p
				debug = "playerNum:" + std::to_string(state.playerNum) + "PositionX:" + std::to_string(state.position.x) + "PositionY:" + std::to_string(state.position.y);
				stageNum++;
			}
			break;
		}
		case 2: {
			mClientManager->Close();
			break;
		}
		}
	}


	//�L�[�{�[�h�A�b�v�f�[�g
	Keyboard::GetInstance().Update();
	//�^�C���A�b�v�f�[�g
	Time::GetInstance().Update();


	////�V�[���}�l�[�W���[�A�b�v�f�[�g
	//mSceneManager->sceneUpdate();
}

void Game::Draw() const
{

	DrawString(0, 0, debug.c_str(), GetColor(255, 255, 255));
	////�V�[���}�l�[�W���[�`��
	//mSceneManager->sceneDraw();
}

void Game::End()
{
	//delete clientManager;
	//mSceneManager->sceneEnd();
	//mWorldManager->ManagerClear();
}
