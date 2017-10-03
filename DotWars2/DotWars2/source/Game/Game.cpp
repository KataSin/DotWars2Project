#include "Game.h"
#include <DxLib.h>
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
#include "../Actor/ActorID.h"
#include "../Actor/Player/Player.h"
#include "../Camera/Camera.h"
#include "../Graphic/Model/Model.h"
#include "../Graphic/Sprite/Sprite.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
Game::Game(int windowWight, int windowHeght, bool fullScene)
{
	// 画面モードのセット
	SetGraphMode(windowWight, windowHeght, 16);
	//ウィンドウモードに
	ChangeWindowMode(fullScene ? FALSE : TRUE);
}

Game::~Game()
{
}

void Game::Start()
{
	Model::GetInstance().Load("resource/Model/Player/Player.mv1", MODEL_ID::PLAYER_MODEL);
	Sprite::GetInstance().Load("resource/Sprite/Back.png", SPRITE_ID::TEST_SPRITE);
	//ワールドを生成
	manager = std::make_shared<WorldManager>();
	auto world = std::make_shared<World>(manager);
	world->Add(ACTOR_ID::PLAYER_ACTOR, std::make_shared<Player>(*(world.get()), Matrix4::Identity));
	manager->Add(WORLD_ID::GAME_WORLD, world);

}

void Game::Update()
{
	Keyboard::GetInstance().Update();
	manager->Update();
	//カメラ設定
	Camera::GetInstance().SetTarget(Vector3::Zero);
	Camera::GetInstance().SetPosition(Vector3(40, 40, 40));
	Camera::GetInstance().SetRange(1.0f, 500.0f);

	Camera::GetInstance().Update();
}

void Game::Draw() const
{
	manager->Draw();
}

void Game::End()
{

}
