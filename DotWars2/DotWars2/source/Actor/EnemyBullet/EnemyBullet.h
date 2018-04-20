#pragma once
#include "../Actor.h"

#include "../PlayerBullet/PlayerBullet.h"

class EnemyBullet :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="state">�e�̏��</param>
	EnemyBullet(IWorld& world, const PlayerBullet::BulletState& state);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~EnemyBullet()override;
	/// <summary>
	/// �X�^�[�g
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const override;
	/// <summary>
	///	�����蔻��
	/// </summary>
	/// <param name="other">���������I�u�W�F�N�g</param>
	virtual void Collision(Actor& other, const CollisionParameter& parameter)override;

	void SetPosition(const Vector3& pos) {
		mPosition = pos;
	}

private:
	//�x�N�g��
	Vector3 mVec;
	//�x�N�g��Y
	float mVecY;
	//�ʒu
	Vector3 mPosition;
	//�o������ʒu
	Vector3 mStartPos;
	//���_�̈ʒu
	Vector3 mVertexPoint;
	//����
	Vector3 mDistance;
	//����
	float mTime;
	//�����_�����W
	Vector3 mRandVec;
	//�����_����]
	Vector3 mRandRotate;
	//��]
	Vector3 mRotate;
	//�J���[
	Vector4 mColor;

	float mCoppyPosY;
};