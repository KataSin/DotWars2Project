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
	//�T�[�o�[�ł�
	serverFlag = false;
	if (serverFlag) {
		serverManager = new MySocketServerManager();
		serverManager->Initialize(SOCKET_STATE::TCP_SERVER_SOCKET);
		serverManager->OpenServer(12345, "127.0.0.1");
	}
	else
	{
		clientManager = new MySocketClientManager();
		clientManager->Initialize(SOCKET_STATE::TCP_CLIENT_SOCKET);
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
	//�T�[�o�[����
	if (serverFlag) {
		switch (stageNum)
		{
		case 0:
		{
			debug = "�v���C���[��҂��Ă��܂�";
			if (serverManager->AcceptServer(2))
				stageNum++;
			break;
		}
		case 1:
		{
			debug = "�T�[�o�[����ʐM��";
			serverManager->Send();
			serverManager->Read();
			
			for (int i = 0; i < 4; i++) {
				mServerState.push_back(clientManager->GetState().states[i]);
			}
			break;
		}
		}
	}
	//�N���C�A���g����
	else
	{
		switch (stageNum)
		{
		case 0:
		{
			debug = "�T�[�o�[�ڑ��ɐڑ����Ă��܂�";
			if (clientManager->ConnectClient("127.0.0.1", 12345))
				stageNum++;
			break;
		}
		case 1:
		{
			//���蓖�Ă�ꂽ���̂����炤
			debug = "�ŏ��̏���������Ă��܂�";
			if (clientManager->FirstRead()) {
				mClientState.playerNum = clientManager->GetFirstState().playerNum;
				mClientState.position = clientManager->GetFirstState().position;
				stageNum++;
			}
			break;
		}
		case 2:
		{
			clientManager->SetState(mClientState);
			if (!clientManager->Read())return;
			clientManager->Send();
			stageNum++;
			break;
		}
		case 3:
		{
			debug = "�N���C�A���g����ʐM��";
			if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
				mClientState.position.x -= 40.0f*Time::GetInstance().DeltaTime();
			}
			if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
				mClientState.position.x += 40.0f*Time::GetInstance().DeltaTime();
			}
			if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
				mClientState.position.y += 40.0f*Time::GetInstance().DeltaTime();
			}
			if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
				mClientState.position.y -= 40.0f*Time::GetInstance().DeltaTime();

			}
			clientManager->SetState(mClientState);



			clientManager->Read();
			clientManager->Send();
			
			mServerState.clear();
			for (int i = 0; i < 2; i++) {
				mServerState.push_back(clientManager->GetState().states[i]);
			}
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
	
	std::string pos = "�v���C���[" + std::to_string(mClientState.playerNum) + "x:" + std::to_string(mClientState.position.x)+"y:"+std::to_string(mClientState.position.y);
	DrawString(200, 0, pos.c_str(), GetColor(128, 128, 128));

	DrawCircle(mClientState.position.x, mClientState.position.y, 5, GetColor(255, 255, 255));


	////�V�[���}�l�[�W���[�`��
	//mSceneManager->sceneDraw();
}

void Game::End()
{
	//delete clientManager;
	//mSceneManager->sceneEnd();
	//mWorldManager->ManagerClear();
}
