#include "PlayerMoveAttack.h"
#include "../../ActionManager/ActionManager.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"

#include "../../../../Graphic/ModelAnim/ModelAnim.h"

#include "../../../../Time/Time.h"


//攻撃中の移動スピード
const float ATTACK_MOVE_SPEED = 20.0f;

PlayerMoveAttack::PlayerMoveAttack(IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(world, actionManager, parameter)
{
	//カメラアクター取得
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
}

PlayerMoveAttack::~PlayerMoveAttack()
{
}

void PlayerMoveAttack::Start()
{
	mPosition = mParameter.mat.GetPosition();
}

void PlayerMoveAttack::Update()
{
	//離されていたら状態チェンジ
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	//カメラのベクトルを取得
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized();
	Vector3 cameraFrontVec= mCameraActor->GetParameter().mat.GetFront().Normalized();
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
		Matrix4::RotateY(mCameraActor->GetParameter().mat.GetRotateDegree().y+180.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);
}

void PlayerMoveAttack::End()
{
}

void PlayerMoveAttack::Collision(Actor & other, const CollisionParameter & parameter)
{
}
