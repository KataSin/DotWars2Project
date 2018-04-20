#pragma once
#include "../../Actor.h"


class DefaultPlate :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	DefaultPlate(IWorld& world, const Matrix4& mat);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~DefaultPlate()override;
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



	void SetHp(int hp) {
		mPlateHp = hp;
	}
private:
	//���X�|�[������
	float mRespawnTime;
	//��ꂽ���ǂ���
	bool mIsBreak;
	//�v���[�g��HP
	int mPlateHp;
};