#include "GamePlay.h"
#include "../../Actor/Player/Player.h"
#include "../../Actor/EnemyPlayer/EnemyPlayer.h"
#include "../../Actor/CameraActor/CameraActor.h"
#include "../../Actor/Stage/Stage.h"
#include "../../Actor/Stage/DefaultPlate/DefaultPlate.h"

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



	//�Q�[���v���C���[���h�ɒǉ�
	auto gamePlayWorld = mWorldManager->GetWorld(WORLD_ID::GAME_WORLD);
	//�v���C���[
	mPlayer = std::make_shared<Player>(*gamePlayWorld, Matrix4::Identity*Matrix4::Translate(Vector3::Up*20.0f), (PLAYER_ID)mWorldManager->GetFirstState().playerNum);
	//�A�N�^�[�ǉ�
	gamePlayWorld->Add(ACTOR_ID::PLAYER_ACTOR, mPlayer);

	EnemyPlayerState enemyState;
	gamePlayWorld->Add(ACTOR_ID::ENEMY_PLAYER_ACTOR, std::make_shared<EnemyPlayer>(*mGameWorld, enemyState));
	gamePlayWorld->Add(ACTOR_ID::STAGE_ACTOR, std::make_shared<Stage>(*gamePlayWorld));

	//�A�N�^�[�X�^�[�g
	gamePlayWorld->Start();


	//UDP�ʐM�J�n
	mUDPManager = new UDPClientSocketManager();
	mUDPManager->Bind(mWorldManager->GetFirstState());
	mUDPManager->SetServerAddr(mWorldManager->GetClientManager()->GetServerAddr());


}

void GamePlay::Update()
{
	NetWorkUpdate();
	mWorldManager->Update();
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		//mIsEnd = true;
	}
}

void GamePlay::Draw() const
{
	DrawString(0, 0, "�Q�[���V�[��", GetColor(255, 255, 255));

	for (int i = 0; i <= 31; i++) {
		Vector3 pos = NetVec3::ToVector3(mUDPManager->GetServerState().bulletPos[i]);
		Matrix4 mat=
			Matrix4::Scale(1)*
			Matrix4::RotateX(0)*
			Matrix4::RotateY(0)*
			Matrix4::RotateZ(0)*
			Matrix4::Translate(pos);
		Model::GetInstance().Draw(MODEL_ID::PLAYER_BULLET_MODEL, mat);
	}

	mWorldManager->Draw();

}

void GamePlay::End()
{
	mWorldManager->WorldAllClear();
}

void GamePlay::NetWorkUpdate()
{
	serverCount++;
	//�v���C���[�̏��𑗂���ɃZ�b�g
	mUDPManager->SetState(mPlayer->GetParameter().state);
	//2�t���[���Ɉ��T�[�o�[�ɑ���
	if (serverCount % 2 == 0)
		mUDPManager->Send();
	//�T�[�o�[��������擾����
	mUDPManager->Read();

	//�v���[�g�\��
	auto stage = dynamic_cast<Stage*>(mWorldManager->GetWorld(WORLD_ID::GAME_WORLD)->FindActors(ACTOR_ID::STAGE_ACTOR).front().get());

	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j <= 15; j++) {
			//�T�[�o�[���v�Z����HP����
			dynamic_cast<DefaultPlate*>(stage->mPlates[i][j].get())->SetHp(mUDPManager->GetServerState().stagePlates[i][j]);
		}
	}

	//�擾�������𔽉f������(�v���C���[���W��)
	for (const auto& i : mUDPManager->GetServerState().states) {
		//���l�̏�񂩂�-1�̏ꍇ�l�����Ȃ����ߖ���
		if (mPlayer->GetParameter().state.playerNum != i.playerNum&&i.playerNum != -1) {
			EnemyPlayerState state;
			state.id = (PLAYER_ID)i.playerNum;
			state.pos =NetVec3::ToVector3(i.position);
			dynamic_cast<EnemyPlayer*>(mWorldManager->GetWorld(WORLD_ID::GAME_WORLD)->FindActors(ACTOR_ID::ENEMY_PLAYER_ACTOR).front().get())->SetEnemyPlayerState(state);

		}
	}
	//���[���h�ɃT�[�o�[�̏����Z�b�g
	mWorldManager->GetWorld(WORLD_ID::GAME_WORLD)->SetNetState(mUDPManager->GetServerState());

}
