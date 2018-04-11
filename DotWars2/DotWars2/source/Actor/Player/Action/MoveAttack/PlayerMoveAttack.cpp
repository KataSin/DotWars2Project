#include "PlayerMoveAttack.h"
#include "../../ActionManager/ActionManager.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"

#include "../../../../Graphic/ModelAnim/ModelAnim.h"

#include "../../../../Time/Time.h"

#include "../../Player.h"
#include "../../../PlayerBullet/PlayerBullet.h"

//攻撃中の移動スピード
const float ATTACK_MOVE_SPEED = 60.0f;
//攻撃する間隔
const float ATTACK_BULLET_TIME = 0.1f;
PlayerMoveAttack::PlayerMoveAttack(Actor* actor, IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(actor, world, actionManager, parameter)
{
	mAttackTime = 0.0f;
}

PlayerMoveAttack::~PlayerMoveAttack()
{
}

void PlayerMoveAttack::Start()
{
	mPosition = mParameter.mat.GetPosition();
	//カメラアクター取得
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	mPlayerActor = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();

	mVertexPos = mWorld.FindActors(ACTOR_ID::PLAYER_BULLET_POINT_ACTOR).front();



}

void PlayerMoveAttack::Update()
{
	mPosition = mParameter.mat.GetPosition();
	//離されていたら状態チェンジ
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}

	//if (Keyboard::GetInstance().KeyStateDown(KEYCODE::SPACE)) {
	//	mActionManager.ChangeAction(ActionBehavior::JUMP_ATTACK, true);
	//	return;
	//}
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	//カメラのベクトルを取得
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized();
	Vector3 cameraFrontVec = mCameraActor->GetParameter().mat.GetFront().Normalized();
	//カメラのy軸無視
	cameraFrontVec.y = 0.0f;

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition += cameraLeftVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition -= cameraLeftVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition += cameraFrontVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition -= cameraFrontVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}


	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(mCameraActor->GetParameter().mat.GetRotateDegree().y)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);

	//攻撃
	mAttackTime += Time::GetInstance().DeltaTime();
	if (mAttackTime >= ATTACK_BULLET_TIME) {
		PlayerBullet::BulletState state;
		//弾設定
		state.playerID = mParameter.playerID;
		state.vertexPos = mVertexPos->GetParameter().mat.GetPosition();
		state.spawnPos = mParameter.mat.GetPosition();


		state.rand = Vector3::One;

		mWorld.Add(ACTOR_ID::PLAYER_BULLET_ACTOR, std::make_shared<PlayerBullet>(mWorld, state));

		mAttackTime = 0.0f;
	}

}

void PlayerMoveAttack::End()
{
}

void PlayerMoveAttack::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colID == COL_ID::PLAYER_PLATE_COL) {
		//床に当たったら止まる
		dynamic_cast<Player*>(mMyActor)->SetVeloY(0.0f);
	}
}
