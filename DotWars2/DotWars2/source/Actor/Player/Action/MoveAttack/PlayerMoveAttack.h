#pragma once

#include "../Action.h"
class PlayerMoveAttack :public Action
{
public:
	PlayerMoveAttack(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	
	virtual ~PlayerMoveAttack() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter) override;

private:
	//�J�����A�N�^�[
	ActorPtr mCameraActor;
	//���W
	Vector3 mPosition;
	//�v���C���[�A�N�^�[
	ActorPtr mPlayerActor;
	//���_
	ActorPtr mVertexPos;
	//�U���Ԋu�^�C��
	float mAttackTime;
};