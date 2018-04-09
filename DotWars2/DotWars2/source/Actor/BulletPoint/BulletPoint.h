#pragma once
#include "../Actor.h"


class BulletPoint :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	BulletPoint(IWorld& world);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BulletPoint()override;
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
	//�J�����A�N�^�[
	ActorPtr mCameraActor;
	//���W
	Vector3 mPosition;
	//�����̐���
	float mDisNum;
	//
};