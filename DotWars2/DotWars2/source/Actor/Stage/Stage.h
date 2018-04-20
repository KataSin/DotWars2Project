#pragma once
#include "../Actor.h"


class Stage :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	Stage(IWorld& world);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Stage()override;
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
	//��̃X�e�[�W�̃}�g���N�X
	Matrix4 mStageMat;

public:
	ActorPtr mPlates[16][16];
};