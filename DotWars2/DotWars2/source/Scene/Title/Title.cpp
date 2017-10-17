#include "Title.h"

#include "../../Actor/Player/Player.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
Title::Title(WorldManagerPtr manager) :
	mWorldManager(manager)
{
	mIsEnd = false;
	mNextScene = SceneID::GAME_PLAY_SCENE;
}

Title::~Title()
{
}

void Title::Start()
{
	mMyScene = SceneID::TITLE_SCENE;
	mIsEnd = false;
	mNextScene = SceneID::GAME_PLAY_SCENE;

	//ゲームプレイワールドに追加
	auto gamePlayWorld = mWorldManager->GetWorld(WORLD_ID::GAME_WORLD);
	gamePlayWorld->Add(ACTOR_ID::PLAYER_ACTOR, std::make_shared<Player>(*gamePlayWorld, Matrix4::Identity));
}

void Title::Update()
{
	mWorldManager->Update();

	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		mIsEnd = true;
	}
}

void Title::Draw() const
{
	DrawString(0, 0, "タイトルシーン", GetColor(255, 255, 255));
	mWorldManager->Draw();

}

void Title::End()
{
	mWorldManager->WorldAllClear();
}
