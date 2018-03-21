#pragma once

#include "../Action.h"



class PlayerJump :public Action
{
public:
	PlayerJump(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerJump() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter);

private:
	//�v���C���[
	ActorPtr mPlayerActor;
	Vector3 mPosition;
	Vector3 mMoveVec;
	//�W�����v�̑��x
	Vector3 mJumpVelo;
	//�J����
	ActorPtr mCameraActor;

	//���Ƃ̓����蔻��p�̎���
	float mColTime;
	
};