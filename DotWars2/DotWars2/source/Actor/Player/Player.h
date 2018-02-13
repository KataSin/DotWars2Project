#pragma once
#include "../Actor.h"
class ActionManager;

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
	/// <summary>
	///	�����蔻��
	/// </summary>
	/// <param name="other">���������I�u�W�F�N�g</param>
	virtual void Collision(Actor& other)override;


private:
	Vector3 mPosition;

	ActionManager* mActionManager;
};