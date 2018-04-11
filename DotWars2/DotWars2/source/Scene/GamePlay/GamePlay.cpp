#include "GamePlay.h"
#include "../../Actor/Player/Player.h"
#include "../../Actor/CameraActor/CameraActor.h"
#include "../../Actor/Stage/Stage.h"

#include "../../Utility/Input/Keyboard/Keyboard.h"

#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Camera/Camera.h"

#include "../../Graphic/Model/Model.h"
GamePlay::GamePlay(WorldManagerPtr manager) :
	mWorldManager(manager)
{
	mIsEnd = false;
	mNextScene = SceneID::GAME_PLAY_SCENE;
}

GamePlay::~GamePlay()
{
}

void GamePlay::Start()
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
	//プレイヤー
	mPlayer = std::make_shared<Player>(*gamePlayWorld, Matrix4::Identity*Matrix4::Translate(Vector3::Up*20.0f));
	//アクター追加
	gamePlayWorld->Add(ACTOR_ID::PLAYER_ACTOR, mPlayer);
	gamePlayWorld->Add(ACTOR_ID::STAGE_ACTOR, std::make_shared<Stage>(*gamePlayWorld));

	//アクタースタート
	gamePlayWorld->Start();


	//UDP通信開始
	mUDPManager = new UDPClientSocketManager();
	mUDPManager->Bind(mWorldManager->GetFirstState());
	mUDPManager->SetServerAddr(mWorldManager->GetClientManager()->GetServerAddr());


}

void GamePlay::Update()
{
	serverCount++;
	//通信部分
	mUDPManager->SetState(dynamic_cast<Player*>(mPlayer.get())->GetNetState());
	if (serverCount % 15 == 0)
		mUDPManager->Send();
	mUDPManager->Read();


	mWorldManager->Update();
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		//mIsEnd = true;
	}
}

void GamePlay::Draw() const
{
	DrawString(0, 0, "ゲームシーン", GetColor(255, 255, 255));
	mWorldManager->Draw();

}

void GamePlay::End()
{
	mWorldManager->WorldAllClear();
}
