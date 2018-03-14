#include "PlayerMove.h"

#include "../../IActionManager/IActionManager.h"
#include "../../../../Graphic/ModelAnim/ModelAnim.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Time/Time.h"

const float MOVE_SPEED = 50.0f;

PlayerMove::PlayerMove(IWorld & world, IActionManager& actionManager, Parameter& parameter) :
	Action(world, actionManager, parameter)
{
}

PlayerMove::~PlayerMove()
{
}

void PlayerMove::Start()
{

	//カメラアクター取得
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	mPosition = mParameter.mat.GetPosition();

	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
}

void PlayerMove::Update()
{
	DrawString(0, 32, "歩いてます", GetColor(255, 255, 255));

	//Fキーを押されていたら
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::ATTACK_MOVE, true);
		return;

	}
	//何も入力してなかったら止まる
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::A) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::S) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::D) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::W))
	{
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}
	//カメラのベクトルを取得
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized()*MOVE_SPEED;
	Vector3 cameraFrontVec = mCameraActor->GetParameter().mat.GetFront().Normalized()*MOVE_SPEED;
	//カメラのy軸無視
	cameraFrontVec.y = 0.0f;

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition += cameraLeftVec*Time::GetInstance().DeltaTime();
		mMovemVec = cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition -= cameraLeftVec*Time::GetInstance().DeltaTime();
		mMovemVec = -cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition += cameraFrontVec*Time::GetInstance().DeltaTime();
		mMovemVec = cameraFrontVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition -= cameraFrontVec*Time::GetInstance().DeltaTime();
		mMovemVec = -cameraFrontVec;
	}
	float playerAngle = Vector3::GetAngle2D(mMovemVec,Vector3::Zero);

	DrawString(0, 64, std::to_string(mParameter.mat.GetRotateDegree().y).c_str(), GetColor(255, 255, 255));

	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(-playerAngle+90.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);

}

void PlayerMove::End()
{
}

void PlayerMove::Collision(Actor & other, const CollisionParameter & parameter)
{
}
