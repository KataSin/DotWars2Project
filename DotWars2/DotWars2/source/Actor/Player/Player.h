#pragma once
#include "../Actor.h"
#include "ActionManager\ActionManager.h"

class Player :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	Player(IWorld& world, const Matrix4& mat, PLAYER_ID id);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Player()override;
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
	/// <summary>
	/// �v���C���[�̏�Ԃ��擾����
	/// </summary>
	ActionBehavior GetState();
	/// <summary>
	/// �v���C���[�ɑ��x�𑫂�
	/// </summary>
	/// <param name="velocity"></param>
	void SetPlusVelo(const Vector3 velocity);
	/// <summary>
	/// �v���C���[��Y�����x��ݒ肷��
	/// </summary>
	/// <param name="velocity"></param>
	void SetVeloY(float velocityY);
	/// <summary>
	/// �T�[�o�[�ɑ�������擾
	/// </summary>
	/// <returns>���</returns>
	DotWarsNet GetNetState();
private:
	Vector3 mPosition;

	//���x
	Vector3 mVelo;
	//�A�N�V�����}�l�[�W���[
	ActionManager* mPlayerActionManager;
	//�T�[�o�[�ɑ�����
	DotWarsNet mState;

};