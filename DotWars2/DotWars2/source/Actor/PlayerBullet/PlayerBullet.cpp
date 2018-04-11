#include "PlayerBullet.h"

#include "../../Graphic/Model/Model.h"

#include "../../Random/Random.h"
#include "../../Time/Time.h"

const float BULLET_SPEED = 0.01f;

PlayerBullet::PlayerBullet(IWorld& world, const BulletState& state) :
	Actor(world)
{
	//�p�����[�^�[������
	mParameter.playerID = state.playerID;


	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(0.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(state.spawnPos);


	//�����_���Ŋg�U����
	mRandVec = Vector3(
		Random::GetInstance().Range(-state.rand.x, state.rand.x),
		Random::GetInstance().Range(-state.rand.y + 0.5f, state.rand.y - 0.5f),
		Random::GetInstance().Range(-state.rand.z, state.rand.z));



	mRandRotate = Vector3(
		Random::GetInstance().Range(-100, 100),
		Random::GetInstance().Range(-100, 100),
		Random::GetInstance().Range(-100, 100));

	//bulletstate����
	mPosition = state.spawnPos;
	mVertexPoint = state.vertexPos;
	mStartPos = state.spawnPos;
	//���������߂�v�Z
	mDistance = (mVertexPoint + mRandVec - mStartPos);
	mCoppyPosY = mStartPos.y;


	mTime = 0.0f;
	mVec = (state.vertexPos - state.spawnPos).Normalized()*1000.0f;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Start()
{
}

void PlayerBullet::Update()
{
	//�^�C�����Z
	mTime += Time::GetInstance().DeltaTime();

	mVec.y -=2000.0f*Time::GetInstance().DeltaTime();
	mPosition += mVec*Time::GetInstance().DeltaTime();
	////���_���o���ʒu��������������(���_�Əo���ʒu�̈����Z���}�C�i�X�ɂȂ蕽�����ŋ��߂��Ȃ��Ȃ邽��)
	//if (mCoppyPosY <= mVertexPoint.y)
	//{
	//	//�ō����x�����Ƃɏ����x�����߂�(���������グ)
	//	float InitializeVec = Math::Sqrt((mVertexPoint.y - mCoppyPosY) * 2.0f * 9.8f);
	//	//�����x�����ɒ��_�ɒB���鎞�Ԃ����߂�
	//	float vertexTime = InitializeVec / 9.8f;
	//	//�����ƒ��_�ɒB���鎞�Ԃ����������̂�1�t���[���ɓ���x��z���̈ړ��ʂ����߂�
	//	mVec = Vector3(
	//		mDistance.x / vertexTime  *BULLET_SPEED* Time::GetInstance().DeltaTime(),
	//		0.0f,
	//		mDistance.z / vertexTime *BULLET_SPEED* Time::GetInstance().DeltaTime());
	//	//y���̈ʒu�����߂�
	//	mPosition.y = InitializeVec*mTime*BULLET_SPEED - 9.8f / 2.0f * pow(mTime*BULLET_SPEED, 2) + mCoppyPosY;
	//	//�ړ��ʂ𑫂�
	//	mPosition += mVec;
	//}
	////�Ⴉ������(�����x�����߂��Ȃ�����)
	//else
	//{
	//	//�x��(�o���Ȃ�)
	//	mVecY -= 10.0f*Time::GetInstance().DeltaTime();
	//	Vector3 mVec = mDistance + Vector3(0.0f, mVecY, 0.0f);
	//	mPosition += mVec*BULLET_SPEED*1.5f*Time::GetInstance().DeltaTime();
	//}
	mRotate += mRandRotate*Time::GetInstance().DeltaTime();

	//�e�X�g
	if (mTime >= 2.0f) {
		mParameter.isDead = true;
	}

	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(mRotate.x)*
		Matrix4::RotateY(mRotate.y)*
		Matrix4::RotateZ(mRotate.z)*
		Matrix4::Translate(mPosition);
}

void PlayerBullet::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::PLAYER_BULLET_MODEL, mParameter.mat);
}

void PlayerBullet::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colID == COL_ID::PLATE_BULLET_COL){
		mParameter.isDead = true;
	}
}
