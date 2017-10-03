#pragma once
#include "../Actor.h"


class Player :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	Player(IWorld& world, const Matrix4& mat);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Player()override;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const override;
};