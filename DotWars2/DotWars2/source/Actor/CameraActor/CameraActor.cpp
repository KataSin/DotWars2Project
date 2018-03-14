#include "CameraActor.h"

#include "../../Camera/Camera.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
#include "../../Time/Time.h"

//�J�����֌W
//�J�����̈ړ����x
const float CAMERA_SPEED = 100.0f;
//�J�����̒����_�̍���
const float CAMERA_HEIGHT = 50.0f;
//�v���C���[�ƃJ�����̋���
const float CAMERA_PLAYER_DISTANCE = 80.0f;

CameraActor::CameraActor(IWorld & world) :
	Actor(world)
{
	//����ł��Ȃ�
	mParameter.isDead = false;
	//��]����������
	mRotate = Vector3::Zero;


}

CameraActor::~CameraActor()
{
}

void CameraActor::Start()
{
	//�v���C���[���擾����
	mPlayer = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();
	//���W
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
	//�J�����̓������Ǘ��@�e�X�g
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
	//�J�����̍��W��ݒ�
	Vector3 pos = mPlayer->GetParameter().mat.GetPosition() + Vector3::Up*CAMERA_HEIGHT - mParameter.mat.GetFront()*CAMERA_PLAYER_DISTANCE;
	//�����_�̐ݒ�
	mTargetPos = mPlayer->GetParameter().mat.GetPosition() + Vector3::Up *CAMERA_HEIGHT;

	//�J�����̏����X�V
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
