#pragma once
#include "../Actor.h"

class PlayerBullet :public Actor {

public: 
	struct BulletState {
		PLAYER_ID playerID;  //�N���ł�����
		Vector3 spawnPos;	//�o��������W
		Vector3 vertexPos;	//���_�̍��W
		Vector3 rand;		//�ǂꂾ�����_���炸��邩
	};


public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="state">�e�̏��</param>
	PlayerBullet(IWorld& world, const BulletState& state);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~PlayerBullet()override;
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