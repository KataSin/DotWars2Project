#pragma once

#include "../Action.h"
class PlayerIdle :public Action
{
public:
	PlayerIdle(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerIdle() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter);

private:
	//���W
	Vector3 mPosition;
	//�v���C���[�A�N�^�[
	ActorPtr mPlayerActor;
};