#include "BulletPoint.h"

#include "../../Camera/Camera.h"

#include "../../Graphic/Model/Model.h"

BulletPoint::BulletPoint(IWorld & world):
	Actor(world)
{
	mParameter.isDead = false;

	mParameter.mat = Matrix4::Translate(Vector3::Zero);
	//�U���̋���
	mDisNum = 100.0f;

	//�e�X�g
	Model::GetInstance().Load("resource/Model/test.mv1", MODEL_ID::TEST_MODEL);

}

BulletPoint::~BulletPoint()
{
}

void BulletPoint::Start()
{
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	mPosition = Vector3::Zero;
}

void BulletPoint::Update()
{
	//�����_���擾
	Vector3 targetPos = Camera::GetInstance().GetTarget();
	//�����_�ƃJ�����̃x�N�g��
	Vector3 targetCameraVec = targetPos - Camera::GetInstance().GetPosition();
	
	mPosition = targetPos + targetCameraVec.Normalized()*mDisNum;

	mParameter.mat = 
		Matrix4::Scale(10.0f)*
		Matrix4::Translate(mPosition);

}


void BulletPoint::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::TEST_MODEL, mParameter.mat);
}

void BulletPoint::Collision(Actor & other, const CollisionParameter & parameter)
{
}
