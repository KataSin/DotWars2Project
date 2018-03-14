#include "Title.h"

#include "../../Actor/Player/Player.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"

#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Camera/Camera.h"
#include "../../Actor/CameraActor/CameraActor.h"

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


	//アクタースタート
	gamePlayWorld->Start();

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
	DrawSphere3D(Vector3::ToVECTOR(Vector3::Zero), 10, 10, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);

	DrawSphere3D(Vector3::ToVECTOR(Vector3(100,0,100)), 10, 10, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);

	mWorldManager->Draw();

}

void Title::End()
{
	mWorldManager->WorldAllClear();
}
