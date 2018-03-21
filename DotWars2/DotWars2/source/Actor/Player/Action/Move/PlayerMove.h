#pragma once

#include "../Action.h"
class PlayerMove :public Action
{
public:
	PlayerMove(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerMove() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter) override;

private:
	//�v���C���[�A�N�^�[
	ActorPtr mPlayerActor;

	ActorPtr mCameraActor;
	//���W
	Vector3 mPosition;
	//�����Ă���x�N�g��
	Vector3 mMovemVec;
};