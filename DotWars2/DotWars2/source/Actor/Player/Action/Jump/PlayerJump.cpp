#include "PlayerJump.h"

#include "../../Player.h"

#include "../../../../Time/Time.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
//ジャンプ中の移動速度
const float JUMP_MOVE_SPEED = 50.0f;
//ジャンプのパワー
const float JUMP_POWER = 2.0f;
PlayerJump::PlayerJump(Actor* actor, IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(actor, world, actionManager, parameter)
{
}

PlayerJump::~PlayerJump()
{
}

void PlayerJump::Start()
{
	//プレイヤーを設定
	mPlayerActor = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();
	//カメラ取得
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	//現在のポジションをセット
	mPosition = mParameter.mat.GetPosition();
	//ジャンプを設定
	mJumpVelo.y = JUMP_POWER;
	//プレイヤーにジャンプを代入
	dynamic_cast<Player*>(mPlayerActor.get())->SetPlusVelo(mJumpVelo);
	//時間設定
	mColTime = 0.0f;
}

void PlayerJump::Update()
{
	mPosition = mParameter.mat.GetPosition();
	mColTime += Time::GetInstance().DeltaTime();

	//カメラのベクトルを取得
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized()*JUMP_MOVE_SPEED;
	Vector3 cameraFrontVec = mCameraActor->GetParameter().mat.GetFront().Normalized()*JUMP_MOVE_SPEED;
	//カメラのy軸無視
	cameraFrontVec.y = 0.0f;

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition += cameraLeftVec*Time::GetInstance().DeltaTime();
		mMoveVec = cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition -= cameraLeftVec*Time::GetInstance().DeltaTime();
		mMoveVec = -cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition += cameraFrontVec*Time::GetInstance().DeltaTime();
		mMoveVec = cameraFrontVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition -= cameraFrontVec*Time::GetInstance().DeltaTime();
		mMoveVec = -cameraFrontVec;
	}
	float playerAngle = Vector3::GetAngle2D(mMoveVec, Vector3::Zero);


	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(-playerAngle + 90.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);



}

void PlayerJump::End()
{
}

void PlayerJump::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colID == COL_ID::PLAYER_PLATE_COL&&
		mColTime >= 0.1f) {
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
	}
}
