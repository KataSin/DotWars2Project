#include "Matching.h"

Matching::Matching(WorldManagerPtr manager) :
	mWorldManager(manager)
{
}

Matching::~Matching()
{
}

void Matching::Start()
{
}

void Matching::Update()
{
	switch (mStageNum)
	{
	case 0: {
		debug = "�T�[�o�[�ɐڑ���";
		if (mTCPManager->Connect("127.0.0.1", 1234567))
			mStageNum++;
		break;
	}
	case 1: {
		debug = "���擾��";

		if (mTCPManager->Read(mFirstState)) {
			std::string text;
			//�f�o�b�O�p
			debug = "playerNum:" + std::to_string(mFirstState.playerNum) + "PositionX:" + std::to_string(mFirstState.position.x) + "PositionY:" + std::to_string(mFirstState.position.y);
			//�ʐM�I��
			mTCPManager->Close();
			//���[���h�}�l�[�W���[�ɓn��
			mWorldManager->SetFirstState(mFirstState);
			mWorldManager->SetClientManager(mTCPManager);


			mNextScene = SceneID::GAME_PLAY_SCENE;
			mIsEnd = true;
		}
		break;
	}
	}

}

void Matching::Draw() const
{
	DrawString(0, 0, "�}�b�`���O�V�[��", GetColor(255, 255, 255));
}

void Matching::End()
{
}
