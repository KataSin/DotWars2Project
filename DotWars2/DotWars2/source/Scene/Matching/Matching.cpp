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
		debug = "サーバーに接続中";
		if (mTCPManager->Connect("127.0.0.1", 1234567))
			mStageNum++;
		break;
	}
	case 1: {
		debug = "情報取得中";

		if (mTCPManager->Read(mFirstState)) {
			std::string text;
			//デバッグ用
			debug = "playerNum:" + std::to_string(mFirstState.playerNum) + "PositionX:" + std::to_string(mFirstState.position.x) + "PositionY:" + std::to_string(mFirstState.position.y);
			//通信終了
			mTCPManager->Close();
			//ワールドマネージャーに渡す
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
	DrawString(0, 0, "マッチングシーン", GetColor(255, 255, 255));
}

void Matching::End()
{
}
