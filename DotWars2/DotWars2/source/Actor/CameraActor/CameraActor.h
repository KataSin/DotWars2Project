#pragma once
#include "../Actor.h"
class ActionManager;

class CameraActor :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	CameraActor(IWorld& world);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CameraActor()override;
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
	virtual void  Collision(Actor& other, const CollisionParameter& parameter)override;

private:
	//�v���C���[���
	ActorPtr mPlayer;
	//�J�����̍��W
	Vector3 mPosition;
	//��]���
	Vector3 mRotate;
	//�����_
	Vector3 mTargetPos;
};