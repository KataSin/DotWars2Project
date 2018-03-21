#include "Title.h"

#include "../../Actor/Player/Player.h"
#include "../../Actor/CameraActor/CameraActor.h"
#include "../../Actor/Stage/Stage.h"

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

	ModelAnim::GetInstance().Load("resource/Model/Player/Player01.mv1", MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_IDLE);
	Model::GetInstance().Load("resource/Model/PlayerBullet/PlayerBullet.mv1", MODEL_ID::PLAYER_BULLET_MODEL);
	Model::GetInstance().Load("resource/Model/Stage/Stage.mv1", MODEL_ID::STAGE_MODEL);

	Model::GetInstance().Load("resource/Model/Stage/DefaultPlate.mv1", MODEL_ID::DEFAULT_PLATE_MODEL);
	Model::GetInstance().Load("resource/Model/Player/Player01.mv1", MODEL_ID::PLAYER_MODEL);


	//ゲームプレイワールドに追加
	auto gamePlayWorld = mWorldManager->GetWorld(WORLD_ID::GAME_WORLD);
	gamePlayWorld->Add(ACTOR_ID::PLAYER_ACTOR, std::make_shared<Player>(*gamePlayWorld, Matrix4::Identity*Matrix4::Translate(Vector3::Up*20.0f)));
	gamePlayWorld->Add(ACTOR_ID::STAGE_ACTOR, std::make_shared<Stage>(*gamePlayWorld));

	//アクタースタート
	gamePlayWorld->Start();

}

void Title::Update()
{
	mWorldManager->Update();
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		//mIsEnd = true;
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
