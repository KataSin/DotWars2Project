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

	//�X�e�[�W�ԍ��ݒ�
	mStageNum = 0;

	//�}�l�[�W���[����
	mTCPManager = new TCPServerSocketManager();

	serverCount = 0;
}

void Server::Update()
{
	serverCount++;
	switch (mStageNum)
	{
	case 0: {
		debug = "�v���C���[�̎�t������";
		if (mTCPManager->Listen(2))
			mStageNum++;
		break;
	}
	case 1: {
		debug = "�v���C���[��t��";
		if (mTCPManager->Accept())
			mStageNum++;
		break;
	}
	case 2: {
		debug = "�v���C���[�ɏ��𑗂蒆";
		if (mTCPManager->Send())
			mStageNum++;
		break;
	}
	case 3: {
		debug = "TCP�I��";
		mTCPManager->Close();
		mWorldManager->SetServerManager(mTCPManager);
		mNextScene = SceneID::GAME_PLAY_SERVER_SCENE;
		mIsEnd = true;
		break;
	}
	}
}

void Server::Draw() const
{
	DrawString(0, 0, "�T�[�o�[�V�[��", GetColor(255, 255, 255));

	DrawString(0, 64, debug.c_str(), GetColor(255, 255, 255), GetColor(255, 255, 255));
}

void Server::End()
{
}
