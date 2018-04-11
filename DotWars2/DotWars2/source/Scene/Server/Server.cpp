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
		//UDP�ʐM�J�n
		mUDPManager = new UDPServerSocketManager();
		//TCP�Ŏ�����N���C�A���g�̏���UDP�ɓn��
		for (const auto& i : mTCPManager->GetConnectSockets()) {
			mUDPManager->AddClientAdd(i);
		}
		//��Ԃ�������
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
	DrawString(0, 0, "�T�[�o�[�V�[��", GetColor(255, 255, 255));

	DrawString(0, 64, debug.c_str(), GetColor(255, 255, 255), GetColor(255, 255, 255));
}

void Server::End()
{
	delete mUDPManager;
	delete mTCPManager;
}
