#pragma once

#include "../Action.h"
class PlayerMove :public Action
{
public:
	PlayerMove(IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerMove() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

private:
	Vector3 mPosition;

};