#include "GamePlay.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
GamePlay::GamePlay(WorldManagerPtr manager) :
	mWorldManager(manager)
{
	mIsEnd = false;
}

GamePlay::~GamePlay()
{
}

void GamePlay::Start()
{
	mIsEnd = false;
	mNextScene = SceneID::TITLE_SCENE;
	mMyScene = SceneID::GAME_PLAY_SCENE;
}

void GamePlay::Update()
{
	mWorldManager->Update();

	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		mIsEnd = true;
	}
	
}

void GamePlay::Draw() const
{
	DrawString(0, 0, "ゲームプレイシーン", GetColor(255, 255, 255));
	mWorldManager->Draw();
}

void GamePlay::End()
{
	mWorldManager->WorldAllClear();
}
