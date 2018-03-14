#include "CameraActor.h"

#include "../../Camera/Camera.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
#include "../../Time/Time.h"

//カメラ関係
//カメラの移動速度
const float CAMERA_SPEED = 100.0f;
//カメラの注視点の高さ
const float CAMERA_HEIGHT = 50.0f;
//プレイヤーとカメラの距離
const float CAMERA_PLAYER_DISTANCE = 80.0f;

CameraActor::CameraActor(IWorld & world) :
	Actor(world)
{
	//死んでいない
	mParameter.isDead = false;
	//回転情報を初期化
	mRotate = Vector3::Zero;


}

CameraActor::~CameraActor()
{
}

void CameraActor::Start()
{
	//プレイヤーを取得する
	mPlayer = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();
	//座標
	Vector3 cameraPos = mPlayer->GetParameter().mat.GetPosition() + mPlayer->GetParameter().mat.GetFront()*3.0f;
	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(0.0f)*
		Matrix4::Translate(cameraPos);

	mTargetPos = mPlayer->GetParameter().mat.GetPosition();

	Camera::GetInstance().SetPosition(mParameter.mat.GetPosition());
	Camera::GetInstance().SetTarget(mTargetPos);
	Camera::GetInstance().SetRange(0.5f, 1000.0f);

}

void CameraActor::Update()
{
	//カメラの動きを管理　テスト
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::LEFT)) {
		mRotate.y += CAMERA_SPEED*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::RIGHT)) {
		mRotate.y -= CAMERA_SPEED*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::UP)) {
		mRotate.x += CAMERA_SPEED*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::DOWN)) {
		mRotate.x -= CAMERA_SPEED*Time::GetInstance().DeltaTime();
	}
	
	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(mRotate.x)*
		Matrix4::RotateY(mRotate.y)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPlayer->GetParameter().mat.GetPosition());
	//カメラの座標を設定
	Vector3 pos = mPlayer->GetParameter().mat.GetPosition() + Vector3::Up*CAMERA_HEIGHT - mParameter.mat.GetFront()*CAMERA_PLAYER_DISTANCE;
	//注視点の設定
	mTargetPos = mPlayer->GetParameter().mat.GetPosition() + Vector3::Up *CAMERA_HEIGHT;

	//カメラの情報を更新
	Camera::GetInstance().SetPosition(pos);
	Camera::GetInstance().SetTarget(mTargetPos);
	Camera::GetInstance().SetCameraVec(Vector3::Up);
	Camera::GetInstance().Update();
}

void CameraActor::Draw() const
{
}

void CameraActor::Collision(Actor& other, const CollisionParameter& parameter)
{
}
