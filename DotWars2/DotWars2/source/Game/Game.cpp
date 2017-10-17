#include "Game.h"
#include <DxLib.h>
//ワールド
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
//シーン
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Title/Title.h"
#include "../Scene/GamePlay/GamePlay.h"
//その他
#include "../Time/Time.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
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
	mSceneManager->sceneStart();
	//シーン追加
	mSceneManager->AddScene(SceneID::TITLE_SCENE, std::make_shared<Title>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SCENE, std::make_shared<GamePlay>(mWorldManager));
	//最初のシーン
	mSceneManager->StartScene(SceneID::TITLE_SCENE);
}

void Game::Update()
{
	//キーボードアップデート
	Keyboard::GetInstance().Update();
	//タイムアップデート
	Time::GetInstance().Update();

	//シーンマネージャーアップデート
	mSceneManager->sceneUpdate();
}

void Game::Draw() const
{
	//シーンマネージャー描写
	mSceneManager->sceneDraw();
}

void Game::End()
{
	mSceneManager->sceneEnd();
	mWorldManager->ManagerClear();
}
