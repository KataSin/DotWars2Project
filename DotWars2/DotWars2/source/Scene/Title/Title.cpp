#include "Title.h"

#include "../../Actor/Player/Player.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"

#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Camera/Camera.h"


#include "../../Graphic/Model/Model.h"
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

	ModelAnim::GetInstance().Load("resource/Model/Player/Player1.mv1", MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_IDLE);
	
	//ゲームプレイワールドに追加
	auto gamePlayWorld = mWorldManager->GetWorld(WORLD_ID::GAME_WORLD);
	gamePlayWorld->Add(ACTOR_ID::PLAYER_ACTOR, std::make_shared<Player>(*gamePlayWorld, Matrix4::Identity));
}

void Title::Update()
{
	mWorldManager->Update();

	Camera::GetInstance().SetPosition(Vector3(20, 20, 20));
	Camera::GetInstance().SetTarget(Vector3(0, 0, 0));
	Camera::GetInstance().SetRange(0.5f, 1000.0f);
	Camera::GetInstance().SetCameraVec(Vector3::Up);
	Camera::GetInstance().SetView(60.0f);
	Camera::GetInstance().Update();

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
